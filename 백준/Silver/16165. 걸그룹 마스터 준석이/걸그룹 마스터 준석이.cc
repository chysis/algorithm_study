#include <bits/stdc++.h>
using namespace std;

int N, M, popul;
string group, member;

struct GirlGroup {
    string name;
    vector<string> members;
};

GirlGroup groups[101];

void printAllMembers(string team){
    for(int i=0; i<N; i++){
        if(groups[i].name==team){
            for(auto a: groups[i].members){
                cout<<a<<"\n";
            }
            return;
        }
    }
}

void printTeamByMember(string member){
    for(int i=0; i<N; i++){
        for(int j=0; j<groups[i].members.size(); j++){
            if(member==groups[i].members[j]){
                cout<<groups[i].name<<"\n";
                return;
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>N>>M;
	for(int i=0; i<N; i++){
	    cin>>group>>popul;
	    groups[i].name=group;

	    for(int j=0; j<popul; j++){
	        cin>>member;
	        groups[i].members.push_back(member);
	    }
	    
	    sort(groups[i].members.begin(), groups[i].members.end());
	}
	
	for(int i=0; i<M; i++){
	    string target;
	    int opt;
	    cin>>target>>opt;
	    
	    if(opt==0){
	        printAllMembers(target);
	    }else{
	        printTeamByMember(target);
	    }
	}
}