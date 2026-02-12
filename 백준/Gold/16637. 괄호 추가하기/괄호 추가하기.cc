#include <bits/stdc++.h>
#define INF (~0U>>2)
using namespace std;

int N, ans=-INF;
string S;
bool sel[10], used[10];

bool isNumber(char c){
    return c>='0' && c<='9';
}

int apply(int a, char op, int b){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    return a*b;
}

int calc(){
    vector<int> nums;
    vector<char> ops;

    int n0 = S[0]-'0';
    nums.push_back(n0);

    int opCnt = N/2; // 연산자 개수
    for(int opIdx=0; opIdx<opCnt; opIdx++){
        char op = S[2*opIdx + 1];
        int nxt = S[2*opIdx + 2]-'0';

        if(sel[opIdx]){
            // 괄호 안의 식은 먼저 계산해서 하나의 숫자로 합침
            int left = nums.back();
            nums.pop_back();
            nums.push_back(apply(left, op, nxt));
        } else {
            ops.push_back(op);
            nums.push_back(nxt);
        }
    }

    // 남은 걸 왼쪽부터 계산
    int res=nums[0];
    for(int i=0; i<ops.size(); i++){
        res=apply(res, ops[i], nums[i+1]);
    }
    return res;
}

void solve(int cnt){
    if(cnt>=N/2){
        int res=calc();
        ans=max(ans, res);
        return;
    }
    
    // 해당 연산자에 괄호 안 치는 경우
    solve(cnt+1);
    
    // 해당 연산자에 괄호 치는 경우
    sel[cnt]=true;
    solve(cnt+2); // 인접한 연산자는 패스
    sel[cnt]=false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>S;
    int ops_cnt=N/2; // 연산자 개수
    
    // 설치할 괄호쌍 개수
    for(int i=0; i<=(ops_cnt+1)/2; i++){
        solve(i);
    }
    cout<<ans;
}