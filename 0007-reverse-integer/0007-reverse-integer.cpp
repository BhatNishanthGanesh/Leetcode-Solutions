class Solution {
public:
    int reverse(int x) {
        int num=0;
        bool neg=false;
        if(x==INT_MIN) return 0;
        if(x<0){
            neg=true;
            x=-x;
        }
        while(x>0){
            if(num>INT_MAX/10) return 0;
            num=num*10+(x%10);
            x/=10;
        }
        return neg?-num:num;
    }
};