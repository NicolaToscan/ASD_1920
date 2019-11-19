#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

int N, M;
void visita(vector<int> *g, int from, bool *visited, stack<int> *res);

int main()
{
    ifstream in("input.txt");
    in >> N;
    in >> M;

    vector<int> g[N];
    bool isTop[N];
    bool visited[N];

    for (int i = 0; i < N; i++)
    {
        isTop[i] = true;
        visited[i] = false;
    }

    for (int i = 0; i < M; i++)
    {
        int s, e;
        in >> s;
        in >> e;
        g[s].push_back(e);
        isTop[e] = false;
    }

    stack<int> res;
    for (int i = 0; i < N; i++)
        if (isTop[i])
            visita(g, i, visited, &res);

    ofstream out("output.txt");
    while (!res.empty()) {
        out << res.top() << " ";
        res.pop();
    }

    return 0;
}

void visita(vector<int> *g, int from, bool *visited, stack<int> *res)
{
    if (visited[from])
        return;

    visited[from] = true;
    for (vector<int>::iterator it = g[from].begin(); it != g[from].end(); ++it)
    {
        visita(g, *it, visited, res);
    }

    (*res).push(from);
}