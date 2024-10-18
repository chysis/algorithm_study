#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--){
        int A, B;
        cin>>A>>B;
        
        int x1=0, y1=0, x2=0, y2=0;
        for(int i=1; i<=200; i++){
            for(int j=1; i<=200; j++){
                if((i+j)*(i+j)-i-3*j+2==2*A){
                    x1=i, y1=j;
                    break;
                } else if((i+j)*(i+j)-i-3*j+2>2*A){
                    break;
                }
            }
        }
        
        for(int i=1; i<=200; i++){
            for(int j=1; i<=200; j++){
                if((i+j)*(i+j)-i-3*j+2==2*B){
                    x2=i, y2=j;
                    break;
                } else if((i+j)*(i+j)-i-3*j+2>2*B){
                    break;
                }
            }
        }
        
        int x=x1+x2, y=y1+y2;
        cout<<((x+y)*(x+y)-x-3*y+2)/2<<"\n";
    }
}