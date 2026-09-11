class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt=0;
        int n=digits.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int num=digits[i]*100+digits[j]*10+digits[k];
                    string len=to_string(num);
                    if(i!=j && j!=k && i!=k && digits[k]%2==0 && !st.count(num) && len.size()%3==0){
                        st.insert(num);
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};