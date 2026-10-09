class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && s[i]==')'){
                if((i+1<s.length() && s[i+1]!=')') || (i==s.length()-1)){
                    st.pop();
                    cnt++;
                }else{
                    i++;
                    st.pop();
                }
            }else if(st.empty() && i+1<s.length() && s[i]==')' && s[i+1]==')'){
                i++;
                cnt++;
            }
            else if(st.empty() && s[i]==')'){
                cnt+=2;
            }else if(s[i]=='(') st.push('(');
        }
        cnt+=2*(int)st.size();
        return cnt;
    }
};