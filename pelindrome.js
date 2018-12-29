function solution(pelindrome){
    let pelindromeLen = pelindrome.length;
    let maxPelindromeLen = 0;
    let checkStatus = true;
    
    if (pelindromeLen > 1 && pelindromeLen <= 2500) 
    {
        for(let i = pelindromeLen - 1;i > 0; i--)//검사해야되는 개수를 증가. i 는 검사 char 수 - 1 .
        {  
            //stackLen = math.ceil(i / 2)
            console.log("여기서 시작" + i);
            let temp = 0;
            for(let j = 0; j < pelindromeLen - i; j++) //검사 char 수에 따라 회문 검사 횟수가 달라진다. j는 검사시작할 문자의 인덱스 수와 같다.
            {
                temp = 0;
                for(let k = j;k < j+(i + 1); k++)
                {
                    console.log("여기서 비교" + pelindrome[k] + "  " + pelindrome[j + i - temp]);
                    if (pelindrome[k] != pelindrome[j + i - temp])
                    {
                        checkStatus = false;
                        break;
                    }
                    temp += 1;
                }
                if (checkStatus == true)
                {
                    console.log("이거실행");
                    maxPelindromeLen = i+1;
                    return maxPelindromeLen;
                }
                checkStatus = true;
            }
        }
    }
    else if(pelindromeLen == 1)
        return 1;
    else (pelindromeLen == 0)
        return 0;

}  
