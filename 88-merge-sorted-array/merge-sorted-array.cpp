class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m+n);
        int id=0;
        int i=0; int j=0;
        while(i<m and j<n)
        {
            if(nums1[i]<=nums2[j])
            {
            res[id]=nums1[i];
            id++;
            i++;
            }
            else
            {
                res[id]=nums2[j];
                id++;
                j++;
            }
        }
        while(j<n){
            res[id]=nums2[j];
            id++;
            j++;
        }
        while(i<m){
            res[id]=nums1[i];
            id++;
            i++;
        }
        nums1 = res;
    }
};