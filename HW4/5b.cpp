// Solved using class notes and the implementation of checking for isomorphic strings from https://www.geeksforgeeks.org/check-if-two-given-strings-are-isomorphic-to-each-other/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // check if the strings are the same size
        if (s.length() != t.length())
        {
            return false;
        }
        // initializing an unordered_map to store letters from
        // s and t as key value pairs
        unordered_map<char, char> characterMap;
        // create a set to store visited letters
        set<char> seen;
        // iterate through the string s
        for (int i = 0; i < s.length(); i++)
        {
            // check if the character in s is not already mapped and
            // the character from t hasn't been used
            if (characterMap.count(s[i]) == 0 && seen.count(t[i]) == 0)
            {
                characterMap[s[i]] = t[i];
                seen.insert(t[i]);
                // check if the mapping is unique
            }
            else if (characterMap.count(s[i]) == 0 && seen.count(t[i]) > 0)
            {
                return false;
                // check if a character from s is already mapped to a character from t
            }
            else if (characterMap[s[i]] != t[i])
            {
                return false;
            }
        }
        // all the characters are successfully mapped
        return true;
    }
};