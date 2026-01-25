class Solution {
 public:
  int minimumDifference(vector<int>& nums, int k) {
    if (k == 1) return 0;

    sort(nums.begin(), nums.end());

    int result = INT_MAX;
    for (size_t i = 0; i < nums.size() - k + 1; i++) {
      result = min(result, nums[i + k - 1] - nums[i]);
    }

    return result;
  }
};