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
    小 P 在工作之余研究起了等差数列。
    这天，小 P 在会议室的白板上写下了一个等差数列之后，接到电话就离开了会议室打电话。
    不明真相的小 Q 紧接着进入了会议室。
    然而，小 Q 有一个非常糟糕的强迫症 -- 他非常讨厌偶数。
    于是，他将白板上所有的偶数擦去，将每个偶数替换为除以2的结果。
    如果一遍操作之后，白板上仍然有偶数，他就重复一遍操作，直到白板上的偶数都消失为止。
    小 P 打完电话，回到了会议室，发现了小 Q 的杰作。
    可是，之前的等差数列对于小 P 来说无比重要。
    现在，他想知道在小 Q 操作之前他写下的等差数列是什么？
    如果有多种可能的答案，请输出首项最小的等差数列。
输入：
    第一行一个整数 N (4 <= N <= 50)，表示小 Q 操作完之后白板上整数的数量。
    之后 N 行，每行一个奇数 A[i]，依次表示小 Q 操作完之后白板上的数列。
    保证 1 <= A[i] <= 1000
输出：
    共 N 行，每行一个数，依次表示小 Q 操作前，满足题目要求的等差数列的各个值。
示例：
    输入：
        6
        1
        1
        3
        1
        5
        3
    输出：
        1
        2
        3
        4
        5
        6
*/

class Solution
{
public:
    void get(int N, vector<int> & vec)
    {
        if (N <= 0)
            return;
        if (N == 1)
            cout << vec[0] << endl;
        if (N == 2)
        {
            while(vec[1] < vec[0])
                vec[1] *= 2;
            for(int i = 0; i < N; i++)
                cout << vec[i] << endl;
        }
        if (N > 2)
        {
            bool flag = true;
            for (int i = 1; i < N; i++)
            {
                if (vec[i] != vec[0])
                {
                    flag = false;
                    break;
                }
            }
            if (true == flag)
            {
                for (int i = 0; i < N; i++)
                    cout << vec[i] << endl;
                return;
            }
            int val_1 = vec[0];
            int val_2 = vec[1];
            for (int i = 1 ; ;i++)
            {
                vector<int> vec_tmp(vec);
                if (0 == i % 10)
                {
                    val_1 *= 2;
                    vec_tmp[0] = val_1;
                    vec_tmp[1] = val_2;
                    while(vec_tmp[1] < vec_tmp[0])
                        vec_tmp[1] *= 2;
                }
                else
                {
                    val_2 *= 2;
                    vec_tmp[0] = val_1;
                    vec_tmp[1] = val_2;
                    while(vec_tmp[1] < vec_tmp[0])
                        vec_tmp[1] *= 2;
                }
                if (true == makeVec(N, vec_tmp))
                {
                    for(int i = 0; i < N; i++)
                        cout << vec_tmp[i] << endl;
                    return;
                }
            }
        }
    }
private:
    bool makeVec(int N, vector<int> & vec)
    {
        int d = vec[1] - vec[0];
        int tmp = vec[1];
        for (int i = 2; i < N; i++)
        {
            tmp += d;
            if (false == isOK(tmp, vec[i]))
                return false;
        }
        return true;
    }

    bool isOK(int tmp, int & val)
    {
        while (val < tmp)
        {
            val *= 2;
        }
        return (val == tmp);
    }

};

int main()
{
    Solution solution;

    int N;
    cin >> N;
    vector<int> vec(N+1);
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    solution.get(N, vec);

    return 0;
}