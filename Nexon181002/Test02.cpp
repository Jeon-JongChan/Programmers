#include <bits/stdc++.h>

using namespace std;
// Complete the maxStep function below.
int maxStep(int n, int k) {
    int result = 0;
    for(int i = 1; i <= n; i++)
    {
        if(result + i != k)
        {
            result += i;
        }
        else
        {
            if(i - 1 > 0) result += (i - 1);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int res = maxStep(n, k);

    fout << res << "\n";

    fout.close();

    return 0;
}