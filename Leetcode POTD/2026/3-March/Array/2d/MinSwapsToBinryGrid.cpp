/**
 * Minimum Swaps to arrnage a binary grid 
 * leetcode 1536 
 * 
 * hume mai dignoal ek par ke saaare elts ko 0 krna h 
 * probem cdescriiton :
 * 
 * 
 * thoug process example 1 : leetcode exmqple 1 same 
 * Example 1:


Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3
 * ab jo mian digonal h n a
 * uske upa rke jitne bhi cels h unko 0 bnate h 
 * ab pehle row no 0 se puchte h 
 * tumhe kitne 0 chahiye 
 * 3-1 =2 
 * 2nd row mein 3-2 =1 chhiye  bcz dgrmnal = 2nd col in 2n row 
 * 3rd row mein 0 hhaiye hoga aise 
 * hu row swap rk skte h na ki particular columns of a r or clumsn itself 
 * hum ek rocrod mintina kr lete h 
 * ki kis row ko kitn 0 chhaye dgronal ke upar 
 * 
 * toh ba dkeho row 1 ko 2 0 chaiye 
 * toh ab ai row dekho jiske end mein 0 = 3-need >= k
 * aur dhyaan rkaho hum djane torw smk h swap k skt eh 
 * erest row ko pakdnge agar muliple rows staisfy kr rhe h 
 * isse min waps lagenge 
 * 
 * toh 
 * ab swa krne ke baad dekho kya ho rha h 
 * 
 * 
 * 
 */

/************************************************** C++ **************************************************/
//Approach (Siilar to Bubble Sort - Find best candidate and swap)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(); // rows == columns

        vector<int> endZeros(n, 0);
        //endZeros[i] = count of consecutive 0s from the end of ith row

        for(int i = 0; i < n; i++) {
            int j = n-1; //start from end

            int count = 0;
            while(j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }

            endZeros[i] = count;
        }


        int steps = 0;

        for(int i = 0; i < n; i++) {
            
            int need = n - i - 1;

            int j = i;

            while(j < n && endZeros[j] < need) {
                j++;
            }

            if(j == n) {
                return -1;
            }

            steps += j-i;

            while(j > i) {
                swap(endZeros[j], endZeros[j-1]);
                j--;
            }

        }

        return steps;
        
    }
};
