#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Monster{
    string name;
    int atk;
    int def;
    int maxHp;
    int hp;
    int xp;
};

struct Equipment{
    int type; // ['W', 'A', 'O']
    int atk; // W만 해당
    int def; // A만 해당
    int AccEffect; // O만 해당, ['HR', 'RE', 'CO', 'EX', 'DX', 'HU', 'CU']
    
    Equipment(): type(-1), atk(0), def(0), AccEffect(0) {}
};

struct Hero{
    int maxHp;
    int hp;
    int atk;
    int def;
    int level;
    int maxXp;
    int xp;
    
    Equipment weapon;
    Equipment armor;
    vector<Equipment> accessories[7]; // 각 효과별로 관리
    
    Hero(): maxHp(20), hp(20), atk(2), def(2), level(1), maxXp(5), xp(0) {}
    
    void levelUp(){
        this->level++;
        this->maxXp=5*this->level;
        this->maxHp+=5;
        this->hp=this->maxHp;
        this->atk+=2;
        this->def+=2;
        this->xp=0;
    }
    
    void gainXp(int amount){
        if(this->accessories[3].size()!=0) amount=static_cast<int>(amount * 1.2);
        this->xp+=amount;
        
        if(this->xp>=maxXp){
            levelUp();
        }
    }
};

int N, M, startX, startY, curX, curY, K=0, L=0, turn=0;
string S;
char map[101][101];

Hero hero;
Monster monsters[101][101];
Equipment itemBoxes[101][101];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // input
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>map[i][j];
            if(map[i][j]=='@'){
                startX=i, startY=j;
                curX=i, curY=j;
                map[i][j]='.'; // 변수로만 주인공 위치 관리
            } else if(map[i][j]=='&' || map[i][j]=='M'){
                K++;
            } else if(map[i][j]=='B'){
                L++;
            }
        }
    }
    
    cin>>S;
    
    for(int i=0; i<K; i++){
        int R, C, W, A, H, E;
        string S;
        cin>>R>>C>>S>>W>>A>>H>>E;
        
        Monster monster={S, W, A, H, H, E};
        monsters[R][C]=monster;
    }
    
    for(int i=0; i<L; i++){
        int R, C;
        char T;
        cin>>R>>C>>T;
        if(T=='W'){
            int S; cin>>S;
            Equipment equipment;
            equipment.type=0;
            equipment.atk=S;
            itemBoxes[R][C]=equipment;
        } else if(T=='A'){
            int S; cin>>S;
            Equipment equipment;
            equipment.type=1;
            equipment.def=S;
            itemBoxes[R][C]=equipment;
        } else{
            string S; cin>>S;
            Equipment equipment;
            equipment.type=2;
            
            if(S=="HR") equipment.AccEffect=0;
            else if(S=="RE") equipment.AccEffect=1;
            else if(S=="CO") equipment.AccEffect=2;
            else if(S=="EX") equipment.AccEffect=3;
            else if(S=="DX") equipment.AccEffect=4;
            else if(S=="HU") equipment.AccEffect=5;
            else if(S=="CU") equipment.AccEffect=6;

            itemBoxes[R][C]=equipment;
        }
    }
}

int countHeroAcc(){
    int temp=0;
    for(int i=0; i<7; i++){
        temp+=hero.accessories[i].size();
    }
    return temp;
}

void moveHero(char dir){
    int nx=curX, ny=curY;
    if(dir=='L'){
        ny-=1;
    } else if(dir=='R'){
        ny+=1;
    } else if(dir=='U'){
        nx-=1;
    } else{
        nx+=1;
    }
    
    if(map[nx][ny]=='#' || nx<=0 || ny<=0 || nx>N || ny>M)  return;
    
    curX=nx, curY=ny; // hero 위치 변경
    return;
}

