#include <iostream>
#include <stdlib.h>

using namespace std;

int validConf(int queries[][2], int value, int a, int b){
    int trustIn2;
    for(int i = 0; i < b; i++){
        if((value & (1 << (queries[i][0] - 1))) != 0){
            trustIn2 = value & (1 << (abs(queries[i][1]) - 1));
            if((queries[i][1] > 0) && (trustIn2 == 0)) return -1;
            if((queries[i][1] < 0) && (trustIn2 != 0)) return -1;
        }
    }

    int maxAg = 0;
    for(int i = 0; i < a; i++){
        if((value & (1 << i)) != 0) maxAg++;
    }
    return maxAg;
}

int main()
{
    int a, b, maxConfiable, totalAgents;
    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0) return 0;
        int queries[b][2];
        maxConfiable = 0;
        for(int i = 0; i < b; i++){
            cin >> queries[i][0];
            cin >> queries[i][1];
        }

        for(int i = (1 << a) - 1; i >= 0 ; i--){
            totalAgents = validConf(queries, i, a, b);
            if(totalAgents > maxConfiable) maxConfiable = totalAgents;
        }

        cout << maxConfiable << "\n";

    }
}
