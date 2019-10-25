#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int x, y, arrVal;
};

struct Edge{
    Node n1, n2;
    double d;
    bool operator < (Edge const& other){
        return d < other.d;
    }
};

vector<Node> DS;
vector<Edge> graph;
vector<Node> nodes;


Node findFather(Node node){
    if(DS[node.arrVal].arrVal == node.arrVal) return node;
    return DS[node.arrVal] = findFather(DS[node.arrVal]);
}

bool mergeFather(Node n1, Node n2){
    Node a = findFather(n1), b = findFather(n2);
    if(a.arrVal != b.arrVal){
        DS[a.arrVal] = b;
        return true;
    }
    return false;
}

int main()
{
    int T, S, P;
    cin >> T;
    while(T--){
        cin >> S >> P;
        DS.clear();
        graph.clear();
        nodes.clear();
        for(int i = 0; i < P; i++){
            Node cNode;
            cNode.arrVal = i;
            cin >> cNode.x >> cNode.y;
            for(Node node: nodes){
                Edge tmp;
                tmp.n1 = node;
                tmp.n2 = cNode;
                tmp.d = sqrt((cNode.x - node.x) * (cNode.x - node.x) + (cNode.y - node.y) * (cNode.y - node.y));
                graph.push_back(tmp);
            }
            nodes.push_back(cNode);
            DS.push_back(cNode);
        }

        sort(graph.begin(), graph.end());
        vector<double> sizes;

        for(Edge edge: graph) if(mergeFather(edge.n1,edge.n2)) sizes.push_back(edge.d);

        printf("%.2f\n", sizes[sizes.size() - S]);

    }
    return 0;
}
