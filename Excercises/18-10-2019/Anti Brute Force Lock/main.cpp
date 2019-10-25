#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Edge{
    int p1, p2, c;
    bool operator < (Edge const& other){
        return c < other.c;
    }
};


int calcCost(int a, int b){
    int cCost = abs((a - b) % 10);
    cCost += abs((a/10 - b/10) % 10);
    cCost += abs((a/100 - b/100) % 10);
    cCost += abs((a/1000 - b/1000) % 10);
    return cCost;
}

int main()
{
    int T, N, cost, cCount, int;
    cin >> T;
    vector<int> DS;
    vector<Edge> graph;
    Edge tmp;
    map<int, int> keys;
    vector<int> nodes;

    while(T--){
        cost = cCount = 0;
        cin >> N;
        DS.resize(N);
        nodes.resize(N);
        keys.clear();

        for(int i = 0; i < N; i++)  DS[i] = i;
        for(int i = 0; i < N; i++) {
            cin >> input;
            for(int node : nodes){

            }
        }


    }
}
