class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int mx=0;
        for(int x:st){
            int cnt=1;
            if(!st.count(x-1)){
                int y=x;
                while(st.count(y+1)){
                    y++;
                    cnt++;
                }
                mx=max(mx,cnt);
            }
        }
        return mx;
    }
};