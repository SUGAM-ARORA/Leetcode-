class Solution {
public:
    int numWays(int steps, int arrLen) {
        int maxPosition = min(steps / 2 + 1, arrLen);
        vector<int> curWays(maxPosition + 2, 0);
        vector<int> nextWays(maxPosition + 2, 0);
        curWays[1] = 1;
        const int mod = 1000000007;

        while (steps > 0) {
            for (int pos = 1; pos <= maxPosition; pos++) {
                nextWays[pos] = ((long)curWays[pos] + curWays[pos - 1] + curWays[pos + 1]) % mod;
            }

            swap(curWays, nextWays);
            steps--;
        }

        return curWays[1];        
    }
};