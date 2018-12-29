#import math

def solution(pelindrome):
    pelindrome = "".join(pelindrome)
    pelindromeLen = len(pelindrome)
    maxPelindromeLen = 0
    checkStatus = True

    if not pelindrome.islower() and not pelindrome.isalpha() and pelindrome.isspace():
        return 0

    if pelindromeLen > 1 and pelindromeLen <= 2500 :
        for i in range(pelindromeLen - 1,0,-1) : #검사해야되는 개수를 증가. i 는 검사 char 수 - 1 .
            #stackLen = math.ceil(i / 2)
            for j in range(0,pelindromeLen - i): #검사 char 수에 따라 회문 검사 횟수가 달라진다. j는 검사시작할 문자의 인덱스 수와 같다.
                temp = 0
                for k in range(j,j+(i + 1)):
                        
                    if pelindrome[k] != pelindrome[j + i - temp]:
                        checkStatus = False
                        break
                    temp += 1

                if checkStatus:
                    maxPelindromeLen = i+1
                    return maxPelindromeLen
                checkStatus = True
    elif pelindromeLen == 1 :
        return 1
    elif pelindromeLen < 1:
        return 0
        

    
s = input("input a pelindrome string : ")       
print(solution(s))      



