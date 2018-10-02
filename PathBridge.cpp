#include <string>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truckIdx = 0;
    deque<int> onTheBridge;
    deque<int> timeQueue;

    if(1 <= bridge_length && bridge_length <= 10000 && 1 <= weight && weight <= 10000 && 1 <= truck_weights.size() && truck_weights.size() <= 10000)
    {
        while(truck_weights.size() > truckIdx || onTheBridge.size() > 0)
        {
            for(int i = 0; i < bridge_length; i++)
            {
                answer++;
                if(truck_weights.size() > truckIdx)
                {
                    if(weight - truck_weights.back() >= 0)
                    {
                        onTheBridge.push_back(truck_weights[truckIdx++]);
                        timeQueue.push_back(bridge_length);
                        weight -= onTheBridge.back();
                    }
                }
                cout << answer << " : " << timeQueue[0] << " : " << onTheBridge.back() << endl;
                //현재 다리위에 있는 트럭들의 위치를 하나씩 줄인다.
                for(int q  = 0; q < timeQueue.size(); q++)
                {
                    timeQueue[q]--;
                    if(timeQueue[q] == 0) //도착했을 경우 빼준다.
                    {
                        weight += onTheBridge.front(); //제한무게 원상 복구
                        timeQueue.pop_front();
                        onTheBridge.pop_front();
                        q--;
                    }
                }
                if(timeQueue.size() == 0 && truckIdx == truck_weights.size()) break;
                if(timeQueue[0] == 0) break;
            }
        }
        answer++;
    }
    return answer;
}