// dhcp_sim.cpp
// Compile: g++ -std=c++17 dhcp_sim.cpp -o dhcp_sim
// Usage: ./dhcp_sim
#include <bits/stdc++.h>
using namespace std;

// helper IP conversions
uint32_t ip_to_int(const string &ip)
{
    uint32_t a, b, c, d;
    sscanf(ip.c_str(), "%u.%u.%u.%u", &a, &b, &c, &d);
    return (a << 24) | (b << 16) | (c << 8) | d;
}
string int_to_ip(uint32_t x)
{
    return to_string((x >> 24) & 255) + "." + to_string((x >> 16) & 255) + "." + to_string((x >> 8) & 255) + "." + to_string(x & 255);
}

int main()
{
    cout << "DHCP Simulator\n";
    string start_ip, end_ip;
    cout << "Enter pool start IP (e.g. 192.168.1.100): ";
    cin >> start_ip;
    cout << "Enter pool end IP   (e.g. 192.168.1.200): ";
    cin >> end_ip;
    uint32_t a = ip_to_int(start_ip), b = ip_to_int(end_ip);
    if (a > b)
        swap(a, b);

    // Data structures
    unordered_map<string, uint32_t> mac_to_ip; // MAC -> IP
    unordered_map<uint32_t, string> ip_to_mac; // IP -> MAC
    set<uint32_t> free_ips;
    for (uint32_t ip = a; ip <= b; ++ip)
        free_ips.insert(ip);

    string cmd;
    while (true)
    {
        cout << "\nCommands: discover <MAC>, release <MAC>, show, exit\n> ";
        if (!(cin >> cmd))
            break;
        if (cmd == "discover")
        {
            string mac;
            cin >> mac;
            if (mac_to_ip.count(mac))
            {
                cout << "Already leased: " << int_to_ip(mac_to_ip[mac]) << "\n";
                continue;
            }
            if (free_ips.empty())
            {
                cout << "No IPs available\n";
                continue;
            }
            uint32_t ip = *free_ips.begin();
            free_ips.erase(free_ips.begin());
            mac_to_ip[mac] = ip;
            ip_to_mac[ip] = mac;
            cout << "Assigned " << int_to_ip(ip) << " to " << mac << "\n";
        }
        else if (cmd == "release")
        {
            string mac;
            cin >> mac;
            if (!mac_to_ip.count(mac))
            {
                cout << "No lease for " << mac << "\n";
                continue;
            }
            uint32_t ip = mac_to_ip[mac];
            mac_to_ip.erase(mac);
            ip_to_mac.erase(ip);
            free_ips.insert(ip);
            cout << "Released " << int_to_ip(ip) << " from " << mac << "\n";
        }
        else if (cmd == "show")
        {
            cout << "Active leases:\n";
            for (auto &p : mac_to_ip)
                cout << p.first << " -> " << int_to_ip(p.second) << "\n";
            cout << "Free IPs left: " << free_ips.size() << "\n";
        }
        else if (cmd == "exit")
            break;
        else
            cout << "Unknown command\n";
    }
    return 0;
}
