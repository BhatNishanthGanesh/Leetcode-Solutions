class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt=0;
        vector<int>v;
        for(int ele:nums){
           if(ele==1){
              cnt++;
           }else{
              if(cnt>0) v.push_back(cnt);
              cnt=0;
              v.push_back(cnt);
           }
        }
        if(cnt>0) v.push_back(cnt);
        if((int)v.size()==1 && v[0]!=0) return v[0]-1;
        cnt=0;
        int mx=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                int l=(i>0)?v[i-1]:0;
                int r=(i<v.size()-1)?v[i+1]:0;
                mx=max(mx,l+r);
            }
        }
        return mx;
    }
};