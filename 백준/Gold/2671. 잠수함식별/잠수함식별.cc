#include <bits/stdc++.h>
using namespace std;

int idx=0, prevPattern=-1;
string S;

// 100~1~ 감지
int findPattern1(int start){
    int idx=start;
    if(start>S.length()-3) return -1; // 패턴의 최소 길이 4
    if(S[start]=='0'){
        // 1001100... 같은 경우
        if(!(prevPattern==1 && S[start-1]=='1' && S[start-2]=='1')) return -1;
        idx++;
    }else{
        if(S[start+1]!='0') return -1;
        idx+=2;
    }
    
    int cnt0=0, cnt1=0;
    while(idx<S.length()){
        if(S[idx]=='0') idx++, cnt0++;
        else{
            if(cnt0==0) return -1;
            else break;
        }
    }
    
    while(idx<S.length()){
        if(S[idx]=='1') idx++, cnt1++;
        else{
            if(cnt1==0) return -1;
            else break;
        }
    }
    if(cnt0==0 || cnt1==0) return -1;
    return idx;
}

// 01 감지
int findPattern2(int start){
    if(start>=S.length()-1) return -1; // 패턴의 최소 길이 2

    if(S[start]=='0' && S[start+1]=='1') return start+2;
    else return -1;
}

int main()
{
    // ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S;
    while(idx<S.length()){
        int res1=findPattern1(idx);
        int res2=findPattern2(idx);

        if(res1==-1 && res2==-1){
            cout<<"NOISE";
            return 0;
        }
        
        if(res1!=-1 && res2==-1) idx=res1, prevPattern=1;
        else if(res1==-1 && res2!=-1) idx=res2, prevPattern=2;
    }
    cout<<"SUBMARINE";
}