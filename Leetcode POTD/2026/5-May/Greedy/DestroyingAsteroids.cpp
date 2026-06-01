/*
 * Approach 1 : Sorting + Greedy
 *
 * Intuition:
 * Always destroy the smallest asteroid first.
 * Smaller asteroids increase our mass and help us destroy bigger asteroids later.
 *
 * TC : O(n log n)
 *      -> sorting = O(n log n)
 *      -> traversal = O(n)
 *
 * SC : O(log n)
 *      -> recursion stack used by STL sort
 *
 */

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {

        long long m = mass;

        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        for (int i = 0; i < n; i++)
        {
            if (asteroids[i] <= m)
            {
                m += asteroids[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/*
 * Approach 2 : Frequency Array / Counting Sort Idea
 *
 *
 * TC : O(n + maxAsteroid)
 *      -> find max asteroid = O(n)
 *      -> build frequency = O(n)
 *      -> traverse frequency array = O(maxAsteroid)
 *
 * SC : O(maxAsteroid)
 *      -> frequency array
 *

 */
class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        int maxasteroid = 0;
        for (int a : asteroids)
        {
            if (a > maxasteroid)
                maxasteroid = a;
        }
        vector<int> freq(maxasteroid + 1, 0);
        for (int a : asteroids)
        {
            freq[a]++;
        }
        long long currentmass = mass;
        for (int i = 1; i <= maxasteroid; i++)
        {
            if (freq[i] > 0)
            {
                if (i > currentmass)
                    return false;
                currentmass += (long long)i * freq[i];
            }
        }
        return true;
    }
};