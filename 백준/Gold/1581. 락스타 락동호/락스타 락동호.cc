#include <bits/stdc++.h>
using namespace std;

int FF, FS, SF, SS;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>FF>>FS>>SF>>SS;
    if(FF==0 && FS==0){
        cout<<SS+(SF==0 ? 0 : 1);
    }else{
        // F_로 시작
        int ans=0;
        ans+=FF;
        if(FS>0){
            ans++;
            FS--;
            
            ans+=SS;
            while(SF>0 && FS>0){
                SF--; ans++;
                FS--; ans++;
            }
            if(SF>0) ans++;
        }

        cout<<ans;
    }
}