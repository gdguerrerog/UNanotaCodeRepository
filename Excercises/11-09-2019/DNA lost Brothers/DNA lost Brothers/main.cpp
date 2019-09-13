#include <iostream>

using namespace std;

void solve(string DNA1, string DNA2){
    int n = DNA1.length();
    int matrix[n + 1][n + 1];

    for(int i = 0, j; i < n + 1; i++){
        for(j = 0; j < n + 1;j++) {
            if(i == 0 || j == 0) matrix[i][j] = 0;
            else if(DNA1[i - 1] == DNA2[j - 1]) matrix[i][j] = matrix[i - 1][j - 1] + 1;
            else matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }

    //cout << (matrix[n][n]) << " " << (n*0.99) << " " <<  (matrix[n][n] >= n*0.99) << " " << n <<endl;
    if(matrix[n][n]*1.0 >= n*0.99) cout << "Long lost brothers D:\n";
    else cout << "Not brothers :(\n";
}

void consoleInput(){
    string DNA1, DNA2;
    cin >> DNA1 >> DNA2;
    solve(DNA1, DNA2);
}

void testInput(){
    string DNA1 = "", DNA2 = "";
    for(int i = 0; i < 98; i++){
        DNA1 += "A";
        DNA2 += "A";
    }
    DNA1 += "A";
    DNA2 += "B";
    DNA1 += "A";
    DNA2 += "B";
    solve(DNA1, DNA2);
}
int main()
{
    consoleInput();
    //testInput();
    return 0;
}
