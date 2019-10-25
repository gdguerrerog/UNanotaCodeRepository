#include <iostream>

using namespace std;

struct People{
    int id;
    vector<int> enemies;
};

People * ids;
int n;
bool first = true;

int findFather(int id){
    if(ids[id].id == id) return id;
    ids[id].id = findFather(ids[id].id);
    return ids[id].id;
}

void setFriends(int x, int y){
    int yF = findFather(y), xF = findFather(x);
    for(int enemy: ids[xF].enemies) if(enemy == yF) {
        cout << "-1\n";
        return;
    }
    int yF = findFather(y), xF = findFather(x);
    ids[yF] = xF;
}

void setEnemies(int x, int y){
    int yF = findFather(y), xF = findFather(x);
    if(yF == xF){
        cout << "-1\n";
        return;
    }


}

void areFriends(int x, int y){
    if(findFather(x) == findFather(y)) cout << "1\n";
    else cout << "0\n";
}

void areEnemies(int x, int y){

}

int main()
{
    int c, x, y;
    cin >> n;
    ids = new int[n + 2];
    for(int i = 0; i < n + 2; i++)  ids[i].id = i;

    while(true){
        cin >> c >> x >> y;
        switch(c){
            case 0: return 0;
            case 1: setFriends(x, y); break;
            case 2: setEnemies(x, y); break;
            case 3: areFriends(x, y); break;
            case 4: areEnemies(x, y); break;
        }
    }

}
