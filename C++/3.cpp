/**
 * @author github.com/akappakappa
 *
 * Given a string s, find the length of the longest substring without repeating characters.
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;
        int gap[2] = {0, 0};
        int longest = 0;
        for (; gap[1] < s.length(); gap[1]++)
        {
            auto indexIterator = map.find(s[gap[1]]);
            if (indexIterator != map.end() && indexIterator->second >= gap[0]) gap[0] = indexIterator->second + 1;
            longest = max(longest, gap[1] - gap[0] + 1);
            map[s[gap[1]]] = gap[1];
        }
        return longest;
    }
};