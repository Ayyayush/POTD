/**
 * *Find Original Strings::= 2
 * 
 * Thought Process-
 * Hume dhyaan uska rakhna h jo consecutively repeat ho rha h 
 * atleast k size ke kitne strings ban skte h ye dekhna h 
 * 
 * eg ::= aabbcc    k==3
 * 
 * abc,abcc,abbc,abbcc
 * abc,aabcc,aabbc,aabbcc
 * total ==8 mila
 * 
 * hum dekhenge ki kis character se kitne option mil rhe h 
 * aa  ,bb ,cc  
 * aise toh lag rha h ki directly 2*2*2 == 8 kr do aa gya answer
 * 
 * par dikkat aise h ki maan lo k=5 h ab dekho
 * valid kaun se bache 
 * abbcc,aabbc,aabbcc,aabcc
 * answer ab chaihiye 5 toh directly nhi ho rha 
 * 
 * dekho total unique charcters kitne h a,b,c ==3 
 * ab maan lo sirf aaaaa print kiya toh 
 * ab maan lo k==unique characters count h toh ..
 * jitne bhi possible strings banenge saare characters use krke sbhi valid honge 
 * toh ye ek base case h 
 * if total unique chaarcetrs == k 
 * total answer hoga all possible with including all unique characters atleast once 
 * else
 * answer == total - invalid strings count 
 * *My aim is to find total valid strings now 
 * 
 * 
 * hamare paas har charcter ke liye possibility h ki wo character valid h ya nhi 
 * aur include krate hue jaane pe ye condition satisfy hona chahiye ki >= k 
 * hum character ki 1+ se jyada freq leke sab possible dekhenge 
 * take i to iterate in freq 
 * count->  to count how many characetrs we took till now
 * 
 * solve(0,0,freq,k)
 * {
 * result=0;
 * for()
 * }
 * 
 * 
 * 
 * 
 */


//Approach-1 (Recursion + Memoization) - TLE
//T.C : O(n*k*maxFreq), n = total unique characters, maxFreq = maximumFrequency of a character
//S.C : O(n*k)
class Solution {
public:
    int M = 1e9+7;
    vector<vector<int>> t;

    int solve(int i, int count, vector<int>& freq, int k) {
        if(i >= freq.size()) {
            if(count < k)
                return 1; //found invalid string
            return 0;
        }

        if(t[i][count] != -1) {
            return t[i][count];
        }

        long long result = 0;

        for(int take = 1; take <= freq[i]; take++) {
            if(count + take < k) {
                result = (result + solve(i+1, count+take, freq, k)) % M;
            } else {
                break;
            }
        }

        return t[i][count] = result;
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        int n = freq.size();
        t.assign(n+1, vector<int>(k+1, -1)); //invalid krne k lie count should be less than k < k
        //We have to now find count of invalid strings 
        long long invalidCount = solve(0, 0, freq, k);

        return (P - invalidCount + M) % M;


    }
};


 
 