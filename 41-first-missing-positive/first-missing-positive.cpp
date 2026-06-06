class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
        int n = nums.size();
        
        // Step 1: Cyclic Sort - Place each number in its correct index
        for (int i = 0; i < n; ++i) {
            // Using a long long or a simple cast isn't strictly necessary, 
            // but we ensure nums[i] is within the valid range [1, n].
            // We keep swapping as long as nums[i] is not at its correct home: nums[nums[i] - 1]
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Identify the first position where the value doesn't match the index
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If all spots are filled perfectly, the missing number is n + 1
        return n + 1;
    }
};