/*
 * GOOGLE - MEETING ROOMS 3
 *
 * You're given a 2D integer array of meetings.
 * Each meeting is in half-closed form: [start, end) — which means it includes the start time but not the end time.
 * All start times are **unique**.
 *
 * Room allocation should follow 3 rules:
 * 1. Each meeting will take place in the **lowest numbered unused room**.
 * 2. If **no room** is available, the meeting will be **delayed** until a room becomes available.
 * 3. Even if delayed, the **duration of the meeting remains the same**.
 *    When multiple meetings are delayed, priority is given to the one with **earlier original start time**.
 *
 *
 * Example:
 * Number of rooms = 3
 * Meetings = [(1, 20), (2, 10), (3, 5), (6, 8), (4, 9)]
 *
 * Step 1: Sort the meetings by start time.
 * Sorted meetings: 
 *   m1 = (1, 20)
 *   m2 = (2, 10)
 *   m3 = (3, 5)
 *   m4 = (4, 9)
 *   m5 = (6, 8)
 *
 * Assign rooms step-by-step:
 * - m1 => assign to room 1
 * - m2 => check if room 1 is free by 2 → NO → try next room → room 2 is free → assign m2 to room 2
 * - m3 => check room 1 → still busy → room 2 → busy → room 3 → free → assign m3 to room 3
 *
 * Now:
 * room1: m1 = (1, 20)
 * room2: m2 = (2, 10)
 * room3: m3 = (3, 5)
 *
 * Remaining:
 * m4 = (4, 9)
 * m5 = (6, 8)
 *
 * m4 comes before m5, so we try to allocate m4 first.
 * All rooms are busy at time 4, so we wait for the **first room to become free**.
 * - m3 in room 3 ends at 5 → room 3 becomes free at 5 → assign m4 to room 3 starting at 5
 * - m4 has duration 5 (9 - 4), so new end = 5 + 5 = 10
 *
 * Now:
 * room3 = (5, 10)
 *
 * m5 now needs a room:
 * - All rooms are busy at 6 → m2 ends at 10 (room 2), m4 also ends at 10 (room 3)
 * - We pick the **lowest numbered room that becomes free first**, which is room 2 → assign m5 to room 2 starting at 10
 * - m5 has duration = 2 (8 - 6), so new end = 10 + 2 = 12
 *
 * Final room usage:
 * room1: (1, 20)
 * room2: (2, 10) → (10, 12)
 * room3: (3, 5) → (5, 10)
 *
 *
 * Implementation Strategy:
 * - Use a min-heap or array of size `n` to track current meeting end times in rooms.
 * - For each meeting (sorted by start time):
 *    - Check if any room is free at the start time.
 *      - If yes: assign it to the lowest-numbered available room.
 *      - If no: find the room whose meeting ends the earliest.
 *              Delay the current meeting to that time and assign that room.
 * - Keep updating room's end time based on assignment.
 *
 * Key Steps:
 * 1. Sort the meetings by start time.
 * 2. For each meeting:
 *    a) Try to find the first room that becomes available.
 *    b) If available, assign.
 *    c) Else, wait until the earliest room gets free.
 */



 //Approach-1 (Brute Force - Do as said)
//T.C : O(mlogm +m*n) , where Let n = number of rooms, m =  number of meetings
//S.C : O(n)
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings), end(meetings)); //sort by starting time of meetings

        vector<int> roomsUsedCount(n, 0); //Each room is used 0 times in the beginning
        vector<long long> lastAvailableAt(n, 0); //Each room will be last available at
        

        for(vector<int>& meet : meetings) {
            int start  = meet[0];
            int end    = meet[1];
            bool found = false;

            long long EarlyEndRoomTime = LLONG_MAX;
            int EarlyEndRoom     = 0;

            //Find the first available meeting room
            for(int room = 0; room < n; room++) {
                if(lastAvailableAt[room] <= start) {
                    found = true;
                    lastAvailableAt[room] = end;
                    roomsUsedCount[room]++;
                    break;
                }

                if(lastAvailableAt[room] < EarlyEndRoomTime) {
                    EarlyEndRoom = room;
                    EarlyEndRoomTime = lastAvailableAt[room];
                }
            }

            if(!found) {
                lastAvailableAt[EarlyEndRoom] += (end - start);
                roomsUsedCount[EarlyEndRoom]++;
            }

        }

        int resultRoom = -1;
        int maxUse     = 0;  
        for(int room = 0; room < n; room++) {
            if(roomsUsedCount[room] > maxUse) {
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};



/**
 * What was the bottleneck of your approach
 * ye tha ki saari rooms pe traverse krna hi krna h 
 * jisme time lag rha tha O(M)
 * rooms ka size bhot bada hota toh bhot dikkat hoti  
 * toh hum rooms mein meeting start aur end tore kr lete h
 * taaki sort kr sake taaki kis room mein jana h dhundne aasan ho
 * ab maan lo nayi meeting aayi toh uska time toh alag h 
 * toh baar baar sort krna pad rha h 
 * sort kr rhe h ye bhi bulky task h 
 * toh kuch use karo 
 * so we will use minheap 
 * min heap mein 2 chizien hi store karnege end time aur room
 * ab meetings ko sort krke heap mein daal 
 * hepa mein aaya 0,20 
 * room 0 endtime 20
 * ab next meeting pe aao
 * firts room toh milega nhi 
 * par ab usko kaise pata kis room mein jana h 
 * toh hum uss room mein jayenge jiski value sabse kam ho 
 * 
 */