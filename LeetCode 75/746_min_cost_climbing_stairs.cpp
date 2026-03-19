class Solution
{
public:
    vector<int> dp;
    int solve(vector<int> &cost, int idx)
    {
        if (idx >= cost.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int step1 = cost[idx] + solve(cost, idx + 1);
        int step2 = cost[idx] + solve(cost, idx + 2);

        return dp[idx] = min(step1, step2);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        dp.assign(n + 1, -1);
        return min(solve(cost, 0), solve(cost, 1));
    }
};