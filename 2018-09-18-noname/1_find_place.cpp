#include <iostream>

#include <vector>
#include <algorithm>


using namespace std;

/*
题目：
    排列小球
    给定三种类型的小球 P, Q, R，每种小球的数量分别为 np, nq, nr 个。
    现在想将这些小球排成一条直线，但是不允许相同类型的小球相邻，问有多少种排列方法。
    如若 np = 2, nq = 1, nr = 1，则公有 6 种排列方式：
        PQRP, QPRP, PRQP, RPQP, PRPQ, PQPR。
    如果无法组合出合适的结果，则输出 0。
输入：
    一行以空格相隔的三个数，分别表示为 np, nq, nr。
输出：
    排列方法的数量。
示例：
    输入：
        2 1 1 
    输出：
        6
*/

int compos(int a, int b)
{
    int x, y, z;
    int tmp = 1;
    int minus = a - b;
    for (int i = 1; i <= a; i++)
    {
        tmp *= i;
        if (i == a)
            x = tmp;
        if (i == b)
            y = tmp;
        if (i == minus)
            z = tmp;
    }
    return (x / (y * z));
}

int main()
{
    vector<int> vec(3);
    cin >> vec[0] >> vec[1] >> vec[2];
    sort(vec.begin(), vec.end());

    if (vec[2] > (vec[1] + vec[0] + 1))
        return 0;

    int count = 0;

    count += compos(vec[2] - 1, vec[1]);
    count += compos(2 * vec[2] - 1)
    

    return 0;
}