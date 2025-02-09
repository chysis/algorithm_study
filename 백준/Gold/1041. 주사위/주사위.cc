#include <iostream>
#include <algorithm>

#define INF (~0U>>2)
#define ll long long
using namespace std;

ll N, dice[7], minFace=INF, minTwoFace=INF, maxInTwoFace=-1, minThreeFace=INF, maxInThreeFace=-1, threeFace[3];
bool adj[7][7];

void solve(int cnt, int prev){
    if(cnt==3){
        ll temp=0;
        for(int i=0; i<3; i++){
            temp+=dice[threeFace[i]];
        }
        if(temp<minThreeFace){
            minThreeFace=temp;
            maxInThreeFace=max(dice[threeFace[0]], max(dice[threeFace[1]], dice[threeFace[2]]));
        }
        return;
    }
    
    for(int i=prev+1; i<6; i++){
        bool flag=true;
        for(int j=0; j<cnt; j++){
            if(!adj[threeFace[j]][i]){
                flag=false;
                break;
            }
        }
        if(flag){
            threeFace[cnt]=i;
            solve(cnt+1, i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<6; i++){
        cin>>dice[i];
        minFace=min(minFace, dice[i]);
    }
    
    if(N==1){
        ll maxDice=-1, sum=0;
        for(int i=0; i<6; i++){
            maxDice=max(maxDice, dice[i]);
            sum+=dice[i];
        }
        
        cout<<sum-maxDice;
        return 0;
    }
    
    // 이웃한 면 체크
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            adj[i][j]=true;
        }
    }
    
    // A-F, B-E, C-D는 이웃하지 않음
    adj[0][5]=adj[5][0]=false;
    adj[1][4]=adj[4][1]=false;
    adj[2][3]=adj[3][2]=false;
    
    // 이웃한 두 면의 합의 최솟값
    for(int i=0; i<6; i++){
        ll temp=dice[i];
        for(int j=i+1; j<6; j++){
            if(adj[i][j]){
                temp+=dice[j];
                if(temp<minTwoFace){
                    minTwoFace=temp;
                    maxInTwoFace=max(dice[i], dice[j]);
                }
                temp-=dice[j];
            }
        }
    }
    
    solve(0, -1);
    
    ll ans=minFace*(N-2)*(N-2)*5+minTwoFace*(N-2)*12+minThreeFace*8-4*maxInThreeFace-4*(N-2)*maxInTwoFace;
    cout<<ans;
}