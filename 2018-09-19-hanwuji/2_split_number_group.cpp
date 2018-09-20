#include <iostream>
// STL head file
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <numeric>
// Normal header files in C
#include <ctime>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*
题目：
    小爱和小溪有 N 个数字，他们两个想公平的分配这些数字。
    小爱拿的数字集合为 I = [i1, i2, ..., ik]，小溪获得剩下的 J = [j1, j2, ..., jn-k]。
    但是，他们衡量分配公平与否的原则与众不同：
        f(i) = xigma_(i in I) xigma_(j in J) |a_i - a_j|
    在小爱拿到其中的 K 个数字的前提下，计算出他们分配偏差 f(I) 的最小值。
输入：
    输入第一行为两个数字，分别表示总的数字量 N 和小爱拿的数字量 K。
    第二行有 N 个数字，表示每个数字的值。
输出：
    输出一个数字，表示分配偏差 f(I) 的最小值。
示例：
    输入：
        4 1
        3 3 3 1
    输出：
        2
*/

class Solution
{
public:
    void min_minu(int N, int K, vector<vector<int> > & res)
    {
        vector<int> vec_tmp;
        help(0, K, N - K)
    }

    void help(int &count, int K, int sta, int end, vector<int> vec_tmp, vector<vector<int> > & vec)
    {
        if (count == K)
        {
            vec.push_back(vec_tmp);
        }
        for (int i = sta; i <= end; i++)
        {
            vec_tmp.push_back(i);
            count++;
            help(count, K, i+1, end + 1);
        }
    }

};

int main()
{
    Solution solution;

    int N, int K;
    cin >> N >> K;
    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    if (0 == N)
        cout << 0 << endl;
    if (N <= K)
        cout << accumulate(vec.begin(), vec.end(), 0) << endl;
    

    


    return 0;
}