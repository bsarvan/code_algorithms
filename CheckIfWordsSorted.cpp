//
//  main.cpp
//  CheckIfWordsSorted
//
//  Created by Bharat Sarvan on 17/02/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


bool CheckIfSorted(vector<string> S, string alpha) {
    unordered_map<char, int> mp;
    
    for(int i = 0; i < alpha.size(); i++) {
        mp[alpha[i]] = i;
    }
    
    for (int i = 1; i < S.size(); i++) {
        string word1 = S[i - 1];
        string word2 = S[i];
        
        for (int j = 0; j < min(word1.size(), word2.size()); j++) {
            
            if (word1[j] != word2[j]) {
                if (mp[word1[j]] > mp[word2[j]])
                    return false;
                break;
            } 
        }
        
    }
    
    return true;
 
}

int main() {
//    vector<string> words = {"cat", "bat", "tab"};
//    string alpha = "cbat";
    
    vector<string> words = {"hello", "leetcode"};
    string alpha =  "habcldefgijkmnopqrstuvwxyz";
    
    string result = CheckIfSorted(words, alpha)? "TRUE":"FALSE";
    cout<<result<<endl;
    return 0;
}
