class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.length();
        string str=s+s;
        int ans=0;
        for(int i=0;i<n;i++){
            string curr=str.substr(i,n);
            int score=0;
            for(int j=1;j<curr.length();j++){
                if(curr[j]==curr[j-1]) score++;
            }
            if(score==k) ans++;
        }
        return ans;
    }
};