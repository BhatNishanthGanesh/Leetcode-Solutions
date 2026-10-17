class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>char_idx(26);
        for(int i=0;i<s.length();i++){
            char_idx[s[i]-'a']=i;
        }
        vector<int>ans;
        int i=0;
        while(i<s.length()){
            char c=s[i];
            int last=char_idx[s[i]-'a'];
            if(i==last){
                ans.push_back(1);
                i++;
                continue;
            }
            int j=i+1;
            while(j<last){
                int nlast=char_idx[s[j]-'a'];
                if(nlast>last) last=nlast;
                j++;
            }
            ans.push_back(j-i+1);
            i=j+1;
        }
        return ans;
    }
};