class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i= nums[0];
        int b = nums[0];
        int ans = nums[0];

        for(i=1; i<nums.size(); i++){
            int v1 = b+nums[i];
            int v2 = nums[i];
            b = max(v1, v2);
            ans = max(ans, b);
        }
        return ans;

    }
};