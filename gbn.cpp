// GO BACK N

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main(){
    srand(time(0));

    int total;
    cout<<"ENTER TOTAL NO OF FRAMES TO BE SENT"<<endl;
    cin>>total;
    int ws;
    cout<<"ENTER THE WINDOW SIZE"<<endl;
    cin>>ws;

    int curr = 1;
    while(curr<total){
        for(int i =0;i<ws && (curr+i)<=total;i++){
            cout<<"SENDING FRAME "<<curr+i<<endl;
        }

        int lost = curr + (rand()%ws);
        if(lost>total)lost =total;

        cout<<"FRAME "<<lost<<" IS LOST"<<endl;

        cout<<"ACK RECIEVED FOR ";
        for(int i=curr;i<lost;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        curr=lost;
    }

    cout<<"FINISHED"<<endl;
}