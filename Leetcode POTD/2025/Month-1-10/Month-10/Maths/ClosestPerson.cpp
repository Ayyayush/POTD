// T.C == O(1)
//S.C == O(1)+O(1) == O(1)

class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int dist1 = abs(x - z);
        int dist2 = abs(y - z);

        if (dist1 == dist2)
            return 0;
        else if (dist1 < dist2)
            return 1;
        else
            return 2;
    }
};