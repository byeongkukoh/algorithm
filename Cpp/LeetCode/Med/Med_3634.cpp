class Solution {
 public:
  int minRemoval(vector<int>& nums, int k) {
    int n = nums.size();

    if (n == 1) return 0;

    sort(nums.begin(), nums.end());

    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
      long long temp_max_value = (long long)nums[i] * k;

      int arr_cnt = 0;
      for (int j = i; j < n; j++) {
        if (nums[j] > temp_max_value) break;
        arr_cnt++;
      }

      result = min(result, n - arr_cnt);

      if (nums[n - 1] <= temp_max_value) break;
    }

    return result;
  }
};