#include <iostream>

#include <vector>
#include <queue>
#include <fstream>

using namespace std;


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
                int color_tmp = 0;
                for (int j = 1; j <= N; j++)
                {
                    if (1 == graph[i][j])
                    {
                        color_tmp++;
                        if (color_tmp == color[from])
                            color_tmp++;
                        if (color_tmp == color[j])
                            color_tmp++;
                    }
                }
                que.push(i);
                color[i] = color_tmp;
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
    ifstream cin("/Users/aj/work/code/online_test/2018-09-09-jingdong/1_partition_graph_data.txt");

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M;
        cin >> N >> M;
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
        if(flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}