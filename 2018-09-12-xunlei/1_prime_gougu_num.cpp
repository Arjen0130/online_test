#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

/*
题目：
    勾股数，是由三个正整数组成的数组；能符合勾股定理 a*a + b*b = c*c，（a, b, c）的正整数解。
    如果 (a, b, c)是勾股数，它们的正整数倍数，也是勾股数。
    如果 (a, b, c)互质，它们就称为素勾股数。
    给定正整数 N，计算出小于或等于 N 的素勾股数。
    (0 < a <= b <= c <= N)
输入：
    正整数 N
输出：
    小于或等于 N 的素勾股数个数
    (0 < a <= b <= c <= N)
样例：
    输入：
        10
    输出
        1
*/

class Solution
{
public:
    int countNum(int N)
    {
        if (N < 5)
            return 0;
        int count = 0;
        for (int b = 2; b < N; b++)
        {
            for (int a = 1; a < b; a++)
            {
                for (int c = b + 1; c <= N; c++)
                {
                    if (false == isGougu(a, b, c))
                        continue;
                    if (false == isPrime(a, b, c))
                        continue;
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool isGougu(int a, int b, int c)
    {
        return ((a * a + b * b) == c * c);
    }

    bool isPrime(int a, int b, int c)
    {
        return ((isPrime(a, b)) && (isPrime(b, c)) && (isPrime(a, c)));
    }

    bool isPrime(int a, int b)
    {
        if (a <= 0 || b <= 0 || a == b)
            return false;
        else if (a == 1 || b == 1)
            return true;
        else
        {
            while(true)
            {
                int t = a % b;
                if (t == 0)
                    break;
                else
                {
                    a = b;
                    b = t;
                }
            }
            if (b > 1)
                return false;
            else
                return true;
        } 
    }
};


int main()
{
    Solution solution;

    int N;
    cin >> N;
    cout << solution.countNum(N) << endl;

    return 0;
}