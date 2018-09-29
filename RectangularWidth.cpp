#include <iostream>
#include <vector>
using namespace std;

long long solution(vector<vector<int> > rectangles)
{
    long long answer = -1;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    
    for each(auto start in rectangles)
    {
        for each(auto value in rectangles)
        {
            if(start[0] <= value[0] && start[0] > value[2])
            {
                if(start[3] <= value[1] && start[3] > value[3])
                {
                    
                }
                else
                {

                }
            }
        }
    }
    

    return answer;
}