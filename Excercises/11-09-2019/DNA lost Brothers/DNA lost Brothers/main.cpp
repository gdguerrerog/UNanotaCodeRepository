#include <iostream>

using namespace std;

void solve(string DNA1, string DNA2){
    int n = DNA1.length();
    int best1[n + 1], best2[n + 1];
    int * current, * past;
    bool used1 = true;

    for(int i = 0; i <= n; i++) best1[i] = best2[i] = 0;

    for(int i = 1, j; i <= n; i++){
        if(used1){
            current = best2;
            past = best1;
        }else{
            current = best1;
            past = best2;
        }
        for(j = 1; j <= n; j++) {

            //cout << current[j - 1] << "-"<<past[j-1]<<"-";
            if(DNA1[i - 1] == DNA2[j - 1]) current[j] = past[j - 1] + 1;
            else current[j] = max(current[j - 1], past[j]);
            //cout << current[j] << "-"<<past[j]<< "\t";
        }
        used1 = !used1;
        //cout << endl;
    }

    //cout << (current[n]) << " " << (n*0.99) << " " <<  (current[n] >= n*0.99) << " " << n <<endl;
    if(current[n] >= n*0.99) cout << "Long lost brothers D:\n";
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
