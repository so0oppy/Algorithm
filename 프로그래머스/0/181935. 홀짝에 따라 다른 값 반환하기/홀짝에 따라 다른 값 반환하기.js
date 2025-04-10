function solution(n) {
    var answer = 0;
    
    for(var i=1; i<=n; i++)
    {
        if(n % 2 == 1){
            if(i&1) answer += i;
        }
        else{
            if(!(i&1)) answer += i*i;
        }
    }
    
    return answer;
}