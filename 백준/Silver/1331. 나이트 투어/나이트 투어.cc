#include <bits/stdc++.h>
using namespace std;

char col, row;
char sx, sy, ex, ey;
bool visited[7][7];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string ans="Valid";
    char px, py;
    for(int i=0; i<36; i++){
        cin>>col>>row;
        if(i==0){
            sx=col, sy=row;
            px=col, py=row;
        } else if(i==35){
            ex=col, ey=row;
        }
        
        if(i>0){
            if(!(abs(px-col)==1 && abs(py-row)==2) && !(abs(px-col)==2 && abs(py-row)==1)) ans="Invalid";
        }
        if(visited[col-'A'][row-'1']){
            ans="Invalid";
        }
        
        px=col, py=row;
        visited[col-'A'][row-'1']=true;
    }
    
    if(!(abs(sx-ex)==1 && abs(sy-ey)==2) && !(abs(sx-ex)==2 && abs(sy-ey)==1)) ans="Invalid";
    cout<<ans;
}