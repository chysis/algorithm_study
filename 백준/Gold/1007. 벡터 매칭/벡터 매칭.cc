#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <cmath>
#include <algorithm>

#define INF 987654321
using namespace std;

int N;
double res=INF;
vector<pair<int, int>> P;
bool used[21];
bool check[21];
int ans[11];

void solve(int cnt, int idx){
    if(cnt==N/2){
        memset(check, false, sizeof(check));
        pair<double, double> endSum={0.0, 0.0};
        pair<double, double> startSum={0.0, 0.0};
        
        for(int i=0; i<N/2; i++){
            check[ans[i]]=true;
            endSum.first+=P[ans[i]].first;
            endSum.second+=P[ans[i]].second;
        }
        
        for(int i=0; i<N; i++){
            if(!check[i]){
                startSum.first+=P[i].first;
                startSum.second+=P[i].second;
            }
        }
        
        pair<double, double> a={endSum.first-startSum.first, endSum.second-startSum.second};
        res=min(res, sqrt(a.first*a.first+a.second*a.second));
        
        return;
    }
    
    for(int i=idx; i<N; i++){
        if(!used[i]){
            used[i]=true;
            ans[cnt]=i;
            solve(cnt+1, i);
            used[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cout<<fixed;
    cout.precision(6);
    
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0; i<N; i++){
            int X, Y;
            cin>>X>>Y;
            P.push_back({X, Y});
        }
        
        solve(0, 0);
        cout<<res<<"\n";
        
        res=INF;
        P.clear();
    }
}