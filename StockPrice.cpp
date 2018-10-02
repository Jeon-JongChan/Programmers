#include <string>
#include <vector>
#include <memory>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int loopLen = 0;

    for(int p = 0; p < prices.size(); p++)
    {
        answer.push_back(0);
        int answerEndIndex = answer.size() - 1;
        for(int i = p + 1 ; i < prices.size(); i++)
        {
            answer[answerEndIndex]++;
            if(prices[p] > prices[i]) break;
        }
    }

    return answer;
}