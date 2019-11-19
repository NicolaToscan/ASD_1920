#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

int N, M;
void visita(vector<int> *g, int from, bool *visited, int *depth, int d);

int main()
{
    ifstream in("input.txt");
    in >> N;
    in >> M;

    vector<int> g[N];
    bool isTop[N];
    bool visited[N];
    int depth[N];

    for (int i = 0; i < N; i++)
    {
        isTop[i] = true;
        visited[i] = false;
        depth[i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int s, e;
        in >> s;
        in >> e;
        g[s].push_back(e);
        isTop[e] = false;
    }
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        if (isTop[i])
        {
            visita(g, i, visited, depth, 0);

            for (int j = 0; j < N; j++) {
                if (depth[j] > max)
                    max = depth[j];
            }
        }
    }

    ofstream out("output.txt");
    out << max;
    cout << max << endl;

    return 0;
}

void visita(vector<int> *g, int from, bool *visited, int *depth, int d)
{
    if (!visited[from] || depth[from] < d)
    {
        depth[from] = d;
        visited[from] = true;
        for (vector<int>::iterator it = g[from].begin(); it != g[from].end(); ++it)
            visita(g, *it, visited, depth, d + 1);
    }
}