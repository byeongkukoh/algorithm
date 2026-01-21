class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ans;

    for (size_t i = 0; i < nums.size(); i++) {
      bool isAns = false;

      for (int j = 1; j < nums[i]; j++) {
        int temp = j | (j + 1);

        if (temp == nums[i]) {
          ans.push_back(j);
          isAns = true;
          break;
        }
      }

      if (!isAns) ans.push_back(-1);
    }

    return ans;
  }
};