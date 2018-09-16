#include <iostream>
//STL head file
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

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
	    int k=vec[0];
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