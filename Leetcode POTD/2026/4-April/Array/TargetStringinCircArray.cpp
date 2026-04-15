class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {

        int n = words.size();
        int minDist = INT_MAX;

        // ! move right
        int j = startIndex;
        for(int step = 0; step < n; step++)
        {
            if(words[j] == target)
            {
                minDist = min(minDist, step);
                break;
            }
            j = (j + 1) % n;
        }

        // ! move left
        j = startIndex;
        for(int step = 0; step < n; step++)
        {
            if(words[j] == target)
            {
                minDist = min(minDist, step);
                break;
            }
            j = (j - 1 + n) % n;
        }

        return (minDist == INT_MAX) ? -1 : minDist;
    }
};