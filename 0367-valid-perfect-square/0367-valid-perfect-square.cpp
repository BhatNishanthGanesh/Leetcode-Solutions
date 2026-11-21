class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i=1;1ll*i*i<=1ll*num;i++){
            if(1ll*i*i==num) return 1;
        }
        return 0;
    }
};