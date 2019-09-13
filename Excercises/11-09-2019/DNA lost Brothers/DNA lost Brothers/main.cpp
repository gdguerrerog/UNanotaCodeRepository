#include <iostream>
#include <math.h>

using namespace std;

void solve(string DNA1, string DNA2){
    int n = DNA1.length();
    int best1[n + 1], best2[n + 1];
    int * current = best1, * past = best2, *tmp;
    int minAcepted = ceil(n*0.99);

    for(int i = 0; i <= n; i++) best2[i] = 0;

    int register j;
    for(int i = 1; i <= n; i++){
        for(j = 1; j <= n; j++) {
            if(DNA1[i - 1] == DNA2[j - 1]) current[j] = past[j - 1] + 1;
            else current[j] = max(current[j - 1], past[j]);
        }

        if(n - i + 1 < minAcepted - current[n]) break; // No brothers

        tmp = past;
        past = current;
        current = tmp;
        s
    }
    if(current[n] >= minAcepted)  cout << "Long lost brothers D:\n";
    else cout << "Not brothers :(\n";
}

void consoleInput(){
    string DNA1, DNA2;
    cin >> DNA1 >> DNA2;
    solve(DNA1, DNA2);
}

void testInput(){
    //1e5 B: 53.875
    //1e5 N: 8.160
    //1e4 B: 0.562
    //1e4 N: 0.098
    string DNA1 = "", DNA2 = "";

    for(int i = 0; i < 1e3; i++){
        DNA1 += "A";
        DNA2 += "A";
    }
    //*
    for(int i = 0; i < 1e4 - 1e3; i++){
        DNA1 += "A";
        DNA2 += "B";

    }
    //*/

    //cout << "Starting solve\n";
    solve(DNA1, DNA2);
}
int main()
{
    consoleInput();
    //testInput();

    return 0;
}
