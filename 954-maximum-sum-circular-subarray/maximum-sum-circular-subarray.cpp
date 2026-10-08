class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;

        int maxSum = nums[0];
        int minSum = nums[0];

        int currentMax = 0;
        int currentMin = 0;

        for (int x : nums) {
            currentMax = max(x, currentMax + x);
            maxSum = max(maxSum, currentMax);

            currentMin = min(x, currentMin + x);
            minSum = min(minSum, currentMin);

            total += x;
        }

        // All elements are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};