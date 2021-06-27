//
//  main.cpp
//  MinimumSwap
//
//  Created by Bharat Sarvan on 24/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minimumSwaps(vector<int> A) {
    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    int swap_count = 0;
    
    unordered_map<int, int> index_map;
    for (int i = 0; i < A.size(); i++) {
        index_map.emplace(A[i], i);
    }
    
    for (int i = 0; i < A.size(); i++) {
        int correct_value = sorted_A[i];
        if (A[i] != correct_value) {
            int to_swap_index = index_map[correct_value];
            cout<<"Swapping "<<A[i]<<" and "<<A[to_swap_index]<<endl;
            swap(A[i], A[to_swap_index]);
            index_map[A[to_swap_index]] = to_swap_index;
            index_map[correct_value] = i;
            
            swap_count++;
            
        }
    }
    
    return swap_count;
    
}

int main(int argc, const char * argv[]) {
    cout<<"Algorithm  to find the Minimum Swaps required to sort the elements"<<endl;
    
//    vector<int> A = {5,3,1,2,4};
    vector<int> A = {1, 5, 4, 2, 3};
    int result = minimumSwaps(A);
    cout<<result<<endl;
    
    return 0;
}
