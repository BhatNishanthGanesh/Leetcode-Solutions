class Solution {
public:
    long long func(vector<int>&piles,long long mid){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=(piles[i]+mid-1)/mid;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        long long low=1,high=piles[n-1];
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(func(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return (int)ans;
    }
};