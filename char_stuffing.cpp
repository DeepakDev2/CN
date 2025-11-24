// CHAR STUFFING

#include<iostream>
#include<string.h>

using namespace std;


string Char_stuff(string s){
    string stuff ="";
    for(int i=0;i<s.size();i++){
        if(i<s.size()-2 && s[i]=='D' && s[i+1]=='L' && s[i+2]=='E'){
            stuff+="DLE";
        }
        stuff+=s[i];
    }

    return stuff;
}
int main(){
    string data;
    cin>>data;

    string start ="DLESTR";
    string end ="DLEEND";


    string ans = start + Char_stuff(data) + end;

    cout<<"STUFFED STRING IS ="<<ans<<endl;
}