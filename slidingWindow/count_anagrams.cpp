2514. Count Anagrams
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.

A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.

For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.
Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: s = "too hot"
Output: 18
Explanation: Some of the anagrams of the given string are "too hot", "oot hot", "oto toh", "too toh", and "too oht".
Example 2:

Input: s = "aa"
Output: 1
Explanation: There is only one anagram possible for the given string.


// code 

timicomplexity nlogn


#define MOD 1000000007

class Solution {
public:
    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1) {
                res = (res * a) % MOD;
            }

            a = (a * a) % MOD;
            b /= 2;
        }

        return res;
    }

    long long factorial(int n) {
        long long ans = 1;

        for (int i = 1; i <= n; i++) {
            ans = (ans * i) % MOD;
        }

        return ans;
    }

    long long calculatePermutation(string &word) {

        int n = word.length();

        long long total = factorial(n);

        map<char, int> freq;

        for (char ch : word) {
            freq[ch]++;
        }

        for (auto p : freq) {

            long long fact = factorial(p.second);

            long long inverse = power(fact, MOD - 2);

            total = (total * inverse) % MOD;
        }

        return total;
    }

    int countAnagrams(string s) {

        stringstream ss(s);

        string word;

        long long ans = 1;

        while (ss >> word) {

            long long total = calculatePermutation(word);

            ans = (ans * total) % MOD;
        }

        return ans;
    }
};



//optimize solution  n + logn



#define MOD 1000000007

class Solution {
public:
    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b /= 2;
        }

        return res;
    }

    int countAnagrams(string s) {

        int N = s.length();

        vector<long long> fact(N + 1);
        vector<long long> invFact(N + 1);

        // Precompute factorials
        fact[0] = 1;

        for (int i = 1; i <= N; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        // Precompute inverse factorials
        invFact[N] = power(fact[N], MOD - 2);

        for (int i = N; i >= 1; i--) {
            invFact[i - 1] = (invFact[i] * i) % MOD;
        }

        stringstream ss(s);
        string word;

        long long ans = 1;

        while (ss >> word) {

            int n = word.length();

            vector<int> freq(26, 0);

            for (char ch : word) {
                freq[ch - 'a']++;
            }

            long long ways = fact[n];

            for (int count : freq) {
                ways = (ways * invFact[count]) % MOD;
            }

            ans = (ans * ways) % MOD;
        }

        return ans;
    }
};

