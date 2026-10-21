class Solution {
public:
    const int mod=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int end0=0,end1=0;
        bool has0=false;
        for(char c:binary){
            if(c=='0'){
                end0=(end0+end1)%mod;
                has0=true;
            }else{
                end1=(end0+end1+1)%mod;
            }
        }
        return (end0+end1+has0)%mod;
    }
};