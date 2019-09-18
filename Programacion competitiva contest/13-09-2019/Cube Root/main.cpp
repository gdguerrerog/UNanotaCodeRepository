#include <iostream>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

int main()
{
    double root;
    string toPrint;

    int t, n;
    cin >> t;
    int j, afterDot;
    bool dot;
    for(int i = 0;i < t; i++){
        cin >> n;
        root = cbrt(n);
        std::ostringstream stream;
        stream << root;
        toPrint = stream.str();
        dot = false;
        for(j = 0, afterDot = -1; j < toPrint.length() && afterDot < 4; j++){
            if(toPrint[j] == '.') dot = true;
            cout << toPrint[j];
            if(dot) afterDot++;
        }

        if(!dot){
            afterDot = 0;
            cout << '.';
        }

        for(;afterDot < 4 ;afterDot++) cout << '0';
        cout << "\n";

    }

    return 0;
}
