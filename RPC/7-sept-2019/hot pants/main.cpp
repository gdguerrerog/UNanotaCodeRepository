#include <iostream>
#include <vector>

using namespace std;


const string WORSE = " are worse than ";



string * splitString(string s, string delimiter){
    string s1, s2;

    s1 = s.substr(0, s.find(delimiter));
    s2 = s.substr(s1.length() + delimiter.length(), s.length());

    string * exit = new string[2];
    exit[0] = s1;
    exit[1] = s2;

    return exit;


}

int main()
{
    int n ,m;
    cin >> n >> m;
    string input, a, b;
    for(int i=0; i<n ;i++){

    }
    return 0;
}
