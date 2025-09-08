#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        int stringSize = s.size();

        if(stringSize == 0) {
            return "";
        }
        if(stringSize == 1) {
            return s;
        }
        int start = 0;
        int maxLen = 1;
        for(int i=1 ; i<stringSize; i++) {
            

            //For Even Palindrome such as CAAC
            int l=i-1;
            int r=i;
            while(l>=0 && r<stringSize && s[l] == s[r]) {
                if(r-l+1 > maxLen) {
                    maxLen = r-l+1;
                    start =l;
                }
                l--;
                r++;
            }

            //For odd palindrome such as CAC

            l=i-1;
            r=i+1;

            while(l>=0 && r<stringSize && s[l] == s[r]) {
                if(r-l+1 > maxLen) {
                    maxLen = r-l+1;
                    start =l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start,maxLen);
        
}
};

int main() {
    Solution sol;
    string S = "babad";
    cout << sol.longestPalindrome(S) << endl;
    return 0;
}