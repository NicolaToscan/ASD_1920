#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

int N, M;

stack<int> topS(vector<int> *g);
void visita(vector<int> *g, int from, bool *visited, stack<int> *res);
int ccc(vector<int> *g, stack<int> s);
void marchiaDFS(vector<int> *g, int i, int from, int visited[]);

int main()
{
    ifstream in("input.txt");
    in >> N;
    in >> M;

    vector<int> g[N];
    vector<int> gT[N];
    int cc[N];

    for (int i = 0; i < N; i++)
    {
        cc[i] = -1;
    }

    for (int i = 0; i < M; i++)
    {
        int s, e;
        in >> s;
        in >> e;
        g[s].push_back(e);
        gT[e].push_back(s);
    }

    stack<int> st = topS(g);
    int res = ccc(gT, st);

    ofstream out("output.txt");
    out << res;
    cout << res << endl;
    return 0;
}

stack<int> topS(vector<int> *g)
{
    stack<int> res;
    bool visited[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    for (int i = 0; i < N; i++)
        if (!visited[i])
            visita(g, i, visited, &res);

    return res;
}

void visita(vector<int> *g, int from, bool *visited, stack<int> *res)
{
    if (visited[from])
        return;

    visited[from] = true;
    for (vector<int>::iterator it = g[from].begin(); it != g[from].end(); ++it)
        visita(g, *it, visited, res);

    (*res).push(from);
}

int ccc(vector<int> *g, stack<int> s)
{
    int visited[N];
    for (int i = 0; i < N; i++)
        visited[i] = -1;

    int i = 0;

    while (!s.empty())
    {
        int from = s.top();
        s.pop();
        if (visited[from] == -1)
            marchiaDFS(g, ++i, from, visited);
    }

    //count
    int res[i + 1];
    for (int j = 0; j < i + 1; j++)
        res[j] = 0;

    for (int j = 0; j < N; j++)
        res[visited[j]]++;

    int max = 0;
    for (int j = 0; j < i + 1; j++)
    {
        if (res[j] > max)
            max = res[j];
    }
    return max;
}

void marchiaDFS(vector<int> *g, int i, int from, int visited[])
{
    if (visited[from] != -1)
        return;

    visited[from] = i;
    for (vector<int>::iterator it = g[from].begin(); it != g[from].end(); ++it)
        marchiaDFS(g, i, *it, visited);
}