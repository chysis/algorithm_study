#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long k, a, b, c, d;
	cin>>k>>a>>b>>c>>d;
	
	if(a*k+b==c*k+d){
	    cout<<"Yes "<<a*k+b;
	} else cout<<"No";
}