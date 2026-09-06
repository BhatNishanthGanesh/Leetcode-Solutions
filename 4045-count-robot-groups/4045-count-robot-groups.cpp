class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int cnt=1;
        int n=speed.size();
        vector<int>sp,pos;
        sp.push_back(speed[n-1]);
        int mn=position[n-1];
        for(int i=n-2;i>=0;i--){
            if(speed[i]<=sp.back() && mn-position[i]>distance){
                pos.push_back(mn);
                sp.push_back(speed[i]);
            }
            mn=position[i];
        }
        pos.push_back(mn);
        return (int)pos.size();
    }
};