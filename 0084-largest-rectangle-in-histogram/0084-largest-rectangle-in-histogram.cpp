class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int mx=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int idx=st.top();
                st.pop();
                int h=heights[idx];
                int w;
                if(st.empty()){
                    w=i;
                }else{
                    w=i-st.top()-1;
                }
                mx=max(mx,h*w);
            }
            st.push(i);
        }
        while(!st.empty()){
            int idx=st.top();
            int h=heights[idx];
            int w;
            st.pop();
            if(st.empty()){
                w=heights.size();
            }else{
                w=heights.size()-st.top()-1;
            }
            mx=max(mx,h*w);
        }
        return mx;
    }
};