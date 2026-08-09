class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        double price=0;
        int i=0,j=0;
        while(i<prices.size()){
            if(j<discounts.size()){
                price+=prices[i]*(100-discounts[j++])/100.0;
            }else{
                price+=prices[i];
            }
            i++;
        }
        return price;
    }
};