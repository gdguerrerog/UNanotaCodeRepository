#include <iostream>

using namespace std;
unsigned long long one = 1;

int countBits(unsigned long long number){
    int totalCount = 0;

    for(int i = 0; i < 64; i++) if(((one << i) & number) != 0) totalCount++;
    return totalCount;
}

int main()
{
    int n, maxBits, tmpBits;
    cin >> n;
    unsigned long long l, r, x, xVal;
    for(;n > 0; n--){
        cin >> l >> r;
        x = l;
        maxBits = 0;
        xVal = 0;
        for(int i = 0; x <= r;i++){
            tmpBits = countBits(x);
            if(tmpBits > maxBits) {
                maxBits = tmpBits;
                xVal = x;
            }
            x = (x | one << i);
        }

        cout << xVal << "\n";

    }
    //cout << countBits(((unsigned long long)1 << 63) - 1) << "  " << (((unsigned long long)1 << 63) - 1);
    return 0;
}
