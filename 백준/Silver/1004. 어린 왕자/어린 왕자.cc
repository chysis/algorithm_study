#include <bits/stdc++.h>
using namespace std;

int T, X1, Y1, X2, Y2, N, cx, cy, r;
tuple<int, int, int> arr[51];
vector<int> area1, area2; // 시작점, 끝점이 속해있는 원 인덱스 배열
bool chk[51]; 

bool isIn(int a, int b, int r, int px, int py){
    return (px-a)*(px-a) + (py-b)*(py-b) < r*r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T;
    while(T--){
        cin>>X1>>Y1>>X2>>Y2;
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>cx>>cy>>r;
            arr[i]={cx, cy, r};
        }
        
        for(int i=0; i<N; i++){
            int cx=get<0>(arr[i]);
            int cy=get<1>(arr[i]);
            int r=get<2>(arr[i]);
            if(isIn(cx, cy, r, X1, Y1)) area1.push_back(i);
            if(isIn(cx, cy, r, X2, Y2)) area2.push_back(i);
        }
        
        for(int i=0; i<area1.size(); i++) chk[area1[i]]=true;
        for(int i=0; i<area2.size(); i++){
            if(chk[area2[i]]) chk[area2[i]]=false;
            else chk[area2[i]]=true;
        }
        
        int ans=0;
        for(int i=0; i<N; i++){
            if(chk[i]) ans++;
        }
        cout<<ans<<"\n";
        
        area1.clear();
        area2.clear();
        memset(chk, false, sizeof(chk));
    }
}