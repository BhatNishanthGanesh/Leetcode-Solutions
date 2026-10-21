class Solution {
public:
    int solve(vector<int>&temp){
        int n=temp.size();
        stack<int>st;
        int mx=0;
        for(int i=0;i<=n;i++){
            int curr=(i==n)?0:temp[i];
            while(!st.empty() && curr<temp[st.top()]){
                int h=temp[st.top()];
                st.pop();
                int left=(st.empty())?-1:st.top();
                int w=i-left-1;
                mx=max(mx,h*w);
            }
            st.push(i);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>temp(m);
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') temp[j]+=1;
                else temp[j]=0;
            }
            mx=max(mx,solve(temp));
        }
        return mx;
    }
};