class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while((int)ans.length()<num){
            int curr=min(9,sum);
            ans+=to_string(curr);
            sum-=curr;
        }
        return sum>0?"":ans;
    }
};