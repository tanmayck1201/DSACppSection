/*
https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=INT_MIN,i=0,j=height.size()-1;
        while(i<j){
                 int currArea=min(height[i],height[j])*(j-i);
                if(height[i]<height[j]) i++;
                        
                else  j--;
                 maxArea=max(maxArea,currArea);
        }
        return maxArea;
    }
};

*/