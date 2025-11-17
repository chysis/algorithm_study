#include <bits/stdc++.h>
using namespace std;

struct youtuber{
    bool cnt[55][8];
    int streamTime[55]; // idx: 주차 수, 분 단위
};

int N, M, day, sh, eh, sm, em;
string name;
char c;
unordered_map<string, youtuber> um;
vector<string> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>name>>day>>sh>>c>>sm>>eh>>c>>em;
        
        um[name].cnt[(day-1)/7][(day-1)%7]=true;
        um[name].streamTime[(day-1)/7]+=(eh*60+em-sh*60-sm);
    }
    
    for(auto cur: um){
        bool flag=true;
        for(int i=0; i<M/7; i++){
            int temp=0;
            for(int j=0; j<7; j++){
                if(cur.second.cnt[i][j]) temp++;
            }
            if(temp<5){
                flag=false;
                break;
            }
            
            if(cur.second.streamTime[i]<60*60){
                flag=false;
                break;
            }
        }
        
        if(!flag) continue;
        ans.push_back(cur.first);
    }
    
    sort(ans.begin(), ans.end());
    if(ans.size()==0) cout<<-1;
    else{
        for(auto a: ans) cout<<a<<"\n";
    }
}