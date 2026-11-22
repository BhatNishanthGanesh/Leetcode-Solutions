class Solution {
public:
    bool checkString(string s) {
        int b=0;
        for(char c:s){
            if(c=='a' && b>0) return false;
            if(c=='b') b++;
        }
        return true;
    }
};