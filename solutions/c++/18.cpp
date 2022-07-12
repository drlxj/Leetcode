class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int k = 0; k < nums.size(); k++) {
            // cut branch
            if (nums[k] > target && (nums[k] >= 0 || target >= 0)) {
                break;
            }
            
            // delete repeated
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            
            for (int i = k + 1; i < nums.size(); i++) {
                // cut branch in 2. level
                if (nums[k] + nums[i] > target && (nums[k] + nums[i] >= 0 || target >= 0)) {
                    break;
                }
                
                // delete repeated
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                
                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right) {
                    if (nums[k] + nums[i] > target - (nums[left] + nums[right])) {
                        right--;
                        // 当前元素不合适了，可以去重
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    } else if (nums[k] + nums[i]  < target - (nums[left] + nums[right])) {
                        left++;
                        // 不合适，去重
                        while (left < right && nums[left] == nums[left - 1]) left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 去重逻辑应该放在找到一个四元组之后
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }                    
                }
            }
        }
        return result;
    }
};