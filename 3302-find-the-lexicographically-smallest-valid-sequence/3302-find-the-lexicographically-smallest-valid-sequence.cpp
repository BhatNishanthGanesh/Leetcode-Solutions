class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<int>suff(n);
        if(word1[n-1]==word2[m-1]) suff[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int k=suff[i+1];
            if(k<m && word1[i]==word2[m-k-1]) suff[i]=k+1;
            else suff[i]=k;
        }
        vector<int>ans;
        int i=0,j=0;
        bool used=false;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }else if(!used){
                bool possible;
                if(i==n-1){
                    possible=(j==m-1);
                }else{
                    possible=(suff[i+1]>=m-j-1);
                }
                if(possible){
                    ans.push_back(i);
                    j++;
                    used=true;
                }
            }
            i++;
        }
        if(j==m) return ans;
        return {};
    }
};