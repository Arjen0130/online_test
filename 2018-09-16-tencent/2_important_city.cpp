#include <iostream>
#include <fstream>
//STL head file
#include <vector>
// #include <queue>
// #include <list>
// #include <map>
#include <algorithm>

using namespace std;

/*
题目：
    小 Q 所在的王国有 n 个城市，城市之间有 m 条单向道路连接起来。
    对于一个城市 v，从城市 v 出发可以到达的城市数量为 x；
    从某个城市出发，可以到达城市 v 的城市数量为 y；
    如果 y > x，则城市 v 是一个重要城市（间接可达也算可以到达）。
    小 Q 希望你能帮助他计算一下王国中一共有多少个重要城市。
输入：
    输入包括 m+1 行，
    第一行包括两个数 n 和 m (1 <=n, m <= 1000)，分别表示城市数和道路数。
    接下来 m 行，每行两个数 u, v (1 <= u, v <= n)，
    表示一条从 u 到 v 的有向道路，输入中可能包含重边和自环。
输出：
    输出一个数，重要节点的个数。
示例：
    输入：
        4 3
        2 1
        3 2
        4 3
    输出：
        2
    说明：
        城市1和城市2是重要城市
*/

class Solution
{
public:

    void dfs(vector<vector<int> > & graph, vector<vector<int> > &sour, vector<vector<int> > &dest)
    {
        int size = graph.size();
        for (int i = 1; i <= size; i++)
        {
            vector<vector<bool> > flag(size, vector<bool>(size, 0));
            vector<int> city_sour, city_dest;
            city_sour.push_back(i);
            dfsHelp(i, graph, sour, dest, flag, city_sour, city_dest);
            dest[i].insert(dest[i].end(), city_dest.begin(), city_dest.end());
        }
    }

private:
    void dfsHelp(int s, vector<vector<int> > & graph, vector<vector<int> > &sour, vector<vector<int> > &dest, 
                 vector<vector<bool> > & flag, vector<int> city_sour, vector<int> & city_dest)
    {
        int size = graph[s].size();
        for (int i = 1; i <= size; i++)
        {
            if ((graph[s][i] == 1) && (flag[s][i] == false))
            {
                flag[s][i] = true;
                city_dest.push_back(i);
                city_sour.push_back(s);
                sour[i].insert(sour[i].end(), city_sour.begin(), city_sour.end());
                dfsHelp(i, graph, sour, dest, flag, city_sour, city_dest);
            }
        }
    }

};

int main()
{
    ifstream cin("D:/code/online_test/2018-09-16-tencent/2_important_city_data.txt");
    Solution solution;
    
    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }
    vector<vector<int> > sour(n + 1, vector<int>(0));  // 能够到达当前城市的城市的索引
    vector<vector<int> > dest(n + 1, vector<int>(0));  // 当前城市能够到达的城市的索引

    solution.dfs(graph, sour, dest);

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        unique(sour[i].begin(), sour[i].end());
        unique(dest[i].begin(), dest[i].end());
        int sour_size = sour[i].size();
        int dest_size = dest[i].size();
        if (sour_size < dest_size)
            count++;
    }  
    cout << count << endl; 

    return 0;
}