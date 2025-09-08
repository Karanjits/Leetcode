#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// class Solution {
// public:

// //O(n) Solution 1
//     int lengthOfLongestSubstring(string s) {

//         if(s.length() ==0) {
//             return 0;
//         }

//         int start = 0; 
//         int maxLength = 0;
//         unordered_map<char,int> charIndex;

//         for(int end=0; end<s.length();++end) {
//             char current = s[end];
//             if(charIndex.count(current) ) {
//                 start = charIndex[current] +1;
//             }

//             charIndex[current] = end;

//             maxLength = max(maxLength, end-start+1);
//         }


//         return maxLength;
//         }

// };

// int main() {
//     Solution sol;

//     // Test cases: {input, expected output}
//     vector<pair<string,int>> tests = {
//         {"", 0},                // Empty string → length 0
//         {"a", 1},               // Single char → length 1
//         {"aaaa", 1},            // All same → length 1
//         {"abcabcbb", 3},        // "abc" → length 3
//         {"bbbbb", 1},           // "b" → length 1
//         {"pwwkew", 3},          // "wke" → length 3
//         {"dvdf", 3},            // "vdf" → length 3
//         {"anviaj", 5},          // "nviaj" → length 5
//         {"tmmzuxt", 5},         // "mzuxt" → length 5
//         {"abcde", 5}            // All unique → full length 5
//     };

//     // Run all tests
//     for (auto &test : tests) {
//         string input = test.first;
//         int expected = test.second;
//         int result = sol.lengthOfLongestSubstring(input);

//         cout << "Input: \"" << input 
//              << "\" | Expected: " << expected 
//              << " | Got: " << result 
//              << (result == expected ? "  [PASS]" : "  [FAIL]") 
//              << endl;
//     }

//     return 0;
// }

//solution 2
int lengthOfLongestSubstring(string s) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;

    for (int i = 0; i < s.size(); i++) {
        if (dict[s[i]] > start) {
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

int main () {
    vector<string> testCases = {
        "a",
        "aa",
        "ab",
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "",
        "abcdef",
        "abba",
        "dvdf",
        "!@#$%^&*()"
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i+1 
             << " (\"" << testCases[i] << "\"): "
             << lengthOfLongestSubstring(testCases[i]) 
             << endl;
    }

    return 0;
}