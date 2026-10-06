class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int i =0;
        int minend= nums[0];
         int maxend= nums[0];
        int res = abs(nums[0]);
        for(i=1; i<nums.size(); i++)
        {
            int v1 = nums[i];
            int v2 = minend+nums[i];
            int v3 = maxend+nums[i];
            minend = min(v1, min(v2, v3));
            maxend = max(v1, max(v2, v3));
            res= max(res, max(abs(minend), abs(maxend)));
        }
        return res;
    }
};