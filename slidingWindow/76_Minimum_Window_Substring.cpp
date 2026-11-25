problem statement:

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 



class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n)
            return "";

        vector<int> freq1(128, 0);
        vector<int> freq2(128, 0);
        int start_index = -1;
        int min_length = INT_MAX;
        int count = 0;

        for (int i = 0; i < m; i++) {
            int index = t[i];

            if (freq1[index] == 0)
                count++;

            freq1[index]++;
        }

        int curr = 0, prev = 0;

        while (curr < n) {
            int index = s[curr];
            freq2[index]++;

            if (freq2[index] == freq1[index]) {
                count--;
            }

            while (count == 0 && prev <= curr) {
                int length = curr - prev + 1;

                if (length < min_length) {
                    start_index = prev;
                    min_length = length;
                }

                int index = s[prev];
                freq2[index]--;

                if (freq2[index] < freq1[index]) {
                    count++;
                }

                prev++;
            }

            curr++;
        }

        return start_index != -1
                   ? s.substr(start_index, min_length)
                   : "";
    }
};