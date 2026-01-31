// [93, 30, 55] / [1, 30, 5] -> 완료 시각 배열은 [7, 3, 9]
function solution(progresses, speeds) {
    const arr=[], ans=[];
    for(let i=0; i<progresses.length; i++){
        const remain=100-progresses[i];
        if(remain%speeds[i]===0) arr.push(parseInt(remain/speeds[i]));
        else arr.push(parseInt(remain/speeds[i]) + 1);
    }
    
    let waiting=0;
    for(let i=1; i<arr.length; i++){
        if(arr[i]>arr[waiting]){
            ans.push(i-waiting);
            waiting=i;
        }
    }
    ans.push(progresses.length-waiting);
    return ans;
}