#include <iostream>
#include <algorithm>
#include <string>

#define INF 987654321
using namespace std;

int cnt[27];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        string W;
        int K, ans1=INF, ans2=-1;
        cin>>W>>K;
        
        if(W.length()==1){
            cout<<1<<" "<<1<<"\n";
            continue;
        }
        
        for(int i=0; i<26; i++) cnt[i]=0;
        
        // 알파벳 카운트
        for(int i=0; i<W.length(); i++) cnt[W[i]-'a']++;
        
        for(int i=0; i<W.length(); i++){
            if(cnt[W[i]-'a']<K) continue; // 어차피 해당 알파벳으로는 만족할 수 없음
            
            // K번 이상 등장한 문자열이면 그 이후 탐색
            int temp=0; // 연속된 문자열에서 해당 알파벳이 몇 개인지?
            for(int j=i; j<W.length(); j++){
                if(W[j]==W[i]) temp++;
                
                if(temp==K){
                    ans1=min(ans1, j-i+1);
                    ans2=max(ans2, j-i+1);
                    break;
                }
            }
        }
        
        if(ans1==INF) cout<<-1<<"\n";
        else cout<<ans1<<" "<<ans2<<"\n";
    }
}