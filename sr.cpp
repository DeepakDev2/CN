// SR



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

    int cur = 1;

    while(cur<=total){
        cout<<"SENDING FRAMES ";
        for(int i=0;i<ws && (i+ws)<=total ;i++){
            cout<<cur+i<<" ";        
        }
        int lost = cur + (rand()%ws);
        if(lost>total) lost=total;

        cout<<"FRAME "<<lost<<" IS LOST"<<endl;

        cout<<"ACK RECIEVED FOR ";
        for(int i=cur;i<cur+ws && i<total;i++){
            if(i!=lost){
                cout<<i<<" ";
            }
        }

        cout<<"RESENDING FRAME"<<lost<<endl;

        cout<<"FRAME SENT SUCCESSFULLY"<<endl;

        cur+=ws; 

    }
}