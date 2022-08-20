/* https://leetcode.com/problems/longest-common-prefix/submissions/
  Longest Common Prefix

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 0)
            return "";

        // sort alphabetically
        sort(strs.begin(), strs.end());
        string ans = "";
        // Get 1st & last strings
        string a = strs[0];
        string b = strs[n - 1];

        // compare common prefix seq between those & return!
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
            {
                ans += a[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
*/
