class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // If the first element of the ordered nums is greater than zero
            if (nums[i] > 0) {
                return result;
            }
            
            // delete the repeated triplet
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                if (nums[i] + nums[left] + nums[right] < 0){
                    left++;
                    // delete repeated 
                    while (left < right && nums[left] == nums[left - 1]) left++;
                } else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                    // delete repeated 
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    
                    // delete repeated 
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    
                    right--;
                    left++;
                }
                    
            }
        }
        return result;
    }
};