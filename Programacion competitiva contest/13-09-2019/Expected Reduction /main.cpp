#include <iostream>
#include <stdlib.h>

using namespace std;


int mcd(int n1, int n2){
    int maxN = max(n1, n2);
    int minN = min(n1, n2);
    int mod;

    while(minN != 0){
        mod = maxN % minN;
        maxN = minN;
        minN = mod;
    }

    return maxN;
}


int main()
{
    int n;
    cin >> n;
    int numerator;
    if(n % 2 == 0) numerator = n/2 - 1;
    else numerator = n/2;

    for(;numerator != 1 && mcd(n - numerator, numerator) != 1; numerator--);

    cout << numerator << " " << (n - numerator) << "\n";

    return 0;
}
