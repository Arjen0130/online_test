#include <iostream>
// STL head file
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
// Normal header files in C
#include <ctime>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    void set(char c)
    {
        
        if (c == 'i' && 0 < inStack.size())
        {
            opStack.push_back(c);
            delStack.push_back(inStack.back());
            inStack.pop_back();
        }
        else if (c == 'o' && 0 < opStack.size())
        {
            char preC = opStack.back();
            opStack.pop_back();
            if (preC == 'i' && (0 < delStack.size()))
            {
                inStack.push_back(delStack.back());
                delStack.pop_back();
            }
            else 
            {
                inStack.pop_back();
            }
        }
        else
        {
            inStack.push_back(c);
            opStack.push_back(c);
        }
    }
    string get()
    {
        string ret;
        while (inStack.size() > 0)
        {
            ret.push_back(inStack.back());
            inStack.pop_back();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
private:
    vector<char> inStack;
    vector<char> delStack;
    vector<char> opStack;
};

int main()
{
    Solution solution;
    cout << "get input..." << endl;
    string s;    
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        solution.set(s[i]);
    }
    cout << solution.get() << endl;
    return 0;
}