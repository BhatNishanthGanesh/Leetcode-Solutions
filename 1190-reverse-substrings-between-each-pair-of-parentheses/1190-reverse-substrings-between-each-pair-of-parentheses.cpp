class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string curr;
        s.insert(s.begin(),'(');
        s+=')';
        for(char c:s){
            if(!curr.empty()){
                for(char ch:curr) st.push(ch);
                curr="";
            }
            if(c==')'){
                while(!st.empty() && st.top()!='('){
                    curr+=st.top();
                    st.pop();
                }
                if(st.top()=='(') st.pop();
            }else{
                st.push(c);
            }
        }
        reverse(curr.begin(),curr.end());
        return curr;
    }
};