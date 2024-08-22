#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

int Q, m, total=0;
vector<int> v[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>Q>>m;
    for(int i=0; i<Q; i++){
        int opt;
        cin>>opt;
        if(opt==1){
            int num;
            cin>>num;
            v[num%m].push_back(total++);
        } else if(opt==2){
            if(i==0) continue;
            
            int targetIdx=total-1;
            for(int j=0; j<m; j++){
                if(!v[j].empty() && v[j].back()==targetIdx) {
                    v[j].pop_back();
                    total--;
                    break;
                }
            }
        } else if(opt==3){
            int res=INF;
            bool flag=false;
            for(int j=0; j<m; j++){
                if(v[j].empty()){
                    flag=true;
                    break;
                }
                res=min(res, v[j].back());
            }
            
            if(!flag) cout<<total-res<<"\n";
            else cout<<-1<<"\n";
        }
    }
}