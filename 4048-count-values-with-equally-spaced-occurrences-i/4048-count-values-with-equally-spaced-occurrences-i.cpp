class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int rep=1;
            vector<int>ind;
            ind.push_back(i);
            for(int j=0;j<nums.size();j++){
                if(j==i) continue;
                if(nums[i]==nums[j]){
                    rep++;
                    ind.push_back(j);
                }
            }
            if(rep==3){
                bool f=true;
                if(ind[1]-ind[0]!=ind[2]-ind[1]) f=false;
                if(f) cnt++;
            }
        }
        return cnt;
    }
};