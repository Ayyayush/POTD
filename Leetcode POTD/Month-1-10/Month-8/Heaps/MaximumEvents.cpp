/**
 * MAXIMUM NO OF EVENTS
 * 
 * events =[[1,2],[2,3],[4,5]]
 * iss tarah ke problem jisme interval de rakha ho 
 * interval diya ho toh mann mein soritng jarur chalna chahiye
 * based on the starting day sort kar denge 
 * 
 * ab dekh0
 * day 1   - first
 * day 2   - second
 * day 3   - third
 * 
 * 
 * ab dekho given date pe dekho kitne events chal rhe h 
 * 
 * for any day if i have an option to select among events
 * i will choose the one that ends earlier similar to greedy problems 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * *Events = [(1,1), (1,4), (2,2), (3,4), (4,4)]
 * Index   =   0       1       2       3       4
 *
 * Each event is of the form (start_day, end_day)
 * We are tracking which days are covered by which events.
 *
 * d1    |←───────────Event 1──────────→|
 *       |←─Event 0─→|
 *
 * d2    |←───────────Event 1──────────→|
 *             |←─Event 2─→|
 *
 * d3    |←───────────Event 1──────────→|
 *                         |←─────Event 3────→|
 *
 * d4    |←───────────Event 1──────────→|
 *                         |←─────Event 3────→|
 *                                   |←─Event 4─→|
 *
 * Legend:
 * - d1 to d4: Days
 * - Arrows indicate the span of each event across the days
 * - Multiple events can overlap on the same day
 *
 * Useful when solving problems like:
 * - Maximum number of non-overlapping events
 * - Minimum rooms required (interval scheduling)
 * - Event booking within limited time windows

 * maan lo mere paas h 1,1   1,4
 * day 1 pe 1,1 kar liya   kyunki pehle finish ho rha tha 
 * day ==2 ho gya    1,4 bacha h aur 2,2 bhi aa gya  
 * toh ab wo finish karo jo pehle end ho rha h
 * toh firr se ab 2,2 choose kiya
 * ab day ==3 ho gya 
 * ab day 3 pe firr 2 option h    1,4    3,4
 * ab dono ka ending date same h toh koi dikkat  nhi koi bhi choose kar lo 
 * 1,4 choose kar liya
 * 
 * ab day==4 h foirrse 2 option h    3,4    4,4
 * ab firr se 3,4 choose kar liya
 * ab day ==5 h 
 * par ab ending date hi 4 h par ending date 4 h toh nhi choose kr skte 
 * 
 * so if day is greater than ending day we will not choose 
 * so maximum events here ==4 
 * 
 * 
 * 
 * 
 * * Events eg-2    5,10    15,20
 * ab maan lo isme day <=4 se start toh kar nhi skte 
 * already sorted hi h 
 * ab day =5 se hi start kr skte h
 * direct day ko sorted array ke index 0 ke start day ke barabar le lo 
 * day =5 h    5,10 ko pick kr liya kyunkiakele  yhi option tha 
 * day =6 ho gya maan lo par  event toh 15th day se start ho rha
 * ab koi aur option hi nhi h 
 * toh na chahte hue bhi day ko badhana hoga
 * 
 * ab sawaal aata h ki mai store kaha kr rha hoon ki kaun earliest end ho rha h
 * pata kaise chalega
 * toh ek min heap le lo
 * min heap bana lenge 
 * aur min heap mein end day se mtlb h  toh bas wo hi daalenge 
 * 
 * 
 * 
 * 
 * 
 * 
 */


 //Approach (Using Sorting and heap and hreedily picking the ones ending earliest)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(begin(events), end(events));

        priority_queue<int, vector<int>, greater<int>> pq; //min-heap
        int day = events[0][0]; //5
        int i   = 0;
        int count = 0; //result number of events attended

        while(!pq.empty() || i < n) {
            
            if(pq.empty()) {
                day = events[i][0];
            }

            while(i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()) {
                pq.pop(); //1 event attended on this day
                count++; //counting the result
            }

            day++;

            //skip those events whose endDay < day
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return count;
    }
};
