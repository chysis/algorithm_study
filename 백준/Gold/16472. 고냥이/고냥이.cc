#include <bits/stdc++.h>
using namespace std;

int N, cnt[27];
string S;

int abCount(){
    int res=0;
    for(int i=0; i<26; i++){
        if(cnt[i]>0) res++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>S;
    
    int s=0, e=0, ans=0;
    cnt[S[0]-'a']++;
    while(true){
        if(e>=S.length()-1 && e-s+1<=ans) break;
        if(abCount()<=N) {
            ans=max(ans, e-s+1);
            if(e<S.length()-1){
                e++;
                cnt[S[e]-'a']++;
            }
        }
        else {
            s++;
            cnt[S[s-1]-'a']--;
        }
    }
    cout<<ans;
}