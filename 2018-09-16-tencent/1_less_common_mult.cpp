#include <iostream>
//STL head file
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

/*
题目：
    小 Q 在学校学习了最小公倍数的求法：
    LCM(2) = 2，LCM(4，6) = 12，LCM(1，2，3，4，5，6) = 60。
    为了检验小 Q 学习得怎么样，牛牛出了一个算法题给小 Q。
    牛牛给出一个正整数 n，让小 Q 计算出最小的大于 n 的正整数 m，
    使其满足：LCM(n+1, n+2, ..., m) = LCM(1,2, ..., m)。
    例如：
        牛牛给出的正整数 n = 3，那么 m = 6，因为 LCM(4,5,6) = LCM(1,2,3,4,5,6) = 60，
        并且这个 m 是最小的大于 n 的正整数。
输入：
    输入包括一个正整数 n(1 <= n <= 10^6)
输出：
    输出一个正整数，即最小的满足条件的 m
示例：
    输入：
        3
    输出：
        6
*/

class Solution
{
public:
    int lcm(int n)
    {
        // int i,j,k,n,a[100],s=1;
	    // cin>>n;
        vector<int> vec_1;
        vector<int> vec_2;
        int i = 1;
        int mul_1 = 1;
        int mul_2 = 1;
        int j = n+1;
        while (i <= n)
        {
            vec_2.push_back(i);
            mul_2 *= i;   
            i++;
        }
        vec_1.push_back(j);
        mul_1 *= j;
        vec_2.push_back(j);
        mul_2 *= j;
        while(lcmHelp(mul_1, vec_1) != lcmHelp(mul_2, vec_2))
        {
            j++;
            vec_1.push_back(j);
            mul_1 *= j;
            vec_2.push_back(j);
            mul_2 *= j;
        }
        return j;
    }

private:
    int lcmHelp(int sum, vector<int> vec)
    {
        int n = vec.size();
	    int k = vec[0];
	    for (int i = 1; i < n; i++)
	        for (int j = 1; j <= sum; j++)
	        {
	        	if ( j % k == 0 && j % vec[i] == 0)
		        {
			        k=j;
			        break;
		        }
	        }
	    return k;
    }
};

int main()
{
    Solution solution;
    
    int n;
    cin >> n;
    cout << solution.lcm(n) << endl;

    return 0;
}