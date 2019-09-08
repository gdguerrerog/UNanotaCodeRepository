#include <iostream>

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    unsigned short players[n];
    for(int i = 0; i < n;i++) cin >> players[i];

    unsigned long long currentMax = 0;
    vector<unsigned long long> optimal(players,players + n);


    for(int i = m; i < n;i++){
        if(optimal[i] > currentMax) currentMax = optimal[i];
        for(int j = 0; j < m && i + m + j < n; j++){
            if(players[i + m + j] + optimal[i] > optimal[i + m + j]) optimal[i + m + j] = players[i + m + j] + optimal[i];
        }
        /*cout << "Optimal:\n";
        for(int k = 0; k < n;k++) cout << optimal[k] << " " ;
        cout << "\nPlayers:\n";
        for(int k = 0; k < n;k++) cout << players[k] << " ";
        cout << "\n";*/
    }

    cout << currentMax <<"\n";
    return 0;
}
