function solution(clothes) {
    const closet={};
    for(let i=0; i<clothes.length; i++){
        if(!Object.keys(closet).some(key=>key===clothes[i][1])){
            closet[clothes[i][1]]=new Array();
            closet[clothes[i][1]].push(clothes[i][0]);
        }else{
            closet[clothes[i][1]].push(clothes[i][0]);
        }
    }
    console.log(closet);
    
    let ans=1;
    for(const key of Object.keys(closet)){
        ans*=closet[key].length+1;
    }
    return ans-1;
}