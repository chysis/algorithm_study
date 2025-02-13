#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int ans=schedules.size();
    for(int i=0; i<schedules.size(); i++){
        int basis=(schedules[i]/100)*60+schedules[i]%100;
        for(int j=0; j<7; j++){
            if((startday+j-1)%7==5 || (startday+j-1)%7==6) continue;
            int cur=(timelogs[i][j]/100)*60+timelogs[i][j]%100;
            if(cur-basis>10){
                ans--;
                break;
            }
        }
    }
    
    return ans;
}