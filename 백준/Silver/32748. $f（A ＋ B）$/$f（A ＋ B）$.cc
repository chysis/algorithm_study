#include <bits/stdc++.h>
using namespace std;

char arr[10];
string a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0; i<10; i++) cin>>arr[i];
    cin>>a>>b;
    
    for(int i=0; i<a.length(); i++) a[i]=(find(arr, arr+10, a[i])-arr)+'0';
    for(int i=0; i<b.length(); i++) b[i]=(find(arr, arr+10, b[i])-arr)+'0';

    string c=to_string(stoi(a)+stoi(b));
    for(int i=0; i<c.length(); i++) cout<<arr[c[i]-'0'];
}