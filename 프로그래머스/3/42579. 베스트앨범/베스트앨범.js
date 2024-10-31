function solution(genres, plays) {
    const obj = {};
    const totalPlays = {};
    genres.forEach((genre, i)=>{
        genre in obj ? obj[genre].push({idx: i, num: plays[i]}) : obj[genre]=[{idx: i, num: plays[i]}];
        genre in totalPlays ? totalPlays[genre]+=plays[i] : totalPlays[genre]=plays[i];
    });
    
    const keys = Object.keys(obj).sort((a, b)=>totalPlays[b]-totalPlays[a]);
    keys.forEach(key=>obj[key].sort((a, b)=>{
        if(a.num!==b.num) return b.num-a.num;
        else return a.idx-b.idx;
    }))
    
    const ans=[];

    keys.forEach(key=>{
        obj[key].length>=2 ? ans.push(obj[key][0].idx, obj[key][1].idx) : ans.push(obj[key][0].idx);
    })
    
    return ans;
}