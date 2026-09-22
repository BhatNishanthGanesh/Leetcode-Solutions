class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int mx=0;
        for(int ele:st){
            int y=ele;
            if(!st.count(y-1)){
                int cnt=1;
                int x=y;
                while(st.count(x+1)){
                    cnt++;
                    x++;
                }
                mx=max(mx,cnt);
            }
        }
        return mx;
    }
};