
class Solution
{
public:
    long long countVowels(string word)
    {
        int n = word.length();
        long long result = 0; // Overflow avoid karne ke liye long long

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; // Vowel set

        for (int i = 0; i < n; i++)
        {
            if (vowels.count(word[i]))
            {
                result += (long long)(i + 1) * (n - i); // Substrings me count
            }
        }

        return result;
    }
};