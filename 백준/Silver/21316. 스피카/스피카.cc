#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int adj[13][13];
int level[13];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<12; i++){
        int X, Y;
        cin>>X>>Y;
        adj[X][Y]=1;
        adj[Y][X]=1;
        level[X]++;
        level[Y]++;
    }
    
    for(int i=1; i<=12; i++){
        bool one=false, two=false, three=false;
        
        if(level[i]!=3) continue;
        for(int j=1; j<=12; j++){
            if(adj[i][j] && level[j]==1) one=true;
            if(adj[i][j] && level[j]==2) two=true;
            if(adj[i][j] && level[j]==3) three=true;
        }
        
        if(one && two && three){
            cout<<i;
            return 0;
        }
    }
}