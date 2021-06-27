#include <iostream>
#include <vector>
using namespace std;


// O(n2) solution
int maxSubArraySum_v1(vector<int> arr) {
	int maxSum = INT_MIN;
	

	for (int i = 0; i < arr.size(); i++) {
		int n = 0;
		int sumSoFar = 0;	
		while(n < arr.size()) {
			int index = (i + n) % arr.size();
			sumSoFar += arr[index];
			maxSum = max(maxSum, sumSoFar);
			sumSoFar = max(sumSoFar, 0);
			n++;
		}
	}

	return maxSum;
}



int max_subarray_sum(vector<int> arr) {
	int max_sum = INT_MIN;
	int sum_so_far = 0;

	for (auto a : arr) {
		sum_so_far = max(a, a + sum_so_far);
		max_sum  = max(sum_so_far, max_sum);
	}

	return max_sum;
}

int min_subarray_sum(vector<int> arr) {
	int min_sum = INT_MAX;
	int min_so_far = 0;

	for (auto a : arr) {
		min_so_far = min(a, min_so_far + a);
		min_sum = min(min_sum, min_so_far);
	}

	return min_sum;

}

int sumOfArray(vector<int> arr) {
	int sum = 0;
	for(auto a:arr) {
		sum += a;	
	}

	return sum;
}

int maxSubArraySum_v2(vector<int> arr) {
	int max_subarray_sum_wrapped_around = sumOfArray(arr) - min_subarray_sum(arr);
	return max(max_subarray_sum_wrapped_around, max_subarray_sum(arr));
}


int main() {
	vector<int> arr = {8, -1, 3, 4};
	// vector<int> arr = {-4, 5, 1, 0};


	cout<<"Algorithm to find the max subarray sum in a circular array"<<endl;
	int result = 0;

	// result = maxSubArraySum_v1(arr);

	result = maxSubArraySum_v2(arr);

	cout<<"Max Sub Array Sum is "<<result<<endl;

	return 0;
}



