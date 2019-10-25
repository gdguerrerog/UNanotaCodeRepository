#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int arrVal, val;

    bool operator !=(Node const& other){
        return arrVal != other.arrVal;
    }

    bool operator ==(Node const& other){
        return arrVal == other.arrVal;
    }
};

struct Edge{
    Node p1, p2;
    int c;
    bool operator < (Edge const& other){
        return c < other.c;
    }
};



Node findFather(Node node, vector<Node> DS){
    if(DS[node.arrVal] == node) return node;
    return DS[node.arrVal] = findFather(DS[node.arrVal], DS);
}

void mergeDS(Node node1, Node node2, vector<Node> DS){
    Node a = findFather(node1, DS), b = findFather(node2, DS);
    if(a != b) DS[a.arrVal] = b;
}


int calcCost(int a, int b){
    int cCost = abs((a - b) % 10);
    cCost += abs((a/10 - b/10) % 10);
    cCost += abs((a/100 - b/100) % 10);
    cCost += abs((a/1000 - b/1000) % 10);
    return cCost;
}

int main()
{
    int T, N, cost, minTo0, input;
    cin >> T;
    vector<Node> DS;
    vector<Edge> graph;
    vector<Node> nodes;

    while(T--){
        cost = 0;
        minTo0 = 25;
        cin >> N;
        DS.resize(N);
        nodes.resize(N);

        for(int i = 0; i < N; i++) {
            cin >> input;
            Node cNode;
            cNode.arrVal = i;
            cNode.val = input;
            DS[i] = cNode;
            minTo0 = min(minTo0, calcCost(cNode.val, 0));
            for(Node node : nodes){
                Edge tmp;
                tmp.c = calcCost(node.val, cNode.val);
                tmp.p1 = node;
                tmp.p2 = cNode;
                graph.push_back(tmp);
            }

            nodes.push_back(cNode);

        }


    }
}
