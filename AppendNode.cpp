//
//  main.cpp
//  AppendNode
//
//  Created by Bharat Sarvan on 11/03/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

// Online C++ compiler to run C++ program online

#include <iostream>
#include <vector>
using namespace std;


struct elem {
    int val;
    struct elem *next;
    elem(int v):val(v), next(nullptr) {}
};


void appendNode(struct elem **tail, struct elem *node) {
    (*tail)->next = node;
    (*tail) = node;
}

int main() {
    
    struct elem *head = new elem(0);
    struct elem *curr = head;
    appendNode(&curr, new elem(1));
    appendNode(&curr, new elem(2));
    appendNode(&curr, new elem(3));
    
    struct elem *tmp = head;
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
    
    cout<<"End of the program"<<endl;

    return 0;
}
