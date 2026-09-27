class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>num=nums;
        vector<int>ans;
        while(!num.empty()){
            set<int>st(num.begin(),num.end());
            ans.insert(ans.end(),st.begin(),st.end());
            vector<int>used(101,0);
            vector<int>curr;
            for(int ele:num){
                used[ele]++;
                if(used[ele]>1) curr.push_back(ele);
            }
            num=curr;
        }
        return ans;
    }
};