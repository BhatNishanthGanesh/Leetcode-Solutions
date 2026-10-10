class Solution {
public:
    int func(vector<int>&bloomDay,int mid,int k){
        int bq=0,cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
                if(cnt==k){
                    bq++;
                    cnt=0;
                }
            }else{
                cnt=0;
            }
        }
        return bq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m>bloomDay.size()/k) return -1;
        int l=1,h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(bloomDay,mid,k)>=m){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};