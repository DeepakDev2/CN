// CHECKSUM


#include<iostream>
#include<string.h>

using namespace std;


string checksum(string d1,string d2){
    int c =0;
    string result ="";
    for(int i=d1.size()-1;i>=0;i--){
        int b1 = d1[i]-'0';
        int b2 = d2[i]-'0';

        int sum = b1+b2+c;

        result = char((sum%2)+'0') + result;
        c = sum/2;
    }

    if(c==1){
        for(int i=result.size()-1;i>=0;i--){
            if(result[i]=='0'){
                c=0;
                result[i]='1';
                break;
            }
            else{
                result[i]='0';
            }
        }
    }

    for(int i=0;i<result.size();i++){
        result[i] = (result[i]=='0')? '1':'0' ;
    }

    return result;
}
int main(){
    string d1,d2;
    cin>>d1>>d2;

    string ans = checksum(d1,d2);

    cout<<ans;
}