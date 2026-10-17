class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<tuple<int,int,int>>v;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int sum=0;
            while(num>0){
                sum+=(num%10);
                num/=10;
            }
            v.push_back({sum,nums[i],i});
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            if(get<0>(a)==get<0>(b)) return get<1>(a)<get<1>(b);
            return get<0>(a)<get<0>(b);
        });
        int swaps=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i] || i==get<2>(v[i])) continue;
            int cycle=0;
            int j=i;
            while(!vis[j]){
                vis[j]=true;
                cycle++;
                j=get<2>(v[j]);
            }
            if(cycle>1) swaps+=(cycle-1);
        }
        return swaps;
    }
};