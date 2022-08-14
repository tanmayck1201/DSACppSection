/* 
https://leetcode.com/problems/valid-palindrome/
TC - O(n)
 
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            // if front ptr isn't alphanumeric skip it! 
            if(!isalnum(s[l]))
                l++;
            // if back ptr isn't alphanumeric skip it! 
            else if(!isalnum(s[r]))
                r--;
            // Convert to lower case & check if it matches!
            else if(tolower(s[l])!=tolower(s[r]))
                return false;
            // If matches proceed furthure.
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
};
*/