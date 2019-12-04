#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

int N, M;

int START, END;
bool visited[1000000];
int nZones = 0;
int zones[1000000];
int timeToEnd[1000000];

stack<int> ordTop(vector<int> *g, int start);
void visita(vector<int> *g, int from, stack<int> *res);
int ccc(vector<int> *g, stack<int> s);
void marchiaDFS(vector<int> *g, int i, int from);
void removeUseles(vector<int> *g);
void reduceGraph(vector<int> *g, vector<int> *reducedG);
int coutToEnd(vector<int> *reducedG, int from);

int main()
{

    ifstream in("input.txt");
    in >> N;
    in >> M;
    in >> START;
    in >> END;

    vector<int> g[N];
    vector<int> gT[N];

    for (int i = 0; i < M; i++)
    {
        int s, e;
        in >> s;
        in >> e;
        g[s].push_back(e);
        gT[e].push_back(s);
    }

    stack<int> stack = ordTop(g, START);
    ccc(gT, stack);

    vector<int> reducedG[nZones];
    reduceGraph(g, reducedG);

    for (int i = 0; i < nZones; i++)
        timeToEnd[i] = -1;
    timeToEnd[zones[END]] = 1;

    int res = coutToEnd(reducedG, zones[START]);

    ofstream out("output.txt");
    out << res << endl;

    return 0;
}

stack<int> ordTop(vector<int> *g, int start)
{
    stack<int> res;
    for (int i = 0; i < N; i++)
        visited[i] = false;

    visita(g, start, &res);
    return res;
}

void visita(vector<int> *g, int from, stack<int> *res)
{
    if (visited[from])
    {
        return;
    }

    visited[from] = true;
    for (auto n : g[from])
        visita(g, n, res);

    (*res).push(from);
}

int ccc(vector<int> *g, stack<int> s)
{
    for (int i = 0; i < N; i++)
        zones[i] = -1;

    int i = 0;

    while (!s.empty())
    {
        int from = s.top();
        s.pop();
        if (zones[from] == -1)
            marchiaDFS(g, ++i, from);
    }

    nZones = i;
}

void marchiaDFS(vector<int> *g, int i, int from)
{
    if (!visited[from] || zones[from] != -1)
        return;

    zones[from] = i;
    for (auto n : g[from])
        marchiaDFS(g, i, n);
}

void reduceGraph(vector<int> *g, vector<int> *reducedG)
{
    for (int i = 0; i < N; i++)
        for (int n : g[i])
            if (zones[i] != zones[n] && zones[i] > 0 && zones[n])
                reducedG[zones[i]].push_back(zones[n]);
}

int coutToEnd(vector<int> *reducedG, int from)
{
    if (timeToEnd[from] != -1)
        return timeToEnd[from];

    int sum = 0;
    for (int n : reducedG[from])
        sum += coutToEnd(reducedG, n);


    timeToEnd[from] = sum;
    return sum;
}