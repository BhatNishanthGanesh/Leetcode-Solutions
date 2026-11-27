class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAXF = 1500;
        vector<int> freq(MAXF + 1, 0);
        for (auto &it : items) freq[it[0]]++;
        vector<int> multCnt(MAXF + 1, 0);
        for (int f = 1; f <= MAXF; f++) {
            for (int m = f; m <= MAXF; m += f) {
                multCnt[f] += freq[m];
            }
        }
        vector<int> dp(budget + 1, 0);
        for (auto &it : items) {
            int factor = it[0];
            int price = it[1];

            int bonus = multCnt[factor] - 1; 

            vector<int> ndp = dp; 

            for (int r = 0; r < price; r++) {
                int best = INT_MIN;

                for (int k = 0, b = r; b <= budget; k++, b += price) {
                    if (k > 0) {
                        best = max(best, dp[b - price] - (k - 1));
                    }

                    if (best != INT_MIN) {
                        ndp[b] = max(ndp[b], bonus + k + best);
                    }
                }
            }

            dp.swap(ndp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};