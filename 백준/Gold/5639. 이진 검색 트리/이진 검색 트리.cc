#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num;
vector<int> v;
bool visited[10001];

void solve(int s, int e){
    if(s>=e) return; // 오른쪽 자식만 있는 경우 중복 출력 방지
    if(s+1>=e) {
        cout<<v[s]<<"\n";
        return;
    }
    
    int target=upper_bound(v.begin()+s, v.begin()+e, v[s])-v.begin();
    
    solve(s+1, target);
    solve(target, e);
    cout<<v[s]<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin>>num){
        v.push_back(num);
    }
    
    solve(0, v.size());
}