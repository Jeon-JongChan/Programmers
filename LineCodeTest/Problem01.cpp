#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int main() {
    string line;
    int balance = 20000;
    getline(cin, line);
    stringstream ss(line);
    for (int distance; !(ss >> distance).fail(); ) {
        // @todo Write your code here.
        if(distance < 4 && distance > 178) break;
        else{
            int quotient = 0;
            if(distance > 40)
            {
                distance -= 40;
                quotient = distance / 8;
                if(distance % 8 != 0) quotient++;
                quotient *= 80;
            }

            if(balance - (720 + quotient) < 0)
            {
                break;
            }
            else balance -= (720 + quotient);
        }
    }
    // @todo Write your code here.
    cout << balance <<endl;
    return 0;
}
