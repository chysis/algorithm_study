#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string line;
    getline(cin, line);
    
    for(int i=0; i<line.length(); i++){
        if(line[i]>='A' && line[i]<='Z'){
            if(line[i]-'A'>=13) cout<<(char)(line[i]-13);
            else cout<<(char)(line[i]+13);
        } else if(line[i]>='a' && line[i]<='z'){
            if(line[i]-'a'>=13) cout<<(char)(line[i]-13);
            else cout<<(char)(line[i]+13);
        } else cout<<line[i];
    }
}