class Solution {
public:
    long long gcd(long long a,long long b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long l=0,h=1ll*(*min_element(coins.begin(),coins.end()))*k;
        while(l<h){
            long long m=l+(h-l)/2;
            long long cnt=0;
            for(int mask=1;mask<(1<<coins.size());mask++){
                long long lcm=1;
                long long bits=0;
                for(int i=0;i<coins.size();i++){
                    if(mask & (1<<i)){
                        bits++;
                        long long g=gcd(lcm,(long long)coins[i]);
                        long long nxt=lcm/g*coins[i];
                        if(nxt>m){
                            lcm=m+1;
                            break;
                        }
                        lcm=nxt;
                    }
                }
                if(lcm>m) continue;
                if(bits&1) cnt+=m/lcm;
                else cnt-=m/lcm;
            }
            if(cnt>=k){
                h=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};