#include <iostream>
#include <string>

using namespace std;

string next(string str){
    string exit = "";
    char current;
    int my_count;
    for(int i = 0; i <= 1000 && i < str.length();){
        current = str[i];
        i++;
        my_count = 1;
        for(; i <= 1000 && i < str.length() && str[i] == current; i++) my_count++;
        exit += std::to_string(my_count);
        exit += current;
    }

    return exit;
}

int main()
{
    string current;
    int iterations, pos;
    while(true){
        cin >> current >> iterations >> pos;
        if(current == "0" && iterations == 0 && pos == 0) return 0;
        for(int i = 0; i < iterations - 1; i++){
            current = next(current);
            //cout << current << endl;
        }

        cout << current[pos - 1] << "\n";
    }
}
