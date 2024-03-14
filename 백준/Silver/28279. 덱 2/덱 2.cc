#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    while(N--){
        int opt;
        cin>>opt;
        if(opt==1){
            int X; cin>>X;
            dq.push_front(X);
        }
        else if(opt==2){
            int X; cin>>X;
            dq.push_back(X);
        }
        else if(opt==3){
            if(dq.empty()) cout<<-1<<"\n";
            else{
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
        }
        else if(opt==4){
            if(dq.empty()) cout<<-1<<"\n";
            else{
                cout<<dq.back()<<"\n";
                dq.pop_back();
            }
        }
        else if(opt==5){
            cout<<dq.size()<<"\n";
        }
        else if(opt==6){
            cout<<(dq.empty() ? 1: 0)<<"\n";
        }
        else if(opt==7){
            if(dq.empty()) cout<<-1<<"\n";
            else cout<<dq.front()<<"\n";
        }
        else if(opt==8){
            if(dq.empty()) cout<<-1<<"\n";
            else cout<<dq.back()<<"\n";
        }
    }
}