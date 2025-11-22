// subnet_cidr.cpp
// Compile: g++ -std=c++17 subnet_cidr.cpp -o subnet_cidr
#include <bits/stdc++.h>
using namespace std;
uint32_t ip_to_int(const string &ip)
{
    unsigned a, b, c, d;
    sscanf(ip.c_str(), "%u.%u.%u.%u", &a, &b, &c, &d);
    return (a << 24) | (b << 16) | (c << 8) | d;
}
string int_to_ip(uint32_t x) { return to_string((x >> 24) & 255) + "." + to_string((x >> 16) & 255) + "." + to_string((x >> 8) & 255) + "." + to_string(x & 255); }

int main()
{
    cout << "CIDR/Subnet tool\nEnter IP (e.g. 10.0.0.5) and prefix length (e.g. 24):\n";
    string ip;
    int prefix;
    if (!(cin >> ip >> prefix))
        return 0;
    uint32_t ipn = ip_to_int(ip);
    uint32_t mask = prefix == 0 ? 0 : (~uint32_t(0) << (32 - prefix));
    uint32_t net = ipn & mask;
    uint32_t broadcast = net | (~mask);
    uint64_t host_count = (prefix == 32) ? 1 : (prefix == 31 ? 2 : (uint64_t(1) << (32 - prefix)) - 2);
    cout << "Network: " << int_to_ip(net) << "/" << prefix << "\n";
    cout << "Mask: " << int_to_ip(mask) << "\n";
    cout << "Broadcast: " << int_to_ip(broadcast) << "\n";
    if (prefix <= 30)
    {
        cout << "First usable: " << int_to_ip(net + 1) << "\n";
        cout << "Last usable : " << int_to_ip(broadcast - 1) << "\n";
    }
    else if (prefix == 31)
    {
        cout << "Usable hosts (point-to-point): " << int_to_ip(net) << " and " << int_to_ip(broadcast) << "\n";
    }
    else
    {
        cout << "Single host: " << int_to_ip(net) << "\n";
    }
    cout << "Usable hosts count (approx): " << host_count << "\n";

    cout << "\nEnter number of equal subnets to split into (or 0 to exit): ";
    int n;
    cin >> n;
    if (n <= 1)
    {
        cout << "Done\n";
        return 0;
    }
    // find required additional bits
    int additional = 0;
    while ((1 << additional) < n)
        additional++;
    int new_prefix = prefix + additional;
    if (new_prefix > 32)
    {
        cout << "Cannot split into that many subnets\n";
        return 0;
    }
    uint32_t subnet_size = (new_prefix == 32) ? 1u : (1u << (32 - new_prefix));
    cout << "New prefix: /" << new_prefix << " , each subnet size: " << subnet_size << " addresses\n";
    for (int i = 0; i < n; i++)
    {
        uint32_t s_net = net + i * subnet_size;
        uint32_t s_broadcast = s_net + subnet_size - 1;
        cout << "Subnet " << i + 1 << ": " << int_to_ip(s_net) << "/" << new_prefix
             << "  first:" << (subnet_size >= 2 ? int_to_ip(s_net + 1) : int_to_ip(s_net))
             << " last:" << (subnet_size >= 2 ? int_to_ip(s_broadcast - 1) : int_to_ip(s_broadcast))
             << " broadcast:" << int_to_ip(s_broadcast) << "\n";
    }
    return 0;
}
