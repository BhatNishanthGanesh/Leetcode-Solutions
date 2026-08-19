class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>mp;
        for(int i=0;i<reservedSeats.size();i++){
            int row=reservedSeats[i][0];
            int col=reservedSeats[i][1];
            if(!mp.count(row)) mp[row]=7;
            if(col==2 || col==3) mp[row]&=3;
            else if(col==4 || col==5) mp[row]&=1;
            else if(col==6 || col==7) mp[row]&=4;
            else if(col==8 || col==9) mp[row]&=6;
        }
        int res=(n-mp.size())*2;
        for(auto &[_,v]:mp){
            if(v==5 || v==7) res+=2;
            else if(v!=0) res++;
        }
        return res;
    }
};