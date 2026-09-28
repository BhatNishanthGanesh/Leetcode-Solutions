class Solution {
public:
    int maxDepth(string s) {
        int mx=0;
        int open=0;
        for(char c:s){
            if(c=='(') open++;
            else if(c==')') open--;
            mx=max(mx,open);
        }
        return mx;
    }
};