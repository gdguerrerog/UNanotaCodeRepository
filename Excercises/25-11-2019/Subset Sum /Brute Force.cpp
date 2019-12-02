#include <iostream>

using namespace std;

long long solution, toSum, values[40];
int N;

void solve(long long cSum, int offset){
    for(int i = offset; i < N; i++){
        if(cSum + values[i] == toSum) solution++;
        solve(cSum + values[i], i + 1);
    }
}

int main(){
    while(!cin.eof()){
        cin >> N >> toSum;
        solution = 0;
        for(int i = 0; i < N; i++) cin >> values[i];
        solve(0, 0);
        cout << solution << endl;
    }
    return 0;
}

