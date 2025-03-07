#include <bits/stdc++.h>
using namespace std;

int N, arr[200001], fruit[10];

int countFruit() {
	int temp=0;
	for(int i=1; i<=9; i++) {
		if(fruit[i]>0) temp++;
	}
	return temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>N;
	for(int i=0; i<N; i++) {
		cin>>arr[i];
	}

	if(N<=2) {
		cout<<N;
		return 0;
	}

	int s=0, e=1, ans=0;
	fruit[arr[s]]++;
	fruit[arr[e]]++;

	while(s<N-1) {
		if(e==N-1) {
		    ans=max(ans, e-s+1);
			fruit[arr[s++]]--;
		} else {
            fruit[arr[++e]]++;
		}

		if(countFruit()>2) {
			fruit[arr[e--]]--;
			ans=max(ans, e-s+1);
			fruit[arr[s++]]--;
		}
	}

	cout<<ans;
}