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

void bfs(vector<int> *g, int da, int *depth);
bool colora(vector<int> *g, int da, int *depth);

int main()
{
    vector<int> g[N];
    int s1 = 0, s2 = 1;
    int depth1[N];
    int depth2[N];
    int col[N];
    for (int i = 0; i < N; i++)
    {
        depth1[i] = -1;
        depth2[i] = -1;
        col[i] = -1;
    }

    bfs(g, s1, depth1);
    bfs(g, s2, depth2);
    if (colora(g, 0, col))
        for (int i = 0; i < N; i++)
            cout << i << "di colore " << (col[i] % 2 == 0);

    for (int i = 0; i < N; i++)
        if (depth1[i] != -1 && depth2[i] != -1 && depth1[i] == depth2[i])
            cout << i;

    return 0;
}

void bfs(vector<int> *g, int da, int *depth)
{

    q.push(da);
    visited[da] = true;
    depth[da] = 0;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        int tempDepth = depth[t];

        for (vector<int>::iterator it = g[t].begin(); it != g[t].end(); ++it)
        {
            if (!visited[*it] || depth[*it] > tempDepth + 1)
            {
                q.push(*it);
                visited[*it] = true;
                depth[*it] = tempDepth + 1;
            }
        }
    }
}

bool colora(vector<int> *g, int da, int *depth)
{

    q.push(da);
    visited[da] = true;
    depth[da] = 0;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        int tempDepth = depth[t];

        for (vector<int>::iterator it = g[t].begin(); it != g[t].end(); ++it)
        {
            if (!visited[*it])
            {
                q.push(*it);
                visited[*it] = true;
                depth[*it] = tempDepth + 1;
            }
            else
            {
                return (depth[*it] % 2 == 0 && (tempDepth + 1) % 2 == 1)
            }
        }
    }
}