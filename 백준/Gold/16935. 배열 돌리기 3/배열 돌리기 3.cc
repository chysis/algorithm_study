#include <bits/stdc++.h>
using namespace std;

int N, M, R, num, arr[101][101], temp[101][101];

void flipHorizontal(){
    for(int i=0; i<N/2; i++){
        swap_ranges(arr[i], arr[i]+M, arr[N-i-1]);
    }
}

void flipVertical(){
    for(int i=0; i<N; i++){
        reverse(arr[i], arr[i]+M);
    }
}

void rotateRight(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            temp[i][j]=arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            arr[j][N-i-1]=temp[i][j];
        }
    }
    
    swap(N, M);
}

void rotateLeft(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            temp[i][j]=arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            arr[M-j-1][i]=temp[i][j];
        }
    }
    
    swap(N, M);
}

void rotateSquareRight(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            temp[i][j]=arr[i][j];
        }
    }
    // 1 -> 2
    for(int i=0; i<N/2; i++){
        for(int j=0; j<M/2; j++){
            arr[i][j+M/2]=temp[i][j];
        }
    }
    // 2 -> 3
    for(int i=0; i<N/2; i++){
        for(int j=M/2; j<M; j++){
            arr[i+N/2][j]=temp[i][j];
        }
    }
    // 3 -> 4
    for(int i=N/2; i<N; i++){
        for(int j=M/2; j<M; j++){
            arr[i][j-M/2]=temp[i][j];
        }
    }
    // 4 -> 1
    for(int i=N/2; i<N; i++){
        for(int j=0; j<M/2; j++){
            arr[i-N/2][j]=temp[i][j];
        }
    }
}

void rotateSquareLeft(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            temp[i][j]=arr[i][j];
        }
    }
    // 1 -> 4
    for(int i=0; i<N/2; i++){
        for(int j=0; j<M/2; j++){
            arr[i+N/2][j]=temp[i][j];
        }
    }
    // 4 -> 3
    for(int i=N/2; i<N; i++){
        for(int j=0; j<M/2; j++){
            arr[i][j+M/2]=temp[i][j];
        }
    }
    // 3 -> 2
    for(int i=N/2; i<N; i++){
        for(int j=M/2; j<M; j++){
            arr[i-N/2][j]=temp[i][j];
        }
    }
    // 2 -> 1
    for(int i=0; i<N/2; i++){
        for(int j=M/2; j<M; j++){
            arr[i][j-M/2]=temp[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<R; i++){
        cin>>num;
        
        if(num==1) flipHorizontal();
        else if(num==2) flipVertical();
        else if(num==3) rotateRight();
        else if(num==4) rotateLeft();
        else if(num==5) rotateSquareRight();
        else if(num==6) rotateSquareLeft();
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}