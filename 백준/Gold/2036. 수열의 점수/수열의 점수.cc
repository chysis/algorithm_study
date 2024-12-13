#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

ll ans=0;
vector<ll> pos, neg;
bool hasZero=false;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	for(int i=0; i<N; i++){
	    int num;
	    cin>>num;
	    if(num>1) pos.push_back(num);
	    else if(num==1) ans+=1;
	    else if(num<0) neg.push_back(num);
	    else hasZero=true;
	}
	
	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end(), less<int>());
	
	for(int i=0; i<2*(pos.size()/2); i+=2){
	    ans+=pos[i]*pos[i+1];
	}
	
	if(pos.size()%2==1) ans+=pos[pos.size()-1];
	
	for(int i=0; i<2*(neg.size()/2); i+=2){
	    ans+=neg[i]*neg[i+1];
	}
	
	if(neg.size()%2==1) {
	    if(!hasZero) ans+=neg[neg.size()-1];
	}
	
	cout<<ans;
}