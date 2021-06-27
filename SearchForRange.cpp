//
//  main.cpp
//  SearchForRange
//
//  Created by bsarvan on 01/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//


/*
 
 Search for a range
 
 Given a sorted array of integers, find the starting and ending position of a given target value.
 
 Your algorithm’s runtime complexity must be in the order of O(log n).
 
 If the target is not found in the array, return [-1, -1].
 
 Example:
 
 Given [5, 7, 7, 8, 8, 10]
 
 and target value 8,
 
 return [3, 4].
 
 */

#include <iostream>
#include <vector>
using namespace std;


int binarySearch(const vector<int>& A, int key, bool searchFirst){
    int start = 0;
    int end = A.size()-1;
    int mid;
    int result =  -1;
    while(start <= end){
        mid = start + (end-start)/2;
        if(A[mid] == key){
            result = mid;
            if(searchFirst){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else if(A[mid] > key){
            end = mid-1;
        }
        else{ // A[mid] < key
            start = mid+1;
        }
    }
    return result;
}

vector<int> searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> sol;
    
    sol.push_back(binarySearch(A, B, true));
    sol.push_back(binarySearch(A, B, false));
    
    return sol;
    
}

int main(int argc, const char * argv[]) {
    cout<<"Program to find a range for a given number in an array"<<endl;
    vector<int> vec = {5, 7, 7, 8, 8, 10};
    
    vector<int> res = searchRange(vec, 8);
    
    for(auto c:res) {
        cout<<c<<" ";
    }
    cout<<endl;
    
    return 0;
}
