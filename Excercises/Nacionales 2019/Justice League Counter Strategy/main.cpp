#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nVillains, nHeros, hIndex, vIndex, defeated;
    int * villains, * heros;
    while(true){
        cin >> nHeros >> nVillains;
        if(nVillains + nHeros == 0) return 0;

        heros = new int[nHeros];
        villains = new int[nVillains];


        for(int i = 0; i < nHeros; i++) cin >> heros[i];

        for(int i = 0; i < nVillains; i++) cin >> villains[i];

        sort(heros, heros + nHeros);
        sort(villains, villains + nVillains);
        hIndex = vIndex = 0;

        for(; hIndex < nHeros; hIndex++){
            if(heros[hIndex] > villains[vIndex]) vIndex++;
        }

        cout << vIndex << "\n";

    }

}
