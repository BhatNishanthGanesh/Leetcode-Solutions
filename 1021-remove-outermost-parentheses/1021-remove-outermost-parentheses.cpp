class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt1=0,cnt2=0;
        string str="";
        for(char c:s){
            if(c=='('){
                cnt1++;
                if(cnt1>1) str+='(';
            }else if(c==')'){
                cnt2++;
                if(cnt2<cnt1) str+=')';
            }
            if(cnt1==cnt2){
                cnt1=0;
                cnt2=0;
            }
        }
        return str;
    }
};