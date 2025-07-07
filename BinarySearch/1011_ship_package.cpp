
/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/


class Solution
{
public:
    int findDays(vector<int> &weights, int capacity)
    {
        int countDay = 0;
        int pWeight = 0;

        for (int num : weights)
        {
            if (num <= capacity)
            {
                pWeight += num;
                if (pWeight > capacity)
                {
                    countDay++;
                    pWeight = num;
                }
            }
        }
        if (pWeight <= capacity)
            countDay++;
        return countDay;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = low * n;
        int ans = 0;

        while (low <= high)
        {
            int cap = low + (high - low) / 2;

            int countDay = findDays(weights, cap);

            if (countDay <= days)
            {
                ans = cap;
                high = cap - 1;
            }
            else
                low = cap + 1;
        }
        return ans;
    }
};