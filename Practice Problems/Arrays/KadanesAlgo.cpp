/*
Maximum Subarray (Kadanes algo use - O(n))
Brute force - O(n^3), bf optimal - O(n^2) [Try it once!]
https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    // Kadane's algo. (Not workable in all -ve values in array.)
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            // find largest subarray sum from array
            sum += nums[i];
            // replace it with previous one in maxi.
            maxi = max(maxi, sum);
            // Sum should always be +ve value.
            if(sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};
*/