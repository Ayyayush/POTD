class Solution {
public:

    // ! APPROACH : Sorting + Binary Search + Prefix/Suffix Minimum
    // ! T.C. : O((L + W)log(L + W))
    // ! S.C. : O(L + W)

    int landToWater(vector<int>& landStartTime,
                    vector<int>& landDuration,
                    vector<int>& waterStartTime,
                    vector<int>& waterDuration)
    {
        int m = waterStartTime.size();

        vector<pair<int,int>> water(m);

        for(int i = 0; i < m; i++)
        {
            water[i] = {waterStartTime[i], waterDuration[i]};
        }

        sort(water.begin(), water.end());

        vector<int> prefixMinDuration(m);
        vector<int> suffixMinFinish(m);

        prefixMinDuration[0] = water[0].second;

        for(int i = 1; i < m; i++)
        {
            prefixMinDuration[i] =
                min(prefixMinDuration[i - 1], water[i].second);
        }

        suffixMinFinish[m - 1] =
            water[m - 1].first + water[m - 1].second;

        for(int i = m - 2; i >= 0; i--)
        {
            suffixMinFinish[i] =
                min(suffixMinFinish[i + 1],
                    water[i].first + water[i].second);
        }

        int ans = INT_MAX;

        for(int i = 0; i < landStartTime.size(); i++)
        {
            int landFinish =
                landStartTime[i] + landDuration[i];

            int pos =
                upper_bound(
                    water.begin(),
                    water.end(),
                    make_pair(landFinish, INT_MAX)
                ) - water.begin();

            if(pos > 0)
            {
                ans = min(
                    ans,
                    landFinish + prefixMinDuration[pos - 1]
                );
            }

            if(pos < m)
            {
                ans = min(
                    ans,
                    suffixMinFinish[pos]
                );
            }
        }

        return ans;
    }

    int waterToLand(vector<int>& landStartTime,
                    vector<int>& landDuration,
                    vector<int>& waterStartTime,
                    vector<int>& waterDuration)
    {
        int n = landStartTime.size();

        vector<pair<int,int>> land(n);

        for(int i = 0; i < n; i++)
        {
            land[i] = {landStartTime[i], landDuration[i]};
        }

        sort(land.begin(), land.end());

        vector<int> prefixMinDuration(n);
        vector<int> suffixMinFinish(n);

        prefixMinDuration[0] = land[0].second;

        for(int i = 1; i < n; i++)
        {
            prefixMinDuration[i] =
                min(prefixMinDuration[i - 1], land[i].second);
        }

        suffixMinFinish[n - 1] =
            land[n - 1].first + land[n - 1].second;

        for(int i = n - 2; i >= 0; i--)
        {
            suffixMinFinish[i] =
                min(suffixMinFinish[i + 1],
                    land[i].first + land[i].second);
        }

        int ans = INT_MAX;

        for(int i = 0; i < waterStartTime.size(); i++)
        {
            int waterFinish =
                waterStartTime[i] + waterDuration[i];

            int pos =
                upper_bound(
                    land.begin(),
                    land.end(),
                    make_pair(waterFinish, INT_MAX)
                ) - land.begin();

            if(pos > 0)
            {
                ans = min(
                    ans,
                    waterFinish + prefixMinDuration[pos - 1]
                );
            }

            if(pos < n)
            {
                ans = min(
                    ans,
                    suffixMinFinish[pos]
                );
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration)
    {
        int result1 =
            landToWater(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            );

        int result2 =
            waterToLand(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            );

        return min(result1, result2);
    }
};

class Solution {
public:

    // ! APPROACH : Sorting + Binary Search + Prefix/Suffix Minimum
    // ! T.C. : O((L + W)log(L + W))
    // ! S.C. : O(L + W)

    int landToWater(vector<int>& landStartTime,
                    vector<int>& landDuration,
                    vector<int>& waterStartTime,
                    vector<int>& waterDuration)
    {
        int m = waterStartTime.size();

        vector<pair<int,int>> water(m);

        for(int i = 0; i < m; i++)
        {
            water[i] = {waterStartTime[i], waterDuration[i]};
        }

        sort(water.begin(), water.end());

        vector<int> prefixMinDuration(m);
        vector<int> suffixMinFinish(m);

        prefixMinDuration[0] = water[0].second;

        for(int i = 1; i < m; i++)
        {
            prefixMinDuration[i] =
                min(prefixMinDuration[i - 1], water[i].second);
        }

        suffixMinFinish[m - 1] =
            water[m - 1].first + water[m - 1].second;

        for(int i = m - 2; i >= 0; i--)
        {
            suffixMinFinish[i] =
                min(suffixMinFinish[i + 1],
                    water[i].first + water[i].second);
        }

        int ans = INT_MAX;

        for(int i = 0; i < landStartTime.size(); i++)
        {
            int landFinish =
                landStartTime[i] + landDuration[i];

            int pos =
                upper_bound(
                    water.begin(),
                    water.end(),
                    make_pair(landFinish, INT_MAX)
                ) - water.begin();

            if(pos > 0)
            {
                ans = min(
                    ans,
                    landFinish + prefixMinDuration[pos - 1]
                );
            }

            if(pos < m)
            {
                ans = min(
                    ans,
                    suffixMinFinish[pos]
                );
            }
        }

        return ans;
    }

    int waterToLand(vector<int>& landStartTime,
                    vector<int>& landDuration,
                    vector<int>& waterStartTime,
                    vector<int>& waterDuration)
    {
        int n = landStartTime.size();

        vector<pair<int,int>> land(n);

        for(int i = 0; i < n; i++)
        {
            land[i] = {landStartTime[i], landDuration[i]};
        }

        sort(land.begin(), land.end());

        vector<int> prefixMinDuration(n);
        vector<int> suffixMinFinish(n);

        prefixMinDuration[0] = land[0].second;

        for(int i = 1; i < n; i++)
        {
            prefixMinDuration[i] =
                min(prefixMinDuration[i - 1], land[i].second);
        }

        suffixMinFinish[n - 1] =
            land[n - 1].first + land[n - 1].second;

        for(int i = n - 2; i >= 0; i--)
        {
            suffixMinFinish[i] =
                min(suffixMinFinish[i + 1],
                    land[i].first + land[i].second);
        }

        int ans = INT_MAX;

        for(int i = 0; i < waterStartTime.size(); i++)
        {
            int waterFinish =
                waterStartTime[i] + waterDuration[i];

            int pos =
                upper_bound(
                    land.begin(),
                    land.end(),
                    make_pair(waterFinish, INT_MAX)
                ) - land.begin();

            if(pos > 0)
            {
                ans = min(
                    ans,
                    waterFinish + prefixMinDuration[pos - 1]
                );
            }

            if(pos < n)
            {
                ans = min(
                    ans,
                    suffixMinFinish[pos]
                );
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration)
    {
        int result1 =
            landToWater(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            );

        int result2 =
            waterToLand(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            );

        return min(result1, result2);
    }
};