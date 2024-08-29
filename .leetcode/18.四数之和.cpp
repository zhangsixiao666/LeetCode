/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    for (int i = 0; i < n - 3; ++i) {
      if (i and nums[i] == nums[i - 1]) {
        continue;
      }
        //   if (nums[i] > target) {
        //     return res;
        //   }
      for (int j = i + 1; j < n - 2; ++j) {
        if (j != i + 1 and nums[j] == nums[j - 1]) {
          continue;
        }
        // if (nums[i] + nums[j] > target) {
        //   return res;
        // }
        int p = j + 1, q = n - 1;

        while (p < q) {
          long long dist = target - static_cast<long long>(nums[i]) - nums[j] - nums[p] - nums[q];
          if (dist == 0) {
            res.emplace_back(vector<int>{nums[i], nums[j], nums[p], nums[q]});
            ++p, --q;
            while (p < q and nums[p] == nums[p - 1]) {
              ++p;
            }
            while (p < q and nums[q] == nums[q + 1]) {
              --q;
            }
          } else if (dist > 0) {
            ++p;
          } else {
            --q;
          }
        }
      }
    }

    return res;
  }
};
// @lc code=end
