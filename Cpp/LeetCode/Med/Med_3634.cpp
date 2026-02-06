/**
 * 기존 코드의 시간복잡도 O(N^2) -> 이중 반복문 (1939ms)
 * 새로운 코드의 시간복잡도 O(NlogN) -> 투 포인터 (36ms)
 */

class Solution {
 public:
  int minRemoval(vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= 1) return 0;  // 예외 처리

    sort(nums.begin(), nums.end());  // O(N log N)

    int max_keep = 0;  // 지우지 않고 남길 수 있는 최대 원소 개수
    int right = 0;

    // left는 현재 윈도우의 시작점 (최솟값 후보)
    for (int left = 0; left < n; left++) {
      long long limit = (long long)nums[left] * k;

      // right를 가능한 만큼 오른쪽으로 이동 (조건을 만족하는 동안)
      while (right < n && nums[right] <= limit) {
        right++;
      }

      // 현재 윈도우의 크기: right - left
      // (right는 조건을 만족하지 않는 첫 번째 인덱스이므로 +1을 할 필요 없음)
      int current_count = right - left;
      if (current_count > max_keep) {
        max_keep = current_count;
      }

      // 최적화: 만약 남은 원소들을 다 합쳐도 현재 max_keep보다 작다면 중단 가능
      if (right == n && (n - left) <= max_keep) break;
    }

    // 전체 개수 - 최대 유지 개수 = 최소 삭제 개수
    return n - max_keep;
  }
};

// class Solution {
//  public:
//   int minRemoval(vector<int>& nums, int k) {
//     int n = nums.size();

//     if (n == 1) return 0;

//     sort(nums.begin(), nums.end());

//     int result = INT_MAX;
//     for (int i = 0; i < n; i++) {
//       long long temp_max_value = (long long)nums[i] * k;

//       int arr_cnt = 0;
//       for (int j = i; j < n; j++) {
//         if (nums[j] > temp_max_value) break;
//         arr_cnt++;
//       }

//       result = min(result, n - arr_cnt);

//       if (nums[n - 1] <= temp_max_value) break;
//     }

//     return result;
//   }
// };