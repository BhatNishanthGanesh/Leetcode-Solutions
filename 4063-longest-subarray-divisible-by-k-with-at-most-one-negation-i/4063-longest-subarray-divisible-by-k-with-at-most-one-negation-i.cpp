class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            unordered_set<int> seen;

            for (int r = i; r < n; r++) {
                sum += nums[r];

                int rem = ((sum % k) + k) % k;

                if (rem == 0) {
                    ans = max(ans, r - i + 1);
                }

                int x = ((2LL * nums[r]) % k + k) % k;
                seen.insert(x);

                if (seen.count(rem)) {
                    ans = max(ans, r - i + 1);
                }
            }
        }

        return ans;
    }
};