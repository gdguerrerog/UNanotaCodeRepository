#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    string input;
    int len, minD, r, d;
    while(true){
        cin >> len;
        if(len == 0) return 0;
        cin >> input;

        minD = len;
        r = -1;
        d = -1;
        for(int i = 0; i < len; i++){
            if(input[i]=='Z'){
                minD = 0;
                break;
            }
            if(input[i]=='R') r=i;
            if(input[i]=='D') d=i;
            if(r != -1 && d != -1 && abs(r - d) < minD) minD = abs(r - d);
        }

        cout << minD << "\n";
    }




    return 0;
}
