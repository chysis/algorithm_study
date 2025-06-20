#include <bits/stdc++.h>
using namespace std;

int A, B, C;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true){
        cin>>A>>B>>C;
        if(A==0 && B==0 && C==0) break;
        
        int arr[3]={A, B, C};
        sort(arr, arr+3);
        
        if(arr[2]>=arr[0]+arr[1]){
            cout<<"Invalid\n";
            continue;
        }
        
        if(A==B && B==C && C==A) cout<<"Equilateral\n";
        else if((A==B && A!=C && B!=C) || (A==C && A!=B && B!=C) || (B==C && A!=B && A!=C)) cout<<"Isosceles\n";
        else if(A!=B && B!=C && C!=A) cout<<"Scalene\n";
    }
}