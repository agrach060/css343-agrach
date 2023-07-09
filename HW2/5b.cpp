// Completed half of the solution myself using the class notes.
// The way to rotate the digits on the lock was looked up here: https://leetcode.com/problems/open-the-lock/
// Passed 3/3 cases

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        string start = "0000";
        queue<string> q;
        q.push(start);
        set<string> seen;
        int level = 0;
        // put the values of deadends into the set to check for match later
        for (int i = 0; i < deadends.size(); i++)
        {
            seen.insert(deadends[i]);
        }
        // insert the starting value into the set of seen values
        seen.insert(start);

        while (!q.empty())
        {
            level++;
            // go through each node on this level
            for (int sz = q.size(); sz > 0; --sz)
            {
                string word = q.front();
                q.pop();
                // traverse through each digit of the lock
                for (int i = 0; i < 4; ++i)
                {
                    const char cache = word[i];
                    // Increase i-th digit by 1 clockwise
                    word[i] = word[i] == '9' ? '0' : word[i] + 1;
                    if (word == target)
                        return level;
                    if (!seen.count(word))
                    {
                        q.push(word);
                        seen.insert(word);
                    }
                    word[i] = cache;
                    // Decrease i-th digit by 1 counterclockwise
                    word[i] = word[i] == '0' ? '9' : word[i] - 1;
                    if (word == target)
                        return level;
                    if (!seen.count(word))
                    {
                        q.push(word);
                        seen.insert(word);
                    }
                    word[i] = cache;
                }
            }
        }
        // if the target is unreachable, return -1
        return -1;
    }
};
