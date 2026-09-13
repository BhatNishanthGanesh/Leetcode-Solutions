vector<vector<int>>pal(2);
bool f=false;
void precompute(){
    if(f) return;
    for(int x=1;x<=100000;x++){
    long long n=x;
    int rev=n/10;
        while(rev){
            n=n*10+(rev%10);
            rev/=10;
        }
        if(n<=1e9){
            pal[n&1].push_back(n);
        }
        n=x;
        rev=x;
        while(rev){
            n=n*10+(rev%10);
            rev/=10;
        }
        if(n<=1e9){
            pal[n&1].push_back(n);
        }
    }
    for(auto &v:pal) sort(v.begin(),v.end());
    f=true;
}
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        precompute();
        long long cnt=0;
        for(int ele:nums){
            auto &v=pal[ele&1];
            auto it=lower_bound(v.begin(),v.end(),ele);
            long long mn=LLONG_MAX;
            if(it!=v.end()){
                mn=min(mn,(long long)*it-ele);
            }
            if(it!=v.begin()){
                --it;
                mn=min(mn,(long long)ele-*it);
            }
            cnt+=mn/2;
        }
        return cnt;
    }
};