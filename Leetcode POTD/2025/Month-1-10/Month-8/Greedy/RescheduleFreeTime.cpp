/**
 * RESCHEDULE MAXIMUM FREE TIME
 * 
 * 
 * noncoverlapping meetings
 * reschedule krna h atmost k meetings 
 * taaki lonhgest contingous period nof free time mile 
 * yani aisa time jab meeting na ho aur longest mile
 * relative order same rehna chahiye aur non overalapping hona chaihiye
 * 
 * eg ::  m1         ,m2
 *        m1,   m2
 * yha shift kiya par order change nhi hua h
 * 
 * eventtime=5   k=1
 * starttime   = [1,3]
 * endtime     = [2,5]
 * 
 * intuitive wy aayega dimaag mein ki sabko ek sath hi shift kar do simple 
 * 
 * 
 * 
 * 
 * 
 *  * Total event time = 10
 * You are allowed to choose K = 2 non-overlapping events.
 * Each event is represented by a [startTime, endTime] interval.
 *
 * Input:
 *   startTime = [0, 2, 9]
 *   endTime   = [1, 4, 10]
 *   => Events: E1 = [0,1], E2 = [2,4], E3 = [9,10]
 *
 * Timeline Diagram:
 *
 *  Time:   0   1   2   3   4   5   6   7   8   9  10
 *          |---E1---|       |-------E2-------|     |---E3---|
 *                  F1 ------------------------>
 *                          F2 ------------------------>
 *
 * Explanation:
 * - F1: Choosing E1 first, then choosing E3 later → F1 = 1 (duration of E1)
 * - F2: Choosing E2 first, then choosing E3 later → F2 = 5 (duration of E2)
 * - These two do not overlap with E3.
 *
 * States:
 * -------
 * prev = { F1, F2 }
 * current = { F1 + F2 }
 *
 * Values:
 *   F1 = 1
 *   F2 = 5
 *   F1 + F2 = 6 ✔️ (Valid combination of two non-overlapping events)
 *
 * Goal:
 * - Maximize total event time from at most 2 non-overlapping intervals
 * - Final Answer = 6
 * 
 * 
 * hume dikhta h ki k shifts krke k+1  freegaps ko combine kr skte h
 * k ki value h jitni utne hi shifts kr skte h 
 * hume bas free time f1,f2,f3 nikaal lena h 
 * aur dekhna h ki k+1 size ka contiinous gap jo hoga
 * usme best sum kisse milega 
 * aise gaps shift krne se hume dikhta h ki ye sliding window problem h 
 * 

 *         
 */