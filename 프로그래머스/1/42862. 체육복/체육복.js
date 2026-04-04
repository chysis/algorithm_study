function solution(n, lost, reserve) {
    let ans=0;
    let l=lost, r=reserve;
    
    for(let i=1; i<=n; i++){
        // i가 잃어버린 경우
        if(l.includes(i)){
            // 여벌 체육복을 가져온 학생이 도난당한 경우
            if(r.includes(i)){
                r=r.filter(item=>item !== i);
                l=l.filter(item=>item !== i);
                ans++;
            }
        }
        else{
            if(!lost.includes(i)) ans++; // 원래 도난당하지 않아야만 카운트
            if(r.includes(i)){
                // 앞 사람에게 빌려줄 수 있는지 확인
                if(i-1>=1 && l.includes(i-1)){
                    r=r.filter(item=>item !== i-1);
                    l=l.filter(item=>item !== i-1);
                    ans++;
                }
                // 뒷 사람에게 빌려줄 수 있는지 확인
                else if(i+1<=n && l.includes(i+1)){
                    r=r.filter(item=>item !== i+1);
                    l=l.filter(item=>item !== i+1);
                    ans++;
                }
            }
        }
    }
    
    return ans;
}