#include <bits/stdc++.h>
using namespace std;

int N, target, ans=0, cnt=0;
char game;
string str;
set<string> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>N>>game;
	if(game=='Y') target=1;
	else if(game=='F') target=2;
	else target=3;
	
	for(int i=0; i<N; i++){
	    cin>>str;
	    if(s.find(str)==s.end()){
	        cnt++;
	        s.insert(str);
	    } else{
	        continue;
	    }
	    
	    if(cnt==target) {
	        ans++;
	        cnt=0;
	    }
	}
	
	cout<<ans;
}