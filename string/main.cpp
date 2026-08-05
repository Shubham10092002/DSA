//. Find the Index of the First Occurrence in a String

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int pos = -1;

        if (haystack.find(needle) != string ::npos)
        {
            pos = haystack.find(needle);
        }
        return pos;
    }
};

// longest palindromic substring

class Solution
{
public:
    bool palindron(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    string longestPalindrome(string s)
    {
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (palindron(s, i, j))
                {
                    string t = s.substr(i, j - i + 1);
                    ans = t.size() > ans.size() ? t : ans;
                }
            }
        }

        return ans;
    }
};

class Solution


// longest

class Solution
{
public:
    int compress(vector<char> &s)
    {
        int index = 0, count = 1;
        char prev = s[0];

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == prev)
                count++;

            else
            {
                s[index++] = prev;
                if (count > 1)
                {
                    int start = index;
                    while (count)
                    {
                        s[index++] = (count % 10) + '0';
                        count = count / 10;
                    }
                    reverse(s.begin() + start, s.begin() + index);
                }
                count = 1;
                prev = s[i];
            }
        }
        s[index++] = prev;
        if (count > 1)
        {
            int start = index;
            while (count)
            {
                //  s[index++] = (count % 10 ) + '0';
                count = count / 10;
            }
            reverse(s.begin() + start, s.begin() + index);
        }

        return index;
    }
};