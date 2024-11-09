#include <iostream>
#include <algorithm>
using namespace std;

int burgers[1001], sides[1001], beverage[1001];

bool comp(int a, int b){
    return a>b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int B, C, D;
    cin>>B>>C>>D;
    int sum=0;
    for(int i=0; i<B; i++){
        cin>>burgers[i];
        sum+=burgers[i];
    }
    
    for(int i=0; i<C; i++){
        cin>>sides[i];
        sum+=sides[i];
    }
    
    for(int i=0; i<D; i++){
        cin>>beverage[i];
        sum+=beverage[i];
    }
    
    sort(burgers, burgers+B, comp);
    sort(sides, sides+C, comp);
    sort(beverage, beverage+D, comp);
    
    int dcSum=0;
    int setCount=min(B, min(C, D));
    for(int i=0; i<setCount; i++){
        dcSum+=(burgers[i]+sides[i]+beverage[i])*0.9;
    }
    
    for(int i=setCount; i<max(B, max(C, D)); i++){
        if(B>=i) dcSum+=burgers[i];
        if(C>=i) dcSum+=sides[i];
        if(D>=i) dcSum+=beverage[i];
    }
    
    cout<<sum<<"\n"<<dcSum;
}