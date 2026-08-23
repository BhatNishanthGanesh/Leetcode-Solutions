class Solution {
public:
    bool isPalindromic(string s) {
        string binary="";
        for(char c:s){
            int num=c;
            string bin=bitset<8>(num).to_string();
            binary+=bin;
        }
        int l=0,r=binary.length()-1;
        while(l<=r){
            if(binary[l++]!=binary[r--]) return false;
        }
        return true;
    }
};