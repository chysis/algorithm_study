#include <bits/stdc++.h>
using namespace std;

int N, M, R, G, B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>R>>G>>B;
            int I=2126*R+7152*G+722*B;
            if(I>=0 && I<510000) cout<<"#";
            else if(I>=510000 && I<1020000) cout<<"o";
            else if(I>=1020000 && I<1530000) cout<<"+";
            else if(I>=1530000 && I<2040000) cout<<"-";
            else cout<<".";
        }
        cout<<"\n";
    }
}