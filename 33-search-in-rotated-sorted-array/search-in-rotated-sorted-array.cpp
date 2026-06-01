//33. Search in Rotated Sorted Array
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) 
        {   int mid = left + (right - left) / 2;
            
            // If target is found, return its index
            if (nums[mid] == target) 
            {   return mid;
            }
            
            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) 
            {
                // Check if target lies within the sorted left half
                if (nums[left] <= target && target < nums[mid]) 
                {   right = mid - 1; // Narrow down to the left half
                } 
                else 
                {   left = mid + 1;  // Otherwise, search the right half
                }
            } 
            else  // Otherwise, the right half must be sorted 
            {
                // Check if target lies within the sorted right half
                if (nums[mid] < target && target <= nums[right]) 
                {   left = mid + 1;  // Narrow down to the right half
                } 
                else 
                {   right = mid - 1; // Otherwise, search the left half
                }
            }
        }//end of while loop
        
        // Target was not found in the array
        return -1;
    }//end of search()
};