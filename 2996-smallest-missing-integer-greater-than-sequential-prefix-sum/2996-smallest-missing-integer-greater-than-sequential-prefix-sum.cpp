class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int pref=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]!=1) break;
            pref+=nums[i];
        }
        unordered_set<int>st(nums.begin(),nums.end());
        int extra=0;
        for(int i=pref;i<=50;i++){
            if(!st.count(i)) return i;
            extra++;
        }
        pref+=extra;
        return st.count(pref)?pref+1:pref;
    }
};