class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        f[0] =1;
        int sum =0;
        int count =0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int q = sum-k;
            int freq = f[q];
            count += freq;
            f[sum]++;
        }
        return count;
    }
};