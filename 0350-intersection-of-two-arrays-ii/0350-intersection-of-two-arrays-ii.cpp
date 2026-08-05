class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>freq(1001),freq2(1001);
        for(int ele:nums1) freq[ele]++;
        for(int ele:nums2) freq2[ele]++;
        vector<int>ans;
        for(int i=0;i<1001;i++){
            if(freq[i]==0 || freq2[i]==0) continue;
            int mini=min(freq[i],freq2[i]);
            for(int j=0;j<mini;j++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};