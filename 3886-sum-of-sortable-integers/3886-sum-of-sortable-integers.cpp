class Solution {
public:
    vector<int>solve(int n){
        vector<int>v;
        for(int i=1;i*i<=n;i++){
            if((n%i)==0){
                v.push_back(i);
                if(i!=(n/i)) v.push_back(n/i);
            }
        }
        return v;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>divisors=solve(n);
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int sum=0;
        for(int k:divisors){
            bool f=true;
            for(int s=0;s<n && f;s+=k){
                int cnt=0,pos=-1;
                for(int j=0;j<k;j++){
                    int a=nums[s+j];
                    int b=nums[s+(j+1)%k];
                    if(a>b){
                        cnt++;
                        pos=j;
                        if(cnt>1) break;
                    }
                }
                if(cnt>1){
                    f=false;
                    break;
                }
                int r=(cnt==0)?0:(pos+1)%k;
                for(int j=0;j<k;j++){
                    if(nums[s+(r+j)%k]!=v[s+j]){
                        f=false;
                        break;
                    }
                }
            }
            if(f) sum+=k;
        }
        return sum;
    }
};