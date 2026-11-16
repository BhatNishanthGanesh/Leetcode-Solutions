class Solution {
public:
    string digitSum(string s, int k) {
        while((int)s.length()>k){
            string num;
            for(int i=0;i<s.length();i+=k){
                string curr;
                if(i+k>=s.length()) curr=s.substr(i,s.length()-i+1);
                else{
                    curr=s.substr(i,k);
                }
                int sum=0;
                for(int j=curr.length()-1;j>=0;j--){
                    sum+=(curr[j]-'0');
                }
                num+=to_string(sum);
            }
            s=num;
        }
        return s;
    }
};