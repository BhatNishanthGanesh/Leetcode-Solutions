class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            int l=26-(s[i]-'a');
            sum+=(i+1)*l;
        }
        return sum;
    }
};