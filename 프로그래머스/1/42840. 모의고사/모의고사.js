function solution(answers) {
    const ans1=new Array(Math.ceil(answers.length/5)).fill([1, 2, 3, 4, 5]).flat();
    const ans2=new Array(Math.ceil(answers.length/8)).fill([2, 1, 2, 3, 2, 4, 2, 5]).flat();
    const ans3=new Array(Math.ceil(answers.length/8)).fill([3, 3, 1, 1, 2, 2, 4, 4, 5, 5]).flat();
    
    let score=[0, 0, 0];
    
    score[0]=answers.filter((ans, i)=>ans===ans1[i]).length;
    score[1]=answers.filter((ans, i)=>ans===ans2[i]).length;
    score[2]=answers.filter((ans, i)=>ans===ans3[i]).length;
    
    const maxScore=Math.max(...score);
    return score.map((s, i)=>s===maxScore ? i+1 : null).filter(s=>s!==null);
}