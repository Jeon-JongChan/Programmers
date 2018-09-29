#include <string>
#include <vector>
#include <memory>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<unique_ptr<int[]>> arrVector;
    int priceSize = prices.size();
    int loopLen = 0;
    unique_ptr<unique_ptr<int>[]> arr = make_unique<unique_ptr<int>[]>(priceSize);

    for(int p = 0; p < priceSize; p++)
    {
        arr[p] = make_unique<int>(priceSize);
    }

    return answer;
}