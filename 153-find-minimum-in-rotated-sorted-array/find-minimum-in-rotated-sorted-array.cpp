class Solution {
public:
    int findMin(vector<int>& nums) {
// Find minimum element in a rotated sorted array
    int low = 0, high = nums.size() - 1;

    while(low < high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] > nums[high]) {
            low = mid + 1;  // Min is in right half
        } else {
        
            high = mid;  // Min is in left half (including mid)
        }
    }
    return nums[low];
}
};