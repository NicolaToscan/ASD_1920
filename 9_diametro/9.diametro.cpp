#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int counter = 0;
bool visited[10000];
int depth[10000];
queue<int> q;

int bfs(vector<int> *g, int da);

int main()
{
    ifstream in("input.txt");
    in >> N;
    in >> M;

    vector<int> g[N];

    for (int i = 0; i < M; i++)
    {
        int s, e;
        in >> s;
        in >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }

    int resMax = 0;
    for (int i = 0; i < N; i++)
    {
        for (int i = 0; i < N; i++)
        {
            visited[i] = false;
            depth[i] = 0;
        }
        int r = bfs(g, i);
        if (r > resMax)
            resMax = r;
    }

    ofstream out("output.txt");
    out << resMax;
    cout << resMax << endl;

    return 0;
}

int bfs(vector<int> *g, int da)
{
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

        for (vector<int>::iterator it = g[t].begin(); it != g[t].end(); ++it)
        {
            if (!visited[*it])
            {
                q.push(*it);
                visited[*it] = true;
                depth[*it] = tempDepth + 1;
            }
        }
    }

    return maxDepth;
}