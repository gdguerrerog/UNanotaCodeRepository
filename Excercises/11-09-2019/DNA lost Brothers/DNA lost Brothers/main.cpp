#include <iostream>

using namespace std;

void solve(string DNA1, string DNA2){
    int n = DNA1.length();
    int best[n + 1];

    for(int i = 0; i <= n; i++) best[i] = 0;

    for(int i = 1, j; i <= n; i++){
        for(j = 1; j <= n; j++) {
            //cout << best[j] << "-";
            if(DNA1[i - 1] == DNA2[j - 1]) best[j] = best[j - 1] + 1;
            else if(best[j - 1] > best[j]) best[j] = best[j - 1];
            //cout << best[j] << "\t";
        }
        //cout << endl;
    }

    //cout << (best[n]) << " " << (n*0.99) << " " <<  (best[n] >= n*0.99) << " " << n <<endl;
    if(best[n] >= n*0.99) cout << "Long lost brothers D:\n";
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
    DNA2 += "C";
    DNA1 += "C";
    DNA2 += "A";
    solve(DNA1, DNA2);
}
int main()
{
    consoleInput();
    //testInput();
    return 0;
}
