/*
https://leetcode.com/problems/set-matrix-zeroes/

Approach 1 (Making 2d arrays & assign 0 accly.):-
(other approaches remn.)

class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        // get row & cols size & make 2 vectors of 1d.
        int r = m.size(), c = m[0].size();
        vector<int> rm(r, 1);
        vector<int> cm(c, 1);
        
        // Traverse of matrix.
        // Start by row
        for(int i=0; i<r; i++)
        {
            // & in that row traverse all cols.
            for(int j=0; j<c; j++)
            {
                //if any index is 0 make corr vec pos of both 2 vecs as 0.
                if(m[i][j] == 0){
                    rm[i] = 0;
                    cm[j] = 0;
                }
            }
        }// repeat till all rows gets traversed.
        
        // Make respective posns now as 0.
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                // As any vec pos gets 0 turn that mat index as 0.
                if(rm[i] == 0 || cm[j] == 0){
                    m[i][j] = 0;
                }
            }
        }
    }
};

*/