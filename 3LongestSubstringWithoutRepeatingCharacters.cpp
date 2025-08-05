#include <iostream>
using namespace std;
#include <string>;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];

            // If the character was seen and is inside the current window
            if (charIndexMap.count(currentChar) && charIndexMap[currentChar] >= start) {
                start = charIndexMap[currentChar] + 1; // move start to avoid duplicate
            }

            // Update the latest index of the character
            charIndexMap[currentChar] = end;

            // Update the maximum length found so far
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};