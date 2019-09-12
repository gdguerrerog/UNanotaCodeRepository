#include <iostream>

using namespace std;

int main()
{
    string input;
    cin >> input;

    if('0' > input[0] || '9' < input[0]) {
        cout << -1 << "\n";
        return 0;
    }

    for(int i = 0; i < input.length() && '0' <= input[i] && input[i] <= '9'; i++) cout << input[i];
    cout << "\n";

    return 0;
}
