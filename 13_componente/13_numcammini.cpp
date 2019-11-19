#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int bfs(bool *g[], int da, int *visited, int *depth);

int main()
{
    ifstream in("input.txt");
    in >> N;
    in >> M;

    bool **g = new bool *[N];
    for (int i = 0; i < N; i++) {
        g[i] = new bool[N];
        for (int j = 0; j < N; j++)
            g[i][j] = false;
    }

    for (int i = 0; i < M; i++)
    {
        int s, e;
        in >> s;
        in >> e;
        g[s][e] = true;
    }

    int visited[N];
    int depth[N];
    int resMax = 0;
    for (int i = 0; i < N; i++)
    {
        for (int i = 0; i < N; i++)
        {
            visited[i] = false;
            depth[i] = 0;
        }
        int r = bfs(g, i, visited, depth);
        if (r > resMax)
            resMax = r;
    }

    resMax++;

    ofstream out("output.txt");
    out << resMax;
    cout << resMax << endl;
    return 0;
}

int bfs(bool **g, int da, int *visited, int *depth)
{
    queue<int> q;

    int maxDepth = 0;

    q.push(da);
    visited[da] = true;
    depth[da] = 0;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        int tempDepth = depth[t];
        if (tempDepth > maxDepth)
            maxDepth = tempDepth;
        for (int i = 0; i < N; i++)
        {
            if (g[t][i] && g[i][t])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    depth[i] = tempDepth + 1;
                }
            }
        }
    }

    return maxDepth;
}