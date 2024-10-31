#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int N;
vector<int> arr;

ll mergeSort(vector<int>& arr, int s, int m, int e){
    vector<int> v1(arr.begin()+s, arr.begin()+m+1), v2(arr.begin()+m+1, arr.begin()+e+1);
    
    ll sum=0;
    int i=0, j=0, k=s;
    while(i<m-s+1 && j<e-m){
        if(v1[i]<=v2[j]){
            arr[k++]=v1[i++];
        } else{
            arr[k++]=v2[j++];
            sum+=(m-s+1-i);
        }
    }
    
    while(i<m-s+1) arr[k++]=v1[i++];
    while(j<e-m) arr[k++]=v2[j++];
    
    return sum;
}

ll countInversion(vector<int>& arr, int s, int e){
    ll temp=0;
    if(s<e){
        int m=(s+e)/2;
        
        temp+=countInversion(arr, s, m);
        temp+=countInversion(arr, m+1, e);
        
        temp+=mergeSort(arr, s, m, e);
    }
    
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    
    cout<<countInversion(arr, 0, N-1);
}