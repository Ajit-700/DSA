class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return {};
        
        vector<int> left(n);
        vector<int> right(n);
        
        // 1. Left array bharna
        for (int i = 0; i < n; i++) {
            // Agar block ki shuruaat hai, toh wahi number max hoga
            if (i % k == 0) {
                left[i] = nums[i];
            } else {
                left[i] = max(left[i - 1], nums[i]);
            }
        }
        
        // 2. Right array bharna
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            // Agar naya block shuru ho raha hai (right se)
            if ((i + 1) % k == 0) {
                right[i] = nums[i];
            } else {
                right[i] = max(right[i + 1], nums[i]);
            }
        }
        
        // 3. Final answer nikalna
        vector<int> result;
        for (int i = 0; i <= n - k; i++) {
            // Har window ka max simple formula se mil jayega
            int windowMax = max(right[i], left[i + k - 1]);
            result.push_back(windowMax);
        }
        
        return result;
    }
};