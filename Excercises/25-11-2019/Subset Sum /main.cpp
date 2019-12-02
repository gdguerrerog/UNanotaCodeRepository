#include <iostream>

using namespace std;

long long solution;
long long toSum;

void solve(long long * values, long long cSum, int offset, long long tSize){
    long long iSum;
    for(int i = offset; i < tSize; i++){
        iSum = cSum + values[i];
        if(iSum == toSum) solution++;
        solve(values, iSum, i + 1, tSize);
    }
}

int main()
{
    while(!cin.eof()){
        int N;
        long long T, tmp;
        cin >> N >> toSum;
        solution = 0;
        long long values[N];
        for(int i = 0; i < N; i++)
            cin >> values[i];
        solve(values, 0, 0, N);
        cout << solution << endl;
    }
    return 0;
}
