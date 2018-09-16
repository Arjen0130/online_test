#include <iostream>

#include <vector>
#include <queue>
#include <fstream>

using namespace std;

/*
题目：Accept
    幼儿园一个大班要分成两个小班，有些小朋友不希望自己和其他某几位小朋友同班。
    园长向大家收集了不希望同班的要求，然后视情况将一个小班的小朋友分成两个班。
    请你开发一个程序，帮助园长快速判断是否所有小朋友的不同请求都可以被满足。
输入：
    输入分为三部分，
    第一部分是一个 int，代表这个大班里小朋友的总数。
    第二部分是一个 int，代表园长采集到的小朋友们的请求数。
    第三部分是小朋友们的请求，每个请求由两个 int 组成，
    第一个 int 代表提请求的小朋友，
    第二个 int 代表他不希望同班的另一位小朋友。
输出：
    如果所有小朋友的请求都可以满足，输出 1，否则输出 0。
示例：
    输入：
        5
        5
        1 2
        1 3
        1 4
        1 5
        2 3
    输出：
        0        
*/

bool BFS(int s, int N, vector<int> & color, vector<vector<int> > & graph)
{
    color[s] = 1;
    queue<int> que;
    que.push(s);
    while(!que.empty())
    {
        int from = que.front();
        que.pop();
        for(int i = 1; i <= N; i++)
        {
            // 如果相邻的点没有上色就给这个点上色
            if(graph[from][i] && color[i] == 0)
            {
                color[i] = -color[from];
                que.push(i);
            }
            // 如果相邻的颜色相同则返回false
            if(graph[from][i] && color[i] == color[from])
                return false;
        }
    }
    // 如果所有的点都被染过色，且相邻的点颜色都不一样，返回true
    return true;
}


int main()
{
    ifstream cin("D:/code/online_test/2018-09-15-xiaohongshu/1_split_child_class_data.txt");
    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M;
        cin >> N;
        cin >> M;
        vector<vector<int> > graph(N + 1, vector<int>(N + 1, 0));
        vector<int> color(N, 0);
        for (int j = 0; j < M; j++)
        {
            int X, Y;
            cin >> X >> Y;
            graph[X][Y] = 1;
            graph[Y][X] = 1;
        }

        bool flag = false;

        for(int i = 1; i <= N; i++)
        {
            if(color[i] == 0 && ! BFS(i, N, color, graph))
            {
                flag = true;
                break;
            }
        }
        cout << !flag << endl;
    }
    return 0;
}