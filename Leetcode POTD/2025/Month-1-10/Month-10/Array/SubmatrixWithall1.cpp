/**
 * Count Submatrices with All 1's 
 * iss question ke bhot variants h
 * 
 * eg =  {1,0,1}
 *       {1,1,0}
 *       {1,1,0}
 * 
 * single 1 ... 1*1 submatix honge 
 * 
 * m*n size ka 2-d array h
 * 
 * pehle dekhte h ki agar 1-d array hota toh kaise solve krte
 * 
 * 1,0,1,1,1,0
 * it is a 1*5 submatrix 
 * ab aise submatrix dhundo jisme sirf 1 ho 
 * ye toh uss question ki tarah ban gya count subarrays with all 0 
 * 
 * int k=0
 * while(nums[i]==1)
 * {
 * k++
 * count+=k;
 * i++;
 * }
 * 
 * aise total nikal jayega 
 * ye bhi kr skte h ki jitne consectuive 1 dikh rha h uski value add krte chale jao
 * k++ ya k+=1 kr do whi baat h 
 * ye bhi keh skte h 
 * how many submatrices are there ending at that particular index 
 * 
 * ab problem ye ho gya ki ye 2-d array ban gya h 
 * 
 * maan lo 1,0,1 h toh ans hoga 2 
 * 
 * ab   1,0,1
 *      1,1,0      
 * ye sirf rows ko dekhe toh 1-d array hi h na 
 * toh niche wale row ka ans hoga 3 
 * ab dono ko sath kaise nikala jaye 
 * ab aise submatix dekho jo row 0 se start ho rhe h aur row 1 tak ja rhe h
 * 
 * col 0 mein upar bhi 1 niche bhi 1 ...start aur end bhi shi toh +1
 * 
 * aise hi similar tarike mein row 1 aur row 12 ko dekehnge 
 * 
 * thoda sa observe krne pe ek chiz relaise hoga 
 * ki 0 aa rh ah beech mein toh nhi dhund pa rhe h submatrix 
 * agar expand kr pate submatix ko 2*2 ka bana pate 
 * toh count =3 ho jata 
 * aise hi badhte jata 
 * har column mein bas itna hi check krna h ki 1 bhi 0 h kya
 * isse ye pata chalta h ki 1-d array ka trick 2-d ke liye bhi kaam kr skta h 
 * 
 * 
 * 
 * 
 * firr uske baad row 0 , row 1 , row 2 ko dkehnge ..... and so on 
 * 
 * 
 * 
 * 
 * 
 * 
 */

 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to count subarrays with consecutive 1s
    int darraycount(vector<int>& vec) {
        int cons = 0;                  // consecutive 1s count
        int subCount = 0;              // total subarray count

        for (int &val : vec) {
            if (val == 0) {
                cons = 0;              // reset consecutive streak
            } else {
                cons++;                // extend consecutive streak
            }
            subCount += cons;          // add current streak length
        }

        return subCount;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;

        // Fix starting row
        for (int startrow = 0; startrow < m; startrow++) {
            vector<int> vec(n, 1);     // initially assume all 1s

            // Expand downward row by row
            for (int endrow = startrow; endrow < m; endrow++) {
                for (int col = 0; col < n; col++) {   // should go till n
                    vec[col] = vec[col] & mat[endrow][col]; 
                }

                // Count submatrices formed with current row window
                result += darraycount(vec);
            }
        }

        return result;
    }
};
