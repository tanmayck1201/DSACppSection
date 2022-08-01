/* Search in sorted rotated array leetcode (medium) 33 pblm.
   https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int r;
        int n = nums.size();
        int c = 0, i = n - 1;

        // calc. by what no. array is pivoted
        while (nums[0] > nums[i])
        {
            c++;
            i--;
        }

        // dividing array in unpivoted & pivoted parts
        int k = n - c;

        // array not at all pivoted!
        if (c == 0)
            r = RBS(nums, 0, n - 1, target);
        else
        {
            // search in pivoted part.
            if (target < nums[0])
            {
                r = RBS(nums, k, n - 1, target);
            }
            // search in unpivoted part.
            else
            {
                r = RBS(nums, 0, k - 1, target);
            }
        }
        // check & return.
        if (r == -1)
            return -1;
        else
            return r;
    }

    // Recursive Bin Search algo.
    int RBS(vector<int> &nums, int l, int h, int key)
    {
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == key)
            {
                return mid;
            }
            else if (key < nums[mid])
            {
                return RBS(nums, l, mid - 1, key);
            }
            else
            {
                return RBS(nums, mid + 1, h, key);
            }
        }
        return -1;
    }
};

  main pgm is required!

*/