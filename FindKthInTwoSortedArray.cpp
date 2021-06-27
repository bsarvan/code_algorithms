//
//  main.cpp
//  FindKthInTwoSortedArray
//
//  Created by Bharat Sarvan on 21/10/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>

/*
 Find Kth Smallest Element from two sorted arrays
 
 A = {1,4,6,8}
 B = {2,5,7,9}
 
 K = 5
 
 Return 6
 
 */


public class KthSmallestElement {
 
    public static double findKthSmallestElement(int[] A, int[] B, int k){
 
        int[] temp;
 
        int lenA = A.length;
        int lenB = B.length;
 
        if(lenA + lenB < k) return -1;
 
        int iMin = 0;
        int iMax = Integer.min(A.length, k-1);
 
        int i = 0;
        int j = 0;
 
        while (iMin <= iMax) {
            i = (iMin + iMax) / 2;
            j = k - 1 - i; // because of zero based index
            if (B[j - 1] > A[i]) {
                // i is too small, must increase it
                iMin = i + 1;
            } else if (i > 0 && A[i - 1] > B[j]) {
                // i is too big, must decrease it
                iMax = i - 1;
            } else {
                // i is perfect
               return Integer.min(A[i], B[j]);
            }
        }
        return -1;
    }
 
    public static void main(String[] args){
        int[] a = {1,3,5,6,7,8,9,11};
        int[] b = {1,4,6,8,12,14,15,17};
 
        double smallest = findKthSmallestElement(a,b, 9);
        System.out.println("Kth smallest element is : " + smallest);
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
