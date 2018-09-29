#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> vec, answer;
    bool start = true; //강의 새로운 물길을 만들기 위한 변수
    cin >> n;
    string line;
    getline(cin, line);  // drop a newline traling n
    while (n-- > 0) {
        stringstream ss(line);
        for (int fork; !(ss >> fork).fail(); ) {  // read forks from a note
            // @todo Write your code here.
            bool trigger = false;
            if(start)
            {
                vec.push_back(fork);
            }
            else
            {
                for(int index = 0; index < vec.size();index++)
                {
                    if(fork <= vec[vec.size()-1])
                    {
                        if(fork == vec[index])
                        {
                            trigger = true;
                        }
                        if(trigger && fork != vec[index])
                        {
                            cout << -1 << endl;
                            return 0;
                        }
                    }
                    else
                    {
                        if(trigger) vec.push_back(fork);
                        else{
                            answer.push_back(vec[vec.size()-1]);
                            vec.clear();
                            vec.push_back(fork);
                            start = true;
                        }
                    }
                }
            }
        }
        if(start)start = false;
        // @todo Write your code here.
    }
    answer.push_back(vec[vec.size()-1]);
    sort(answer.begin(),answer.end());
    // @todo Write your code here.
    return 0;
}