//
//  main.cpp
//  ExtractWordsFromString
//
//  Created by Bharat Sarvan on 21/03/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    // Write C++ code here
    string s = "He wants to eat food.";
    vector<string> sVec;
    size_t start = 0;
    size_t end = 0;
    while((end = s.find(" ", start)) != string::npos) {
        sVec.emplace_back(s.substr(start, end - start));
        start = end + 1;
    }
    
    sVec.emplace_back(s.substr(start));
    
    for (auto v : sVec) {
        cout<<v<<endl;
    }
    
    return 0;
}
