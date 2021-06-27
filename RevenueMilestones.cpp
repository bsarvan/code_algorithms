//
//  main.cpp
//  RevenueMilestones
//
//  Created by Bharat Sarvan on 05/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {
  // Write your code here

  vector<int> result;
  
  #if 0
  for (auto milestone : milestones) {
    int revenue_so_far = 0;
    for (int i = 0; i < revenues.size(); i++) {
      revenue_so_far += revenues[i];
      if (revenue_so_far >= milestone) {
        result.emplace_back(i + 1);
        break;
      }
    }
  }
  #endif
  
  vector<int> cum_sum;
  
  int sum = 0;
  for(auto revenue : revenues) {
    sum += revenue;
    cum_sum.emplace_back(sum);
  }
  
  for(auto milestone : milestones) {
    auto iter = lower_bound(cum_sum.begin(), cum_sum.end(), milestone);
    result.emplace_back(iter - cum_sum.begin() + 1);
  }
  
  return result;
  
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size();
  int output_size = output.size();
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected);
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {
  // Testcase 1
  int n_1 = 5, k_1 = 4;
  vector <int> revenues_1{100, 200, 300, 400, 500};
  vector <int> milestones_1{300, 800, 1000, 1400};
  vector <int> expected_1{2, 4, 4, 5};
  vector <int> output_1 = getMilestoneDays(revenues_1, milestones_1);
  check(expected_1, output_1);

  // Testcase 2
  int n_2 = 6, k_2 = 5;
  vector <int> revenues_2{700, 800, 600, 400, 600, 700};
  vector <int> milestones_2{3100, 2200, 800, 2100, 1000};
  vector <int> expected_2{5, 4, 2, 3, 2};
  vector <int> output_2 = getMilestoneDays(revenues_2, milestones_2);
  check(expected_2, output_2);
  
  // Add your own test cases here
  
}
