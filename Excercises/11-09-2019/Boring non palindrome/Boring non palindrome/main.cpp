#include <iostream>

using namespace std;

bool verifyPalindrome(string str, int len, int startIndex){
    int total = (len - startIndex)/2;
    for(int i = 0; i < total; i++){
        if(str[i + startIndex] != str[len - i - 1]) return false;
    }
    return true;
}

int main()
{
    string input;

    //for(int i = 0; i < 4999; i++) input += 'a';
    //input += 'b';
    cin >> input;
    int len = input.length(), firstIndexPalindrome = len - 1;
    char last = input[len - 1];
    for(int i = 0; i < len; i++){
        if(input[i] == last && verifyPalindrome(input, len, i)){
            firstIndexPalindrome = i - 1;
            break;
        }
    }

    cout << input;
    for(int i = firstIndexPalindrome; i >= 0; i--) cout << input[i];
    cout << "\n";

    return 0;
}
