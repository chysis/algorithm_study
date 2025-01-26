#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int N, K, cnt=0, ans=0, temp=0, selected[27], appearCnt=0;
set<char> arr[51];
bool chk[51][27], appear[27], visited[27];

void solve(int c, int prev){
    if(c==min(K-5, appearCnt)){ // K-5개를 학습하거나 입력에 등장하는 총 알파벳 가지수만큼 골랐을 때
        bool chkCopy[51][27];
        // chk 복사
        for(int i=0; i<cnt; i++){
            for(int j=0; j<26; j++){
                chkCopy[i][j]=chk[i][j];
            }
        }
        
        // 선택한 알파벳 학습
        for(int i=0; i<c; i++){
            for(int j=0; j<cnt; j++){
                chkCopy[j][selected[i]]=false;
            }
        }
        
        // 배울 수 있는 단어 개수 체크
        int tempCnt=0;
        for(int i=0; i<cnt; i++){
            bool flag=true;
            for(int j=0; j<26; j++){
                if(chkCopy[i][j]){
                    flag=false;
                    break;
                }
            }
            
            if(flag) tempCnt++;
        }
        
        // temp 최댓값 갱신
        temp=max(temp, tempCnt);
        
        return;
    }
    
    for(int i=prev; i<26; i++){
        if(!appear[i]) continue;
        if(!visited[i]){
            visited[i]=true;
            selected[c]=i;
            solve(c+1, i);
            visited[i]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        
        // a, n, t, i, c 제외하고 추가로 필요한 알파벳 표시
        for(int j=4; j<str.length()-4; j++){
            if(str[j]=='a' || str[j]=='n' || str[j]=='t' || str[j]=='i' || str[j]=='c') continue;
            arr[i].insert(str[j]);
        }
    }
    
    if(K<5){
        cout<<0;
        return 0;
    }
    
    for(int i=0; i<N; i++){
        if(arr[i].size()>K-5) continue; // K개 학습해도 불가능한 단어
        else if(arr[i].size()==0) {  // 학습하지 않아도 가능한 단어
            ans++;
            continue;
        }
        
        for(auto a: arr[i]){
            chk[cnt][a-'a']=true;
        }
        cnt++;
    }
    
    // 추린 단어 중 등장하는 알파벳만 표시
    for(int i=0; i<26; i++){
        for(int j=0; j<cnt; j++){
            if(chk[j][i]){
                appear[i]=true;
                break;
            }
        }
    }
    
    for(int i=0; i<26; i++){
        if(appear[i]) appearCnt++;
    }
    
    solve(0, 0);
    cout<<ans+temp;
}