class Solution {
 public:
  bool isTrionic(vector<int>& nums) {
    int p = 0, q = 0;

    // 증가하는지 체크
    for (size_t i = 1; i < nums.size() - 1; i++) {
      if (nums[i] - nums[i - 1] <= 0) {
        // 더 이상 증가하지 않음
        p = i - 1;

        if (p == 0) return false;
        break;
      }
    }

    // 감소하는지 체크
    for (int i = p; i < nums.size() - 1; i++) {
      if (nums[i] - nums[i + 1] <= 0) {
        // 더 이상 감소하지 않음
        q = i;
        if (q == 0 || q == 1) return false;

        break;
      }
    }

    // 증가하는지 체크
    for (int i = q; i < nums.size() - 1; i++) {
      if (nums[i] - nums[i + 1] >= 0) {
        // 더 이상 증가하지 않음
        return false;
      }
    }

    return true;
  }
};