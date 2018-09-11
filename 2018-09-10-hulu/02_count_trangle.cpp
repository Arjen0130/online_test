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
    三角形计数
    时间限制，1000MS
    内存限制，131072KB
    给定一个圆，圆心在原点。给定圆上的一组点 a[i] (i = 1, 2, ..., n)，各点互不重复，
    且用 x 轴正方向逆时针转至与该点所在半径重合时所转角度的 100 倍（整数）表示，取值范围 [0, 36000）。
    我们可以从这组点中任选三点组成一个三角形。
    请问最多可以组成多少个钝角三角形？
输入：
    第一行为一个整数，n 为点的个数。n <= 1000。
    接下来 n 行，每一行有一个整数，每个数表示在圆边上的一个点。
输出：
    任选三点，可以组成钝角三角形的数量。
样例：
    输入：
        4
        0
        10000
        12000
        18000
    输出：
        2
样例2：
    输入：
        4
        9000
        0
        27000
        18000
    输出：
        0

*/

class Solution
{
public:

    int countTrangle(int n, vector<int> & point)
    {
        if (n <= 2)
            return 0;
        int size = point.size();
        if (n != size)
            return -1;

        sort(point.begin(), point.end());

        int count = 0;
        for (int i = 0; i < size; i++)
        {
            int sta = point[i];
            int end = com_angle(sta);
            int num = count_point_num(sta, end, point);
            count += compute_trangle(num);
        }

        return count;
    }

private:

    // 计算180度截止角
    int com_angle(int sta_angle)
    {
        return (sta_angle + 18000) % 36000;
    }

    // 计算角度范围内点的个数
    int count_point_num(int sta_angle, int end_angle, vector<int> & point)
    {
        int count = 0;
        int size = point.size();
        
        bool flag = false;
        if (sta_angle > end_angle)
        {
            flag = true;
            int tmp = sta_angle;
            sta_angle = end_angle;
            end_angle = tmp;
        }

        for (int i = 0; i < size; i++)
        {
            if ((point[i] >= sta_angle) && (point[i] < end_angle))
                count++;
        }

        if (true == flag)
            count = size - count;
        return count;
    }

    // 根据点的个数，计算钝角三角形的个数
    int compute_trangle(int num)
    {
        if (num <= 2)
            return 0;
        num -= 2;
        return (num + 1) * num / 2;
    }

};


int main()
{
    Solution solution;

    int n;
    cin >> n;

    vector<int> point(n);
    for (int i = 0; i < n; i++)
    {
        cin >> point[i];
    }

    cout << solution.countTrangle(n, point) << endl;
    return 0;
}