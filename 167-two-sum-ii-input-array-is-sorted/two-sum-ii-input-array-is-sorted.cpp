class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       // 2 pointers se solve 
       int n = numbers.size();
       int left = 0, right = n - 1;
       while (left < right)
       {
        int current_sum = numbers[left] + numbers[right];
        if (current_sum == target)
        {
            return{left + 1, right + 1};
        }   
         else if(current_sum < target)
         {
            left++;
         }
         else
         right--;
        }
        return{};
    }
};