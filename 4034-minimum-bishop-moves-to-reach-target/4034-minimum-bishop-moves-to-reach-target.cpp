class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int src1=source[0];
        int src2=source[1];
        int tar1=target[0];
        int tar2=target[1];
        int diff1=abs(src1-src2);
        int diff2=abs(tar1-tar2);
        if(diff1%2 != diff2%2) return -1;
        return abs(src1-tar1)==abs(src2-tar2)?1:2;
    }
};