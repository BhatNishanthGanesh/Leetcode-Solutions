class Solution {
public:
    int longestValidParentheses(string s) {
        int mx=0,open=0,close=0;
        for(char c:s){
            if(c=='(') open++;
            else close++;
            if(open==close) mx=max(mx,close*2);
            else if(close>open){
                open=close=0;
            }
        }
        open=close=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(open==close) mx=max(mx,open*2);
            else if(open>close){
                open=close=0;
            }
        }
        return mx;
    }
};