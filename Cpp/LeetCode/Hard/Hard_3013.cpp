class Solution {
 public:
  multiset<int> L_set;
  multiset<int> R_set;

  long long minimum_sum = 0;
  long long result = LLONG_MAX;

  void init() {
    minimum_sum = 0;
    result = LLONG_MAX;

    L_set.clear();
    R_set.clear();
  }

  void insert_and_balence(int number, int k) {
    // 1. L_set에 값을 넣는다.
    L_set.insert(number);
    minimum_sum += number;

    // 2. L_set의 개수가 k-2보다 많으면 (넘치면)
    if (L_set.size() > k - 2) {
      // 2-1. L_set에서 가장 큰 값을 꺼내고 지운다.
      int temp_val = *L_set.rbegin();
      L_set.erase(prev(L_set.end()));

      // 2-2. 합계에서 제외하고, R_set으로 옮긴다.
      minimum_sum -= temp_val;
      R_set.insert(temp_val);
    }

    // 3. 역전 현상이 발생했다면, 값을 정리한다.
    if (!R_set.empty() && *R_set.begin() < *L_set.rbegin()) {
      int max_L = *L_set.rbegin();
      int min_R = *R_set.begin();

      // 3-1. max_L과 min_R 스왑한다.
      L_set.erase(prev(L_set.end()));
      R_set.erase(R_set.begin());

      L_set.insert(min_R);
      R_set.insert(max_L);

      minimum_sum -= max_L;
      minimum_sum += min_R;
    }
  }

  void remove(int out_num, int k) {
    // 1. 먼저L_set에서 out_num을 찾는다.
    if (L_set.find(out_num) != L_set.end()) {
      // 2. L_set에 있으면 지우고 minimum_sum 업데이트 한다.
      int erase_num = *L_set.find(out_num);
      L_set.erase(L_set.find(out_num));
      minimum_sum -= erase_num;
    } else {
      // 3. L_set에 없으면 R_set에서 찾아서 지운다.
      R_set.erase(R_set.find(out_num));
    }

    // 4. L_set의 개수가 k-2보다 작아지면 R_set에서 가져온다.
    if (L_set.size() < k - 2 && !R_set.empty()) {
      int move_num = *R_set.begin();
      R_set.erase(R_set.begin());
      L_set.insert(move_num);

      minimum_sum += move_num;
    }
  }

  long long minimumCost(vector<int>& nums, int k, int dist) {
    init();

    minimum_sum = nums[0];
    if (nums.size() == 1) return minimum_sum;

    // 1. 초기 insert 수행 (1 ~ k - 2)
    for (size_t i = 1; i <= k - 2; i++) {
      insert_and_balence(nums[i], k);
    }

    // 2. 슬라이딩 윈도우 수행
    for (size_t i = k - 1; i < nums.size(); i++) {
      // 2-1. 초기 정답 체크
      result = min(result, minimum_sum + nums[i]);

      // 2-2. 새로운 값 insert 수행
      int ins_num = nums[i];
      insert_and_balence(ins_num, k);

      // 2-3. 빠져야 하는 값 remove 수행
      if (i >= 1 + dist) {
        int out_num = nums[i - dist];
        remove(out_num, k);
      }
    }

    return result;
  }
};