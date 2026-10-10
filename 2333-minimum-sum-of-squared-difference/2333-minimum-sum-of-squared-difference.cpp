class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long>freq(100001);
        for(int i=0;i<nums1.size();i++){
            int d=abs(nums1[i]-nums2[i]);
            freq[d]++;
        }
        long long k=1ll*k1+k2;
        for(int i=100000;i>=1 && k>0;i--){
            if(freq[i]==0) continue;
            long long take=min(k,freq[i]);
            freq[i]-=take;
            freq[i-1]+=take;
            k-=take;
        }
        long long ans=0;
        for(int i=1;i<=100000;i++){
            ans+=freq[i]*i*i;
        }
        return ans;
    }
};