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

/*
题目：
    将12小时制的字符串转换为24小时制的字符串。
输入：
    一个描述12小时制时间的字符串。
    所有的输入都是合理的，不用考虑输入不合理的情况。
输出：
    一个描述24小时制时间的字符串。
示例：
    输入：
        08:03:45PM
    输出：
        20:03:45
*/

class Solution
{
public:

};

int main()
{
    Solution solution;
    string str;
    cin >> str;

    // 处理下午 PM 的时间
    // 对 12:30:00PM 这种格式特殊处理
    if (('P' == str[8] || 'p' == str[8]) && ('1' != str[0] && '2' != str[1]))
    {
        int h = str[0] - '0';
        int l = str[1] - '0';
        l += 12;
        h = h + l / 10;
        l %= 10;
        str[0] = char(h + '0');
        str[1] = char(l + '0');
    }
    // 对 12:30:00AM 这种格式特殊处理
    if (('A' == str[8] || 'a' == str[8]) && ('1' == str[0] && '2' == str[1]))
    {
        str[0] = '0';
        str[1] = '0';
    }
    str = str.substr(0, 8);
    cout << str << endl;

    return 0;
}