#include <iostream>

using namespace std;

int main()
{
    int number;

    cin >> number;
    int total1 = 0;
    for(int i = 0; i < 32; i++) if(((1 << i) & number ) != 0) total1++;

    cout << total1 << "\n";
    return 0;
}
