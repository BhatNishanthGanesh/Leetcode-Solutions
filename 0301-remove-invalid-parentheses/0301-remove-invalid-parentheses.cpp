class Solution {
public:
    void solve(int i,int leftRem,int rightRem,int balance,string &s,vector<string>&v,unordered_set<string>&st,string &temp){
        if(i==s.length()){
            if(leftRem==0 && rightRem==0 && balance==0){
                if(!st.count(temp)){
                    st.insert(temp);
                    v.push_back(temp);
                }
            }
            return;
        }
        if(s[i]=='('){
            if(leftRem>0) solve(i+1,leftRem-1,rightRem,balance,s,v,st,temp);
            temp+=s[i];
            solve(i+1,leftRem,rightRem,balance+1,s,v,st,temp);
            temp.pop_back();
        }
        else if(s[i]==')'){
            if(rightRem>0) solve(i+1,leftRem,rightRem-1,balance,s,v,st,temp);
            temp+=s[i];
            if(balance>0) solve(i+1,leftRem,rightRem,balance-1,s,v,st,temp);
            temp.pop_back();
        }
        else{
            temp+=s[i];
            solve(i+1,leftRem,rightRem,balance,s,v,st,temp);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>v;
        unordered_set<string>st;
        string temp;
        int l=0,r=0,b=0;
        for(char c:s){
            if(c=='(') b++;
            else if(c==')'){
                if(b>0) b--;
                else r++;
            }
        }
        l=b;
        solve(0,l,r,0,s,v,st,temp);
        return v;
    }
};