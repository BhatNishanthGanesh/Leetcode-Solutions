class Solution {
public:
    const int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int even=1,odd=0,pref=0,cnt=0;
        for(int ele:arr){
            pref+=ele;
            if(pref%2==0){
                cnt=(cnt+odd)%mod;
                even++;
            }else{
                cnt=(cnt+even)%mod;
                odd++;
            }
        }
        return cnt;
    }
};