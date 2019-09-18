#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unsigned long l, r, x, i;
    for(;n > 0; n--){
        cin >> l >> r;
        x = 0xFFFFFFFF;
        for(i = 0xFFFFFFFF; x >= l; x = x & i, i = (i >> 1)) if(x <= r) break;

        cout << x << "\n";
    }
    return 0;
}
