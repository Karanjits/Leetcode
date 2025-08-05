#include <iostream>
using namespace std;
#include <string>;
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> charIndex; //unordered hashmap to store each character of string as key and its position as the value
        
        int start = 0;
        int maxLength =0;

        for(int end =0; end<s.size() ; ++end) {

            char currentchar = s[end];

            if(charIndex.count(currentchar) && charIndex[currentchar] >=start) {

                start = charIndex[currentchar] +1;
            }

            charIndex[currentchar] = end;

            maxLength = max(maxLength, end - start +1);

            
        }

        return maxLength;
    }
};