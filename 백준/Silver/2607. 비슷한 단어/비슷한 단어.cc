#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int N;
string arr[101];
int comp[101][27];

bool isSimilar(int idx){
    // 길이가 2 이상 차이나는 경우
    if(abs((int)arr[0].length()-(int)arr[idx].length())>1) return false;
    
    // 두 단어의 구성이 최대 2개까지 다르면 비슷한 단어
    int diff=0;
    for(int i=0; i<26; i++){
        if(comp[0][i]!=comp[idx][i]){
            diff+=abs(comp[0][i]-comp[idx][i]);
        }
    }
    
    if(diff<=2) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<arr[i].length(); j++){
            comp[i][arr[i][j]-'A']++;
        }
    }
    
    int ans=0;
    for(int i=1; i<N; i++){
        if(isSimilar(i)) ans++;
    }
    
    cout<<ans;
}