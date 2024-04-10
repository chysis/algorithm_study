#include <iostream>
#include <algorithm>

#define pdd pair<double, double>
using namespace std;

pdd arr[51];

bool isVisible(pdd &cur, pdd &target){
    double grad=(target.second-cur.second)/(target.first-cur.first);
    
    if(target.first<cur.first){
        for(int i=target.first+1; i<cur.first; i++){
            double tempGrad=(arr[i].second-cur.second)/(arr[i].first-cur.first);
            if(tempGrad<=grad) return false;
        }
    } else{
        for(int i=cur.first+1; i<target.first; i++){
            double tempGrad=(arr[i].second-cur.second)/(arr[i].first-cur.first);
            if(tempGrad>=grad) return false;
        }  
    }
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, ans=-1;
    cin>>N;
    
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        arr[i]={i, num};
    }
    
    for(int i=0; i<N; i++){
        auto cur=arr[i];
        int temp=0;

        for(int j=i-1; j>=0; j--){
            if(isVisible(cur, arr[j])) temp++;
        }
        
        for(int j=i+1; j<N; j++){
            if(isVisible(cur, arr[j])) temp++;
        }

        ans=max(ans, temp);
    }
    
    cout<<ans;
}