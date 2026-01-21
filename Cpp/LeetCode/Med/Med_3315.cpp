class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ans;

    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 0) {
        ans.push_back(-1);
        continue;
      }

      int n = nums[i] + 1;

      int lowbit = n & -n;
      int substract = lowbit >> 1;

      if (nums[i] - substract == 0) {
        ans.push_back(-1);
      } else {
        ans.push_back(nums[i] - substract);
      }
    }

    return ans;
  }
};