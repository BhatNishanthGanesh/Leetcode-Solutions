class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sumA=accumulate(source.begin(),source.end(),0ll);
        long long sumB=accumulate(target.begin(),target.end(),0ll);
        return sumA==sumB;
    }
};