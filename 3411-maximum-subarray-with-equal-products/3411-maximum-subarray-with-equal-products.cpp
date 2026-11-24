class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            unsigned long long prod=1,gcd=nums[i],lc=nums[i];
            for(int j=i;j<nums.size();j++){
                prod*=1Ull*nums[j];
                gcd=__gcd(gcd,1Ull*nums[j]);
                lc=lcm(lc,1Ull*nums[j]);
                if(prod==1Ull*gcd*lc){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};