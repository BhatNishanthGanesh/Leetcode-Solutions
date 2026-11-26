class Solution {
public:
    bool canAliceWin(int n) {
        bool alice=true;
        int cnt=10;
        while(n>=0){
            n-=cnt;
            cnt--;
            alice=!alice;
        }
        return alice;
    }
};