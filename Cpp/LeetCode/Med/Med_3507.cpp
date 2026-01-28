class Solution {
 public:
  bool isNonDecreasing(const vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) return false;
    }

    return true;
  }

  int minimumPairRemoval(vector<int>& nums) {
    int cnt = 0;

    while (!isNonDecreasing(nums)) {
      int minSum = nums[0] + nums[1];
      int idx = 0;

      for (size_t i = 1; i < nums.size() - 1; i++) {
        int temp = nums[i] + nums[i + 1];

        if (temp < minSum) {
          minSum = temp;
          idx = i;
        }
      }

      nums[idx] = nums[idx] + nums[idx + 1];
      nums.erase(nums.begin() + idx + 1);

      cnt++;
    }

    return cnt;
  }
};