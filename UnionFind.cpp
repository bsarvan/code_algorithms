#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10

vector<int> parent(SIZE, -1);


int findParent(int u) {
	if (parent[u] == -1) {
		return u;
	} else 
		return parent[parent[u]];
}

void Union(int u, int v) {
	int U = findParent(u);
	int V = findParent(v);

	if (U != V) {
		parent[V] = U;
	}
}


void printParent() {

	cout<<"The Union Parent Array is - "<<endl;

	for (int i = 0; i < SIZE; i++) {
		cout<<i<<" ";
	}
	cout<<endl;
	for (auto p : parent) {
		cout<<p<<" ";
	}

	cout<<endl;
}

int main() {
	cout<<"Union Find Algorithm"<<endl;


	printParent();
	Union(0, 1);
	Union(2, 4);

	printParent();
	return 0;

}