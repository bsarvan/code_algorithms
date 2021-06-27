//
//  main.cpp
//  DecodeWays
//
//  Created by bsarvan on 12/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given a non-empty string containing only digits, determine the total number of ways to decode it.

 The answer is guaranteed to fit in a 32-bit integer.

  

 Example 1:

 Input: s = "12"
 Output: 2
 Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 Example 2:

 Input: s = "226"
 Output: 3
 Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 Example 3:

 Input: s = "0"
 Output: 0
 Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <map>
#include <vector>
using namespace std;

// Return the number of ways to decode a string
int decodeWaysHelper(string S, size_t k, int *memo) {
    int result;
    
    if (k == 0 ) {
        return 1;
    }
    
    size_t i = S.size() - k;
    if (S[i] == '0') {
        return 0;
    }
    
    if (memo[k] != 0) {
        return (memo[k]);
    }
    
    result = decodeWaysHelper(S, k-1, memo);
    cout<<"K - "<<k<<endl;
    cout<<S<<endl;
//    if (k>=2 && (stoi(S.substr(0,2))) <=26) {
    if (k>=2) {
        result += decodeWaysHelper(S, k-2, memo);
    }
    
    memo[k] = result;
    return result;
    
}
int decodeWays(string S) {
    int *memo = new int[S.size() + 1];
    fill_n(memo, S.size()+1, 0);
    return (decodeWaysHelper(S, S.size(), memo));
}


void DecodeWaysHelper_v2(string S, int index, int k, string curr, unordered_set<string> &unique) {

    if (!curr.empty() and curr.size() <= k and (stoi(curr) <= 26) ) {
        unique.emplace(curr);
    }
    
//    if(!curr.empty())
//        cout<<curr<<endl;
//
//    if (index == S.size()) {
//        return;
//    }

    
    for(int i = index; i < S.size(); i++) {
        curr += S[i];
        DecodeWaysHelper_v2(S, i + 1, k, curr, unique);
        curr.erase(curr.size() - 1);
    }
}

void DecodeWays_v2(string S) {
    string curr;
    unordered_set<string> set;
    DecodeWaysHelper_v2(S, 0, 2, curr, set);
    
    for (auto s : set) {
        cout<<s<<endl;
    }
}

class Solution {
public:
    
    map<int, int> memo;
    
    int recursiveWithMemo(int index, string s) {
        
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }
        
        if (index == s.size()) {
            return 1;
        }
        
        if (s[index] == '0') {
            return 0;
        }
        
        if (index == s.size() - 1) {
            return 1;
        }
        
        int ans = recursiveWithMemo(index + 1, s);
        
        if (stoi(s.substr(index, 2)) <= 26) {
            ans += recursiveWithMemo(index + 2, s);
        }
        
        memo[index] = ans;
        
        return ans;
        
    }
    
    // Decode ways recursive solution
    int numDecodingsRecursive(string s) {
        
        return recursiveWithMemo(0, s);
    }
    
    // Decode Ways Iterative solution
    int numDecodingsIterative(string s) {
        if(s.length() == 1)
        {
            if(s[0] == '0')
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        if(s[0] == '0')
        {
            return 0;
        }

        int prev1 = 1;
        int prev2 = 1;
        int cur;

        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == '0')
            {
                if(s[i - 1] == '1' || s[i - 1] == '2')
                {
                   cur = prev2; // Can only be split one way
                }
                else
                {
                    return 0; // invalid string
                }
            }
            else
            {
                string newS = "";
                newS += s[i - 1];
                newS += s[i];

                if(s[i - 1] != '0' && stoi(newS) <= 26)
                {
                    cur = prev1 + prev2; // It can be split into two ways
                }
                else
                {
                    cur = prev1; // Can only be split one way
                }
            }

            int temp = prev1;
            prev1 = cur;
            prev2 = temp;

        }
        return cur;
    }
};


// Algorithm to decode all possible valid strings


// void DecodeStringHelper(string S, int index, string partial_output, vector<string> &result) {
//     if (index == S.size() - 1) {
//         result.emplace_back(partial_output);
//         cout<<partial_output<<endl;
//         return;
//     }

//     int val = S.substr(index, 1) - '0';
//     if (val > 0 and val <= 26) {
//         partial_output += S.substr(index, 1);
//         DecodeStringHelper(S.substr(index, 1), index + 1, partial_output, result);    
//     }


//     int val = S.substr(index, 2) - '0';
//     if (val > 0 and val <= 26) {
//         partial_output += S.substr(index, 2);
//         DecodeStringHelper(S.substr(index, 2), index + 2, partial_output, result);    
//     }
    
// }

// vector<string> DecodeString(string S) {
//     vector<string> result;
//     DecodeStringHelper(S, 0, "", result);
// }

int main(int argc, const char * argv[]) {
    cout<<"Program to test number of ways to decode a numeric string"<<endl;
    int result = decodeWays("229");
    cout<<"Decode Ways - "<<result<<endl<<endl;
    
    DecodeWays_v2("229");
    
    return 0;
}
