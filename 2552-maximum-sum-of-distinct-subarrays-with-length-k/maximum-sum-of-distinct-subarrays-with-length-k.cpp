class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
 std::unordered_set<int> uniqueElements;
long long currentWindowSum = 0;
long long maxSubarraySum = 0;
int left = 0;
for (int right = 0; right < n; ++right) {
// Condition 1: Maintain distinct elements.
// If the incoming element is a duplicate, shrink the window
// from the left until the duplicate element is removed.
while (uniqueElements.count(nums[right]) == 1) {
 currentWindowSum = currentWindowSum - nums[left];
 uniqueElements.erase(nums[left]);
 left++;
 }
// Include the current element in the window
 uniqueElements.insert(nums[right]);
 currentWindowSum = currentWindowSum + nums[right];
// Condition 2: Check if the window has reached the required length 'k'
if (right - left + 1 == k) {
// Update the maximum sum found so far
 maxSubarraySum = std::max(maxSubarraySum, currentWindowSum);
// Slide the window forward by removing the leftmost element
 currentWindowSum = currentWindowSum - nums[left];
 uniqueElements.erase(nums[left]);
 left++;
 }
 }
return maxSubarraySum;
 }
};