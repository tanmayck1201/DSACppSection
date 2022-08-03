/*
Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tp = INT_MAX; //Max int which will replace least so far element.
        int p = 0; // overall profit
        int pist = 0; // profit if sold today
        int n = prices.size();
        
        for(int i=0; i<n; i++)
        {
            // if we found new buy value which is more smaller then previous one
            if(prices[i] < tp) 
            {
                // update our least so far
                tp = prices[i];
            }
            
            // calculating profit if sold today by, Buy - sell
            pist = prices[i] - tp;
            // if pist is more then our previous overall profit
            if(p < pist)
            {
                // update overall profit
                p = pist;
            }
        }
        return p;
    }
};
*/