#include <iostream>
#include <string>
using namespace std;

string S;
int ans=0, depth=0, times[51], repeat[51];

bool isNum(char c){
    return (c>='0' && c<='9');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>S;
    for(int i=0; i<S.length(); i++){
        if(isNum(S[i])){
            if(i==S.length()-1 || S[i+1]!='(') S[i]='1';
        } 
    }
    
    // cout<<S<<"\n";
    
    for(int i=0; i<S.length(); i++){
        if(isNum(S[i])){
            if(i+1<S.length() && S[i+1]=='(') times[depth+1]=(S[i]-'0');
            else repeat[depth]+=(S[i]-'0');
        } else if(S[i]=='('){
            depth++;
        } else if(S[i]==')'){
            repeat[depth-1]+=(times[depth]*repeat[depth]);
            times[depth]=0, repeat[depth]=0;
            depth--;
        }
        
        // cout<<"cur: "<<i<<"\n";
        // cout<<"depth: "<<depth<<" times: "<<times[depth]<<" repeat: "<<repeat[depth]<<"\n";
        // cout<<"ans: "<<ans<<"\n\n";
    }
    
    cout<<repeat[0];
}