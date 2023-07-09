// Completed half of the solution myself using the class notes.
// Fixed my code and saw the way to rotate the digits on the lock here: https://leetcode.com/problems/open-the-lock/

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {

        unordered_set<string> seen{deadends.begin(), deadends.end()};
        //  check if the starting position if the deadend
        if (seen.count("0000"))
            return -1;
        // check if the starting position is the target
        if (target == "0000")
            return 0;

        int level = 0;
        // start from the initial combination
        queue<string> q{{"0000"}};

        while (!q.empty())
        {
            ++level;
            // go through each node on this level
            for (int sz = q.size(); sz > 0; --sz)
            {
                string word = q.front();
                q.pop();
                // traverse through each digit of the lock
                for (int i = 0; i < 4; ++i)
                {
                    // make a copy of "word[i]" to get back to it after modifications
                    const char cache = word[i];
                    // increase i-th digit by 1 clockwise
                    word[i] = word[i] == '9' ? '0' : word[i] + 1;
                    // check if the current state is the target
                    if (word == target)
                        return level;
                    // indicate that we visited this state
                    if (!seen.count(word))
                    {
                        q.push(word);
                        seen.insert(word);
                    }
                    // get back to the initial "word[i]"
                    word[i] = cache;
                    // decrease i-th digit by 1 counterclockwise
                    word[i] = word[i] == '0' ? '9' : word[i] - 1;
                    // check if the current state is the target
                    if (word == target)
                        return level;
                    // indicate that we visited this state
                    if (!seen.count(word))
                    {
                        q.push(word);
                        seen.insert(word);
                    }
                    // get back to the initial "word[i]"
                    word[i] = cache;
                }
            }
        }
        // if the solution cannot be reached, return -1
        return -1;
    }
};