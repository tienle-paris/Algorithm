/*
Given an integer array nums, find the sum of the elements between indices i and
j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
- You may assume that the array does not change.
- There are many calls to sumRange function.
*/


#include "header.h"

class NumArray {
public:
  NumArray(vector<int> &nums) {
    this->sum = vector<int>(nums.size() + 1, 0);
    for (auto i = 0; i < nums.size(); ++i) {
      this->sum[i + 1] = this->sum[i] + nums[i];
    }
  }

  int sumRange(int i, int j) {
    return this->sum[j + 1] - this->sum[i];
  }

private:
  vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  auto numArray = NumArray(v);
  cout << numArray.sumRange(0, 1) << endl;
}
