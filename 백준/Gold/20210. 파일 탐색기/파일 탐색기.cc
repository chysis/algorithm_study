#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int N;
string arr[10001];
vector<string> newArr[10001];

bool isNumber(char c){
    return c>='0' && c<='9';
}

bool isUpper(char c){
    return c>='A' && c<='Z';
}

bool isLower(char c){
    return c>='a' && c<='z';
}

string concatStr(vector<string> v){
    string res="";
    for(auto a: v) res+=a;
    return res;
}

// a가 더 크면 1, b가 더 크면 -1, 같으면 0
int compNum(string a, string b){
    if(a==b) return 0;
    
    // 앞에 붙은 0 제거
    int firstNotZero=-1;
    for(int i=0; i<a.length(); i++){
        if(a[i]!='0'){
            firstNotZero=i;
            break;
        }
    }
    if(firstNotZero!=-1) a=a.substr(firstNotZero);
    else a="0";
    
    firstNotZero=-1;
    for(int i=0; i<b.length(); i++){
        if(b[i]!='0'){
            firstNotZero=i;
            break;
        }
    }
    if(firstNotZero!=-1) b=b.substr(firstNotZero);
    else b="0";
    
    // 비교
    if(a==b) return 0;
    else if(a.length()>b.length()) return 1;
    else if(a.length()<b.length()) return -1;
    
    for(int i=0; i<a.length(); i++){
        if(a[i]-'0'>b[i]-'0') return 1;
        else if(a[i]-'0'<b[i]-'0') return -1;
    }
    
    return 0;
}

bool comp(vector<string> a, vector<string> b){
    int rep=max(a.size(), b.size()); // 더 긴 문자열에 맞춰서 비교
    for(int i=0; i<rep; i++){
        // 앞부분이 일치하고 문자열 길이가 다른 경우
        if(i>=a.size()) return true;
        else if(i>=b.size()) return false;
        
        // 숫자열과 문자열 판단
        if(isNumber(a[i][0]) && !isNumber(b[i][0])) return true;
        else if(!isNumber(a[i][0]) && isNumber(b[i][0])) return false;
        else if(isNumber(a[i][0]) && isNumber(b[i][0])){ // 둘 다 숫자
            int aZero=0, bZero=0;
            int compRes=compNum(a[i], b[i]);
            
            if(compRes==1) return false; // 숫자가 작은 게 앞으로
            else if(compRes==-1) return true;
            else{ // 숫자가 같으면 0 개수가 적은 게 앞으로
                for(int j=0; j<a[i].size(); j++){
                    if(a[i][j]=='0') aZero++;
                    else break;
                }
                
                for(int j=0; j<b[i].size(); j++){
                    if(b[i][j]=='0') bZero++;
                    else break;
                }
                
                if(aZero!=bZero) return aZero<bZero;
            }
        }
        else{ // 둘 다 알파벳
            int aChar, bChar;
            if(isUpper(a[i][0])) aChar=a[i][0]-'A';
            else aChar=a[i][0]-'a';
            
            if(isUpper(b[i][0])) bChar=b[i][0]-'A';
            else bChar=b[i][0]-'a';
            
            if(aChar!=bChar) return aChar<bChar;
            else{
                // 값이 같으면 대소문자 비교
                if(isUpper(a[i][0]) && isLower(b[i][0])) return true;
                else if(isLower(a[i][0]) && isUpper(b[i][0])) return false;
            }
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    // 입력 문자열 가공(숫자는 묶고 알파벳은 따로따로)
    for(int i=0; i<N; i++){
        for(int j=0; j<arr[i].length(); j++){
            if((arr[i][j]>='A' && arr[i][j]<='Z') || (arr[i][j]>='a' && arr[i][j]<='z')){
                newArr[i].push_back(arr[i].substr(j, 1));
            }else{
                if(j>0 && arr[i][j-1]>='0' && arr[i][j-1]<='9'){
                    newArr[i][newArr[i].size()-1]+=arr[i][j];
                }
                else newArr[i].push_back(arr[i].substr(j, 1));
            }
        }
    }
    
    sort(newArr, newArr+N, comp);
    
    for(int i=0; i<N; i++){
        cout<<concatStr(newArr[i])<<"\n";
    }
}