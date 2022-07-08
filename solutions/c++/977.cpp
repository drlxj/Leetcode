// Details:
// Runtime: 43 ms, faster than 72.39% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 25.9 MB, less than 81.50% of C++ online submissions for Squares of a Sorted Array.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> results(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i <= j; ){
            if (nums[i] * nums[i] < nums[j] * nums[j]){
                results[k--] = nums[j] * nums[j];
                j--;
            } else{
                results[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return results;
    }
};