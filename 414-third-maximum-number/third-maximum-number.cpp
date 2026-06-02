class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int pervElem = nums[0];
        int maxCounted = 1;
        for(int index = 1; index<nums.size(); index++)
        {
            if (nums[index]!= pervElem)
            {
                maxCounted++;
                pervElem = nums[index];
            }
            if(maxCounted == 3)
            {
                return nums[index];
            }
        }
        return nums[0];
    }
};