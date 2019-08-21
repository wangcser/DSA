#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool test(vector<int>& nums) {
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] < nums[i + 1])
			return false;
	}

	return true;
}

int main() {
	int num;
	vector<int> nums;

	// read test case from file
	ifstream rf;
	rf.open("./testcase.in", ios::in);

	while (!rf.eof()) {
		rf >> num;
		nums.push_back(num);
		for (auto m : nums) {
			cout << m << endl;
		}
	}
	rf.close();

	// run test case
	bool result;

	result = test(nums);
	cout << result << endl;

	return 0;
}