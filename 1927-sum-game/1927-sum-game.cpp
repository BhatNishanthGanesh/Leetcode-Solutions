class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        int ql=0,qr=0,leftSum=0,rightSum=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') ql++;
            else{
                leftSum+=(num[i]-'0');
            }
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?') qr++;
            else{
                rightSum+=(num[i]-'0');
            }
        }
        if(ql==0 && qr==0){
            return leftSum!=rightSum;
        }
        if((ql+qr)&1) return true;
        return 2*(leftSum-rightSum)+9*(ql-qr)!=0;
    }
};