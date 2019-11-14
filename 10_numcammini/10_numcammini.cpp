#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int N, M, start, fin;
int counter = 0;
bool visited[10000];
int depth[10000];

void bfs(vector<int> *g, int da);

int main()
{
    ifstream in("input.txt");
    in >> N;
    in >> M;
    in >> start;
    in >> fin;

    vector<int> g[N];

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        depth[i] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        int s, e;
        in >> s;
        in >> e;
        g[s].push_back(e);
    }

    bfs(g, start);
    return 0;
}

void bfs(vector<int> *g, int da)
{
    int res = 0;
    int resDepth = 2000000000;
    queue<int> q;

    q.push(da);
    depth[da] = 0;
    visited[da] = true;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        int currDepth = depth[t];

        if (currDepth + 1 <= resDepth)
        {
            for (vector<int>::iterator it = g[t].begin(); it != g[t].end(); ++it)
            {
                if (!visited[*it] || depth[*it] == currDepth + 1)
                {
                    q.push(*it);
                    depth[*it] = currDepth + 1;
                    visited[*it] = true;

                    if (*it == fin)
                    {
                        res++;
                        resDepth = currDepth + 1;
                    }
                }
            }
        }
    }

    cout << resDepth << endl;
    cout << res << endl;
    ofstream out("output.txt");
    out << resDepth << " " << res;
}