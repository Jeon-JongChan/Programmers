#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    char tempChar = NULL;
    vector<char> barStack;

    for(auto& c : arrangement)
    {
        if(c == '(')
        {
            barStack.push_back(c);
        }
        else if(c == ')' && tempChar == '(')
        {
            barStack.pop_back();
            answer += barStack.size();
        }
        else
        {
            barStack.pop_back();
            answer++;
        }
        tempChar = c;
    }
    return answer;
}