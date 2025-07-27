#include <bits/stdc++.h>
using namespace std;

int N, A, B, C, D, arr[101], ran[101];
vector<int> score;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N*(N-1)/2; i++){
        cin>>A>>B>>C>>D;
        if(C>D) arr[A]+=3;
        else if(C<D) arr[B]+=3;
        else arr[A]++, arr[B]++;
    }
    
    for(int i=1; i<=N; i++) score.push_back(arr[i]);
    sort(score.begin(), score.end(), greater<int>());
    
    int cnt=1;
    ran[0]=cnt++;
    for(int i=1; i<score.size(); i++){
        if(score[i]==score[i-1]) ran[i]=ran[i-1];
        else ran[i]=cnt;
        cnt++;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<score.size(); j++){
            if(arr[i]==score[j]){
                cout<<ran[j]<<"\n";
                break;
            }
        }
    }
}