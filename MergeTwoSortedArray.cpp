//
//  main.cpp
//  MergeTwoSortedArray
//
//  Created by bsarvan on 30/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


// Algorithm to merge two sorted arrays with no handling for duplicates. Merged array may have duplicates
void merge(int a[], int b[], int lastA, int lastB) {
    int indexA = lastA - 1;/* Index of last element in array a*/
    int indexB = lastB - 1;/* Index of last element in array b*/
    int indexMerged = lastB + lastA - 1;/* end of merged array*/
    /* Merge a and b, starting from the last element in each*/
    while (indexB >= 0) {
        /* endofais>thanendofb*/
        if (indexA >= 0 && a[indexA] > b[indexB]) {
            a[indexMerged] = a[indexA]; //
            indexA--;
        } else {
            a[indexMerged] = b[indexB]; //
            indexB--;
        }
        indexMerged--; // move indices
    }
    return;
}


vector<int> merge_with_no_duplicates(vector<int> a, vector<int> b) {

    vector<int> result;
    
    int i = 0;
    int j = 0;
    while(i < a.size() and j < b.size()) {
        if ((a[i] < b[j]) or (a[i] != a[i-1])) {
            result.emplace_back(a[i]);
            i++;
        } else if ((b[j] < a[i]) or (b[j] != b[j-1])) {
            result.emplace_back(b[j]);
            j++;
        }
    }
    
    return result;
    
}

int main(int argc, const char * argv[]) {
    cout<<"Program to merge two sorted array "<<endl;
    int A[15] = {2,3,4,6,8};
    int B[] = {1,3,3,5,7};
    
    vector<int> Av = {2,3,4,6,8};
    vector<int> Bv = {1,3,3,5,7};
    
    merge(A,B,4,4);
    
    for(int i=0;i<8;i++){
        cout<<A[i]<<" ";
    }
    
    cout<<endl;
    
    vector<int> res = merge_with_no_duplicates(Av, Bv);
    
    cout<<"Merged vector with no duplicates"<<endl;
    for (auto r : res) {
        cout<<r<<" ";
    }
    cout<<endl;
    
    cout<<endl;
    
    
    return 0;
}
