#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        
        pair<int, int> cur={0, 0};
        int xMin=0, xMax=0, yMin=0, yMax=0;
        int dir=0;
        
        for(int i=0; i<str.length(); i++){
            if(str[i]=='F'){
                cur={cur.first+dx[dir], cur.second+dy[dir]};
                xMin=min(xMin, cur.first);
                xMax=max(xMax, cur.first);
                yMin=min(yMin, cur.second);
                yMax=max(yMax, cur.second);
            } else if(str[i]=='B'){
                cur={cur.first-dx[dir], cur.second-dy[dir]};
                xMin=min(xMin, cur.first);
                xMax=max(xMax, cur.first);
                yMin=min(yMin, cur.second);
                yMax=max(yMax, cur.second);
            } else if(str[i]=='L'){
                dir--;
                if(dir<0) dir=3;
            } else if(str[i]=='R'){
                dir++;
                if(dir>3) dir=0;
            }
        }
        
        cout<<(xMax-xMin)*(yMax-yMin)<<"\n";
    }
}