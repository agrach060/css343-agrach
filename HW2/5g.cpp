// Had to look up the solution at https://walkccc.me/LeetCode/problems/0973/
// Understood the concept of maxHeap
// Passed 2/2 cases

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        // lambda function that takes two parameters and compares the two points based on
        // their square distance from the origin
        auto compare = [&](const vector<int> &a, const vector<int> &b)
        {
            return squareDist(a) < squareDist(b);
        };
        // maxHeap to store the k closest points
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(compare);
        // traverse through each point in the vector
        for (const vector<int> &point : points)
        {
            // add the point to the maxHeap
            maxHeap.push(point);
            // check if the size of maxHeap exceeds k and, if yes, delete it from maxHeap
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        // move the points for the solution from maxHeap into the solution vector
        while (!maxHeap.empty())
        {
            ans.push_back(maxHeap.top()), maxHeap.pop();
        }
        return ans;
    }

    // calculate the square distance using the Euclidean distance formula
    int squareDist(const vector<int> &p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }
};
