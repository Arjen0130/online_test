#include <iostream>
#include <fstream>

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/*
题目：
    给定一个正整数数组 a，返回一个新的数组 sums，满足 sums[i] 的值为 a 中比 a[i] 小的数字之和；
    如果不存在比 a[i] 小的数字，则 sums[i] 为0.
    已知数组 a 中元素最大值不超过 100000，数组长度不超过 10000，数组元素允许重复。
输入：
    第一行为整数 n，表示数组的长度；
    接下来的 n 行数字表示数组里的元素。
输出：
    正整数数组 sums，使得 sums 长度与 a 长度相同
样例：
    输入：
        4
        5
        4
        2
        9
    输出：
        6
        2
        0
        11
*/

class Solution
{
public:
    vector<int> sum_less(int n, vector<int> & a)
    {
        vector<int> ret;
        if (0 >= n)
            return ret;
        if (1 == n)
        {
            ret.push_back(0);
            return ret;
        }
        
        int size = a.size();
        if (size != n)
            return ret;
        ret.resize(size);

        
        vector<int> sort_a(a);
        sort(sort_a.begin(), sort_a.end());

        vector<int> sum_tmp(size, 0);
        int count_repeat = 1;
        for (int i = 1; i < size; i++)
        {
            if (sort_a[i] > sort_a[i - 1])
            {
                sum_tmp[i] = sum_tmp[i - 1] + sort_a[i - 1] * count_repeat;
                count_repeat = 1;
            }
            if (sort_a[i] == sort_a[i - 1])
            {
                sum_tmp[i] = sum_tmp[i - 1];
                count_repeat++;
            }
        }

        map<int, int> value_to_sum;
        for (int i = 0; i < size; i++)
        {
            value_to_sum.insert(pair<int, int>(sort_a[i], sum_tmp[i]));
        }

        for (int i = 0; i < size; i++)
        {
            ret[i] = value_to_sum[a[i]];
        }

        return ret;
    }
private:
    
};


int main()
{
    Solution solution;

    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> ret = solution.sum_less(n, a);
    for (int i = 0; i < n; i++)
    {
        cout << ret[i] << endl;
    }

    return 0;
}