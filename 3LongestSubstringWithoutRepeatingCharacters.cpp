#include <iostream>
using namespace std;
#include <string>
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

 int main() {
        Solution sol;

        int test1 = sol.lengthOfLongestSubstring("helloworld");
        int test2 = sol.lengthOfLongestSubstring("thisisateststring");


        cout<<"TEST 1" << "-" <<test1<<endl;
        cout<<"TEST 2" << "-"<< test2<<endl;


         
    cout << sol.lengthOfLongestSubstring("helloworld") << endl;  // Expected: 5 ("world")
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;    // Expected: 3 ("abc")
    cout << sol.lengthOfLongestSubstring(" ") << endl; 
    }