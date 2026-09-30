class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        int open=0;
        for(char c:seq){
            if(c=='('){
                open++;
                ans.push_back(open%2);
            }else{
                ans.push_back(open%2);
                open--;
            } 
        }
        return ans;
    }
};