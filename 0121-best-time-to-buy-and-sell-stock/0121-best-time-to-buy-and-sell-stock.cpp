class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX,sell=0,maxi=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            sell=prices[i];
            if(sell>buy){
                maxi=max(maxi,sell-buy);
            }
        }
        return maxi;
    }
};