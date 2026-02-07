#include <bits/stdc++.h>
using namespace std;

vector<pair<int, vector<int>>> arr; // 입력 저장, {학생 번호, 좋아하는 사람 목록}
pair<int, int> neighbors[21][21];
int N, S, num, occupied[21][21]; // 배치 완료된 학생들
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

void init_occupied(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            occupied[i][j]=-1;
        }
    }
}

void init_neighbors(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            neighbors[i][j]={-1, -1};
        }
    }
}

vector<int> get_lovers(int num){
    for(auto a: arr){
        if(a.first==num) return a.second;
    }
    return {};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0; i<N*N; i++){
        cin>>S;
        vector<int> v(4);
        for(int j=0; j<4; j++){
            cin>>v[j];
        }
        arr.push_back({S, v});
    }
    
    init_occupied();
    
    for(int i=0; i<N*N; i++){
        int cur_stud=arr[i].first;
        vector<int> lovers=arr[i].second;
        
        init_neighbors();
        
        // 빈 칸마다 인접 칸 조사하기
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                neighbors[j][k]={-1, -1};
                if(occupied[j][k]!=-1) continue;
                
                int lover_cnt=0, empty_cnt=0;
                for(int dir=0; dir<4; dir++){
                    int nx=j+dx[dir];
                    int ny=k+dy[dir];
                    if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                    
                    if(occupied[nx][ny]==-1) empty_cnt++;
                    else{
                        for(auto lover: lovers){
                            if(lover==occupied[nx][ny]){
                                lover_cnt++;
                                break;
                            }
                        }
                    }
                }
                
                neighbors[j][k]={lover_cnt, empty_cnt};
            }
        }
        
        // 배치할 칸 고르기
        pair<int, int> pos, meta={-1, -1};
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(neighbors[j][k].first>meta.first){
                    meta=neighbors[j][k];
                    pos={j, k};
                } else if(neighbors[j][k].first==meta.first){
                    if(neighbors[j][k].second>meta.second){
                        meta=neighbors[j][k];
                        pos={j, k};
                    }
                }
            }
        }
        
        // 배치
        occupied[pos.first][pos.second]=cur_stud;
    }
    
    // 만족도 계산
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int cur_stud=occupied[i][j];
            auto cur_stud_lovers=get_lovers(cur_stud);
            
            int lover_cnt=0;
            for(int k=0; k<4; k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                
                for(auto lover: cur_stud_lovers){
                    if(lover==occupied[nx][ny]){
                        lover_cnt++;
                        break;
                    }
                }
            }
            
            if(lover_cnt>0){
                ans+=pow(10, lover_cnt-1);
            } 
        }
    }
    
    cout<<ans;
}