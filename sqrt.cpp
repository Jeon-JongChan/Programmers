#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    if(n > 0 && n <= 50000000000000)
    {
        float sqrt_f = sqrt(n);
        int sqrt_i = (int)sqrt_f;

        if(sqrt_f == sqrt_i)
        {
            sqrt_i++;
            answer = pow(sqrt_i,2);
            return answer;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}