class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        string alpha="abcdefghijklmnopqrstuvwxyz";
        // value of z can be max upto 2^25. ie=33554432
        int MAX_VAL=33554432;
        for(int ele:nums){
            string curr="";
            int zcnt=ele/MAX_VAL;
            if(zcnt>0){
                curr.append(zcnt,'z');
            }
            int rem=ele%MAX_VAL;
            for(int i=24;i>=0;i--){
                if((rem>>i)&1) curr.push_back(alpha[i]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};