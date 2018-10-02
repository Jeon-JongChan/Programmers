#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
/*
 * Complete the 'minMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY avg as parameter.
 */

int minMoves(vector<int> avg) {

    int first = 0, last = 0, answer = 0;
    int lastIdx = avg.size() - 1;
    if(1 <= avg.size() && avg.size() <= pow(10,5))
    {
        for(int idx = 0; idx < (avg.size() / 2); idx++)
        {
            if(avg[idx] == 1) first++;
            else if(avg[lastIdx - idx] != 1 && avg[lastIdx - idx] != 0) return 0;

            if(avg[lastIdx - idx] == 1) last++;
            else if(avg[lastIdx - idx] != 1 && avg[lastIdx - idx] != 0) return 0;
        }

        if(first == last)
        {
            first = 0;
            last = 0;
            for(int idx = 0; idx < (avg.size() / 2); idx++)
            {
                if(avg[idx] == 1) first++;
                else break;

                if(avg[lastIdx - idx] == 1) last++;
                break;
            }
        }

        if(first > last)
        {
            for(int idx = 0; idx < avg.size(); idx++)
            {
                if(avg[idx] == 1)
                {
                    for(int i = idx; i > 0; i--)
                    {
                        if(avg[i - 1] == 0 )
                        {
                            avg[i] = 0;
                            avg[i - 1] = 1;
                            answer++;
                        }
                        else break;
                    }
                }
            }
        }
        else
        {
            for(int idx = avg.size() - 1; idx >= 0; idx--)
            {
                if(avg[idx] == 1)
                {
                    for(int i = idx; i < avg.size() - 1; i++)
                    {
                        if(avg[i + 1] == 0 )
                        {
                            avg[i] = 0;
                            avg[i + 1] = 1;
                            answer++;
                        }
                        else break;
                    }
                }
            }
        }
    }

    return answer;

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string avg_count_temp;
    getline(cin, avg_count_temp);

    int avg_count = stoi(ltrim(rtrim(avg_count_temp)));

    vector<int> avg(avg_count);

    for (int i = 0; i < avg_count; i++) {
        string avg_item_temp;
        getline(cin, avg_item_temp);

        int avg_item = stoi(ltrim(rtrim(avg_item_temp)));

        avg[i] = avg_item;
    }

    int result = minMoves(avg);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}