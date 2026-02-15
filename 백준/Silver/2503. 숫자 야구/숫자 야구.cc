#include <bits/stdc++.h>
using namespace std;

int N, Q, S, B;
pair<int, pair<int, int>> arr[101];

bool isValid(int target, int Q, int S, int B){
    string targetStr=to_string(target), QStr=to_string(Q);
    int s_cnt=0, b_cnt=0;
    
    for(int i=0; i<3; i++){
        if(targetStr[i]==QStr[i]) s_cnt++;
        else{
            if(i==0){
                if(targetStr[0]==QStr[1] || targetStr[0]==QStr[2]) b_cnt++;
            }else if(i==1){
                if(targetStr[1]==QStr[0] || targetStr[1]==QStr[2]) b_cnt++;
            }else{
                if(targetStr[2]==QStr[0] || targetStr[2]==QStr[1]) b_cnt++;
            }
        }
    }
    
    return s_cnt==S && b_cnt==B;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>Q>>S>>B;
        arr[i]={Q, {S, B}};
    }
    
    int ans=0;
    for(int i=100; i<=999; i++){
        // 서로 다른 숫자 세 개인지 확인
        string temp=to_string(i);
        if(temp[0]=='0' || temp[1]=='0' || temp[2]=='0') continue;
        if(temp[0]==temp[1] || temp[0]==temp[2] || temp[1]==temp[2]) continue;
        
        bool valid=true;
        for(int j=0; j<N; j++){
            if(!isValid(i, arr[j].first, arr[j].second.first, arr[j].second.second)){
                valid=false;
                break;
            }
        }
        if(valid) ans++; 
    }
    
    cout<<ans;
}