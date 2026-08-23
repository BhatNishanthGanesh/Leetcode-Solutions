class Solution {
public:
    bool isPalindromic(string s) {
        int l=0,r=s.length()-1;
        while(l<=r){
            int left=s[l];
            int right=s[r];
            for(int i=7;i>=0;i--){
                if(((left>>i)&1) != ((right>>(7-i))&1)){
                    return false;
                }
            }
            l++;
            r--;
        }
        return true;
    }
};