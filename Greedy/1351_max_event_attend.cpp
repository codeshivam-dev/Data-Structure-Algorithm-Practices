
/**
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.

 */

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        int n = events.size();

        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int day = events[0][0];
        int i = 0;
        int count = 0;

        while (!pq.empty() || i < n)
        {
            // Just ensured, when there will be huge diff in events day
            if (pq.empty())
                day = events[i][0];

            // Adding all events to heap, whose start at same day
            while (i < n && events[i][0] == day)
            {
                pq.push(events[i][1]);
                i++;
            }

            // if heap not empty -> today, we can attend event
            if (!pq.empty())
            {
                pq.pop();
                count++;
            }
            day++;

            // Remove all events, how are End before currentDay
            while (!pq.empty() && pq.top() < day)
                pq.pop();
            // i++;
        }

        return count;
    }
};