#include <iostream>

using namespace std;

int main()
{
    int cases, a, c, n;
    string start;
    string A = "ALICE\n";
    string C = "CARL\n";
    bool tmp;
    cin >> cases;
    for(; cases > 0; cases--){
        cin >> n >> a >> c >> start;
        tmp = start == "Alice";

        if(a + c == n * n){
            if(tmp) cout << C;
            else cout << A;
            break;
        }

        if (a != c) {
            if(tmp) cout << A;
            else cout << C;
        }else {
            if(tmp) cout << C;
            else cout << A;
        }
    }
    return 0;
}
