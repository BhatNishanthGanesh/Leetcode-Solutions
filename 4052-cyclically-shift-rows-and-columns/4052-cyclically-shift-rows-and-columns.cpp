class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>>v=grid;
        for(int i=0;i<n;i++){
            vector<int>row=v[i];
            for(int j=0;j<n;j++){
                row[j]=v[i][(j+rowShift[i]+n)%n];
            }
            v[i]=row;
        }
        for(int j=0;j<n;j++){
            vector<int>col(n);
            for(int i=0;i<n;i++){
                col[i]=v[i][j];
            }
            for(int i=0;i<n;i++){
                v[(i-colShift[j]+n)%n][j]=col[i];
            }
        }
        return v;
    }
};