//
//  main.cpp
//  NextClosestTime
//
//  Created by bsarvan on 13/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

/*
 
 
 Store the available <4 digit in set(sorted from minimum to maximum natrually);
 Start from end of the time string, replace it with the next larger number in the set. If available and a legal time(min < 60 && hh <24), return the result;
 Else replace it the smalleset number int the set , go to the next digit in the time string.
 Space is O(1), because <4 characters set; time is O(1), which goes through 4 characters in the string
 
 
 Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
 
 You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
 
 Example 1:
 
 Input: "19:34"
 Output: "19:39"
 Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
 Example 2:
 
 Input: "23:59"
 Output: "22:22"
 Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
 
 */
#include <iostream>
#include <set>
using namespace std;

string nextClosestTime(string time) {
    set<char> sorted;
    for(auto c:time){
        if(c==':') continue;
        sorted.insert(c);
    }
    
    string res = time;
    
    // Starting the picking the digits from the end
    for(int i = time.size() -1; i>=0; i--){
        if(time[i] == ':' ) continue;
        auto it = sorted.find(time[i]);
        
        // If the picked digit is not the largest from all the available digits,
        // pick the next largest digit from the set
        if(*it != *sorted.rbegin()){
            it++;
            res[i] = *it;
            // Add the next largest digit to result and check if the time is valid
            if((i>=3 && stoi(res.substr(3,2))<60) ||((i<2) && stoi(res.substr(0,2))<24))
                return res;
        }
        // If the time is not valid after adding the next largest digit at the index "i" in the set.
        // Add the smallest digit in the set and move to the next index.
        res[i]=*sorted.begin(); // take the smallest number
        cout<<res<<endl;
    }
    return res;
}


int main(int argc, const char * argv[]) {
    string time = "19:54";
    
    string res = nextClosestTime(time);
    cout<<"Next Closest Time to "<<time<<" is "<<res<<endl;
    return 0;
}
