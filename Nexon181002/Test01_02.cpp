#include <bits/stdc++.h>
#include <cmath>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pthFactor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER n
 *  2. LONG_INTEGER p
 */

long pthFactor(long n, long p) {

    vector<long> primeNum;
    if( (1 <= n && n <= pow(10,15)) && (1 <= p && p <= pow(10,9)) )
    {
        long sqrtNum = (long)sqrtl(n);
        for(long i = 1; i <= sqrtNum ; i++)
        {
            if(n % i == 0) 
            {
                primeNum.push_back(i);
                cout << i << " sqrtNum : " << sqrtNum << endl; 
            }
        }
        long vectorSize = primeNum.size();

        for(long i = vectorSize - 1; i >= 0; i--)
        {
            if(primeNum[i] != sqrtNum) primeNum.push_back(n / primeNum[i]);
        }
    }

    if(primeNum.size() < p) 
    {
        return 0;
    }
    else
    {
        return primeNum[p-1];
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    long p = stol(ltrim(rtrim(p_temp)));

    long result = pthFactor(n, p);

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