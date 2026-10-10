class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size(),mx=0;
        for(int i=0;i<=n;i++){
            int curr=(i==n)?0:heights[i];
            while(!st.empty() && heights[st.top()]>=curr){
                int idx=st.top();
                int h=heights[idx];
                st.pop();
                int w=i-(st.empty()?-1:st.top())-1;
                mx=max(mx,h*w);
            }
            st.push(i);
        }
        return mx;
    }
};