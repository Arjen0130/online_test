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

};

int main()
{
    Solution solution;
    string str;
    cin >> str;
    if ('P' == str[8] || 'p' == str[8])
    {
        int h = str[0] - '0';
        int l = str[1] - '0';
        l += 12;
        h = h + l / 10;
        l %= 10;
        str[0] = char(h + '0');
        str[1] = char(l + '0');
    }
    str = str.substr(0, 8);
    cout << str << endl;

    return 0;
}