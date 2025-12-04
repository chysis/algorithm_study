#include <bits/stdc++.h>
using namespace std;

bool isHacker=false;
int sum=0, num;
int maxScore[10]={100, 100, 200, 200, 300, 300, 400, 400, 500};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0; i<9; i++){
        cin>>num;
        sum+=num;
        if(num>maxScore[i]){
            isHacker=true;
        }
    }
    
    if(isHacker) cout<<"hacker";
    else if(sum>=100) cout<<"draw";
    else cout<<"none";
}