//
//  main.cpp
//  BuildOrder
//
//  Created by bsarvan on 16/02/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    vector<bool> in;
    
public:
    Graph(int n) {
        V = n;
        adj = new list<int>[n];
        in.resize(V, false);
    }
    
    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
        in[v] = true;
    }
    
    void printGraph() {
        
        for (int i=0;i<V;i++) {
            cout<<i<<" : ";
            for (auto it:adj[i]) {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    int numVertices() {
        return V;
    }
    
    bool hasIncomingEdges(int u) {
        for (int i=0;i<V;i++) {
            for (auto it:adj[i]) {
                if (it == u){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasIncomingEdge(int u) {
        return in[u];
    }
};

int main(int argc, const char * argv[]) {
    Graph graph(5);
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    
    graph.printGraph();
    
    cout<<(graph.hasIncomingEdges(3)?"True":"False")<<endl;

    cout<<(graph.hasIncomingEdge(3)?"Yes":"No")<<endl;
    
    return 0;
}
