// 2중 for문으로 완전 탐색 -> O(N^2) 시간 초과
// 문자열 정렬 후(사전순으로 정렬됨) N번째가 N+1번째에 포함되는지만 확인
function solution(phone_book) {
    phone_book = phone_book.sort((a, b) => {
      if (a < b) return -1;
      if (a > b) return 1;
      return 0;
    });
    for(let i=1; i<phone_book.length; i++){
        if(phone_book[i].startsWith(phone_book[i-1])) return false;
    }
    
    return true;
}