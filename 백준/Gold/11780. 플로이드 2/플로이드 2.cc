#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;

int arr[101][101];
int path[101][101];
vector<int> route;

void findPath(int s, int e){
    if(path[s][e]==0){
        route.push_back(s);
        route.push_back(e);
        return;
    }
    
    findPath(s, path[s][e]);
    route.pop_back();
    findPath(path[s][e], e);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            arr[i][j]=INF;
            if(i==j) arr[i][j]=0;
        }
    }
    
    int N, M;
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int A, B, C;
        cin>>A>>B>>C;
        if(arr[A][B]>C) arr[A][B]=C;
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(arr[i][j]>arr[i][k]+arr[k][j]){
                    arr[i][j]=arr[i][k]+arr[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]==0 || arr[i][j]==INF){
                cout<<0<<" ";
            }
            else cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j]==0 || arr[i][j]==INF) cout<<0<<"\n";
            else {
                route.clear();
                findPath(i, j);
                cout<<route.size()<<" ";
                for(auto a: route){
                    cout<<a<<" ";
                }
                cout<<"\n";
            }
        }
    }
}