bool battle(Monster mon, bool isBoss){
    int heroAtk=hero.atk+(hero.weapon.type==-1 ? 0 : hero.weapon.atk);
    int heroDef=hero.def+(hero.armor.type==-1 ? 0 : hero.armor.def);
    
    bool isHunterActivated=isBoss && hero.accessories[5].size()==1;
    
    if(isHunterActivated){
        hero.hp=hero.maxHp;
    }
    
    int turn=1;
    while(true){
        // 홀수: 주인공 턴, 짝수: 몬스터 턴
        if(turn%2==1){
            if(turn==1 && hero.accessories[2].size()==1){
                if(hero.accessories[4].size()==1){
                    mon.hp-=max(1, heroAtk*3-mon.def);
                } else{
                    mon.hp-=max(1, heroAtk*2-mon.def);
                }
            } else{
                mon.hp-=max(1, heroAtk-mon.def);
            }
        } else{
            if(turn==2 && isHunterActivated){
                hero.hp-=0;
            } else{
                hero.hp-=max(1, mon.atk-heroDef);
            }
        }
        
        if(hero.hp<=0){
            hero.hp=0;
            curX=-1, curY=-1;
            return false;
        } else if(mon.hp<=0){
            return true;
        }
        
        turn++;
    }
}

void printResult(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(i==curX && j==curY) cout<<"@";
            else cout<<map[i][j];
        }
        cout<<"\n";
    }
    
    cout<<"Passed Turns : "<<turn<<"\n";
    cout<<"LV : "<<hero.level<<"\n";
    cout<<"HP : "<<hero.hp<<"/"<<hero.maxHp<<"\n";
    cout<<"ATT : "<<hero.atk<<"+"<<(hero.weapon.type==-1 ? 0 : hero.weapon.atk)<<"\n";
    cout<<"DEF : "<<hero.def<<"+"<<(hero.armor.type==-1 ? 0 : hero.armor.def)<<"\n";
    cout<<"EXP : "<<hero.xp<<"/"<<hero.maxXp<<"\n";
}

int main(){
    input();
    
    for(int comm=0; comm<S.length(); comm++){
        moveHero(S[comm]); // 주인공 이동
        turn++;
        
        if(map[curX][curY]=='.') continue; // 빈 칸이면 패스
        
        if(map[curX][curY]=='B'){
            // 아이템 상자 먹었을 때
            map[curX][curY]='.';
            Equipment curItem=itemBoxes[curX][curY];
            if(curItem.type==0){
                hero.weapon=curItem;
            } else if(curItem.type==1){
                hero.armor=curItem;
            } else{
                if(countHeroAcc()==4) continue;
                if(hero.accessories[curItem.AccEffect].size()!=0) continue;
                
                hero.accessories[curItem.AccEffect].push_back(curItem);
            }
        } else if(map[curX][curY]=='^'){
            // 가시 밟았을 때
            if(hero.accessories[4].size()==1){
                hero.hp-=1;
            } else{
                hero.hp-=5;
            }
            
            if(hero.hp<=0){
                if(hero.accessories[1].size()==0){
                    curX=-1, curY=-1;
                    printResult();
                    cout<<"YOU HAVE BEEN KILLED BY SPIKE TRAP..\n";
                    return 0;
                }
                
                // 아이템으로 부활
                hero.hp=hero.maxHp;
                hero.accessories[1].clear();
                curX=startX, curY=startY;
            }
            
        } else if(map[curX][curY]=='&' || map[curX][curY]=='M'){
            Monster mon=monsters[curX][curY];
            // 몬스터나 보스 만났을 때
            bool isHeroWon=battle(mon, map[curX][curY]=='M' ? true : false);
            
            // 주인공 죽었을 때
            if(!isHeroWon){
                if(hero.accessories[1].size()==1){
                    hero.hp=hero.maxHp;
                    hero.accessories[1].clear();
                    curX=startX, curY=startY;
                    
                    mon.hp=mon.maxHp;
                } else{
                    printResult();
                    cout<<"YOU HAVE BEEN KILLED BY "<<mon.name<<"..\n";
                    return 0;
                }
            } else{
                hero.gainXp(mon.xp);
                if(hero.accessories[0].size()==1){
                    hero.hp=min(hero.hp+3, hero.maxHp);
                }
                
                if(map[curX][curY]=='M'){
                    map[curX][curY]='.';
                    printResult();
                    cout<<"YOU WIN!\n";
                    return 0;
                }
                map[curX][curY]='.';
            }
        }
    }
    
    printResult();
    cout<<"Press any key to continue.\n";
    return 0;
}