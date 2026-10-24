class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int n=height.size();
        int water=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]<height[i]){
                int mid=st.top();
                st.pop();
                if(st.empty()) break;
                int w=i-st.top()-1;
                int h=min(height[st.top()],height[i])-height[mid];
                water+=(h*w);
            }
            st.push(i);
        }
        return water;
    }
};