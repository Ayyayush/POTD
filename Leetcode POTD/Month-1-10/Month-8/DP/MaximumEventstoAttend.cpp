/**
 * Events are exclusive
 *
 * {{1,2,4},{3,4,3},{2,3,1}}
 * k=2
 * start time ke basis pe sort kr dena chahiye interval based questions ko
 * jitna k h utne event hi kr skte h
 * agar maan lo same day pe koi event khtm aur koi shuru ho rha h toh dono nhi le skte
 *
 *
 * maan lo 1,2,4  choose kiya
 * firr 3,4,3  nhi liya
 * firr 3,4,3 le liya
 * toh max porfit hua 4+3 ==7
 * toh yhi lenge
 * take aur skip karenge toh tree dirgam
 * recursion jaisa lag rha
 * take krne ke baad whi lenge agla jo pichle end date ke baad ho
 * toh end date leke chalenge
 *
 */

class Solution
{
public:
    int maxsum = INT_MIN;

    void solve(vector<int> &events, int idx,int currend,  int k,int sum,int &count)
    {

        if (count == k || idx>=events.size())
            return;


        if (events[idx][0] > currend)
        {
            sum += events[idx][2];
            maxsum = max(sum, maxsum);
            currend = events[idx][1];
            solve(events, idx + 1, currend, k, count + 1);
            sum -= events[idx][2];
        }
        else
        {
            solve(events, idx + 1, currend, k, sum, count + 1);
           
        }
    }




    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end());

        int sum = 0, count = 0;
        solve(events, 0,-1, k, sum, count);

        return maxsum;
    }
};