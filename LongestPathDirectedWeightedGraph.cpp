//Longest Path in Directed Acyclic Weighted Graph 
#include <iostream>
#include <vector>

using namespace std;


class Node {
	int v;
	int wt;
public:
	Node(int V, int weight):v(V), wt(weight) {}
};

list<Node> *adj;

void GraphInit(int V) {
	adj = new list<Node>[V];
}

void AddEdge(int u, int v) {

}
