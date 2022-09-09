/*
https://leetcode.com/problems/search-a-2d-matrix/

Approach 1:-

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int r = m.size(), c = m[0].size();
        int i=0, j=c-1;
        
        // traverse last col rowwise!
        while(i<r)
        {
            // if any mat element of last col is >= target,
            if(m[i][c-1] >= target)
            {
                // Then search whole row of that col element.
                while(j >= 0)
                {
                    if(m[i][j] == target)
                        return true;
                    j--;
                }// will be executed only once if condn is true!
            }
            i++;
        }
        // if not true its false only!
        return false;
    }
};

Approach 2:-

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        if(!matrix.size()) return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target) {
                return true;
            }
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};

*/