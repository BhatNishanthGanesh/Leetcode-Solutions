class Solution {
public:
    bool possible(int mid,int n,int m,vector<vector<int>>&pref){
        int mxrow=-1,mxcol=-1,mnrow=n,mncol=m;
        for(int i=0;i+mid<=n;i++){
            for(int j=0;j+mid<=m;j++){
                int sum=pref[i+mid][j+mid]-pref[i][j+mid]-pref[i+mid][j]+pref[i][j];
                if(sum==mid*mid){
                    mxrow=max(mxrow,i);
                    mnrow=min(mnrow,i);
                    mxcol=max(mxcol,j);
                    mncol=min(mncol,j);
                }
            }
        }
        if(mxrow==-1) return false;
        return (mxrow-mnrow>=mid || mxcol-mncol>=mid);
    }
    int maxArea(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int ans=0;
        vector<vector<int>>pref(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pref[i][j]=mat[i-1][j-1]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
            }
        }
        int l=0,h=min(n,m);
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possible(mid,n,m,pref)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans*ans;
    }
};