class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ones=0;
        int left=0;
        int bestlen=101;
        string ans;
        for(int right=0;right<s.length();right++){
            if(s[right]=='1') ones++;
            while(left<=right && ones>k){
                if(s[left]=='1') ones--;
                left++;
            }
            if(ones==k){
                int temp=left;
                while(temp<=right && s[temp]=='0') temp++;
                int len=right-temp+1;
                string sub=s.substr(temp,len);
                if(len<bestlen){
                    bestlen=len;
                    ans=sub;
                }else if(len==bestlen && sub<ans){
                    ans=sub;
                }
            }
        }
        return ans;
    }
};