class Solution {
public:
    const int mod=1e9+7;
    vector<int>prev(vector<int>&arr){
        stack<int>st;
        vector<int>pse;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse.push_back(-1);
            }else{
                pse.push_back(st.top());
            }
            st.push(i);
        }
        return pse;
    }
    vector<int>next(vector<int>&arr){
        stack<int>st;
        vector<int>nse;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse.push_back(arr.size());
            }else{
                nse.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nse.begin(),nse.end());
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>pse=prev(arr);
        vector<int>nse=next(arr);
        long long cnt=0;
        for(int i=0;i<arr.size();i++){
            cnt=(cnt+1ll*arr[i]*(i-pse[i])*(nse[i]-i))%mod;
        }
        return (int)cnt;
    }
};