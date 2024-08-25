#include <iostream>
#include <cmath>
#include <algorithm>

#define INF 987654321
using namespace std;

int x, y;
double res=INF;
pair<int, int> arr[4];
pair<int, int> ans[5];
bool visited[4];

void solve(int cnt){
    if(cnt==4){
        double temp=0;
        for(int i=1; i<=3; i++){
            temp+=sqrt(pow(ans[i].first-ans[i-1].first, 2)+pow(ans[i].second-ans[i-1].second, 2));
        }
        if(res>temp) res=temp;
        return;   
    }
    
    for(int i=1; i<=3; i++){
        if(!visited[i]){
            visited[i]=true;
            ans[cnt]={arr[i].first, arr[i].second};
            solve(cnt+1);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>x>>y;
    ans[0]={x, y};
    for(int i=1; i<=3; i++){
        int A, B;
        cin>>A>>B;
        arr[i]={A, B};
    }
    
    solve(1);
    cout<<(int)res;
}