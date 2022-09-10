/*
https://leetcode.com/problems/search-a-2d-matrix-ii/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int i = 0, j = m[0].size() - 1;
        int n = m.size();

        // Search till i&j gets out of bound of r&c size.
        while(i<n && j>=0)
        {
            if(m[i][j] == target)
                return true;
            if(m[i][j] > target)
            {
                // search in that row.
                j--;
            }else{
                // Goto next row.
                i++;
            }
        }
        return false;
    }
};

*/