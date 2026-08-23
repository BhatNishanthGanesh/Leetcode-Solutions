class Solution {
public:
    vector<int>spf;
    void precompute(){
        spf.resize(100001);
        for(int i=1;i<=100000;i++) spf[i]=i;
        for(int i=2;i*i<=100000;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=100000;j+=i){
                    if(spf[j]==j) spf[j]=i;
                }
            }
        }
    }
    vector<int>getFactors(int x){
        vector<int>v;
        while(x>1){
            int p=spf[x];
            v.push_back(p);
            while(x%p==0) x/=p;
        }
        return v;
    }
    int longestSubarray(vector<int>& nums, int k) {
        precompute();
        int l=0,maxi=0,dis=0;
        vector<int>cnt(100001);
        for(int r=0;r<nums.size();r++){
            vector<int>factor=getFactors(nums[r]);
            for(int p:factor){
                if(cnt[p]==0) dis++;
                cnt[p]++;
            }
            while(dis>k){
                vector<int>leftfactor=getFactors(nums[l]);
                for(int p:leftfactor){
                    cnt[p]--;
                    if(cnt[p]==0) dis--;
                }
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};