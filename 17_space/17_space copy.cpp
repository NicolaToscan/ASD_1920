#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int N, M;
bool *isArt;
bool *artVisited;
int nVicere = 0;

bool bfs(vector<int> *g, int root, int *visited, int *zones, const int nZone, int *vicere)
{
    queue<int> q;
    for (int i = 0; i < N; i++)
        artVisited[i] = false;

    visited[root] = true;
    zones[root] = nZone;
    int nearBackbone = 0;

    q.push(root);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int n : g[node])
        {
            if (!visited[n])
            {
                if (isArt[n])
                {
                    if (!artVisited[n])
                    {
                        nearBackbone++;
                        artVisited[n] = true;
                    }
                }
                else
                {
                    zones[n] = nZone;
                    q.push(n);
                    visited[n] = true;
                }
            }
        }
    }

    if (nearBackbone <= 1)
    {
        vicere[nVicere] = root;
        nVicere++;
    }
}

void marchia(vector<int> *g)
{
    int *visited = new int[N];
    int *zones = new int[N];
    int *vicere = new int[N];

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        zones[i] = -1;
    }

    int nZone = 0;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && !isArt[i])
        {
            bfs(g, i, visited, zones, nZone, vicere);
            nZone++;
        }
    }

    ofstream out("output.txt");
    out << nVicere << endl;
    for (int i = 0; i < nVicere; i++)
        out << vicere[i] << " ";
    out << endl;
}

set<int> art;
void dfs(vector<int> *g, int *visited, int root)
{
    if (isArt[root])
        art.insert(root);
    else if (!visited[root])
    {
        visited[root] = true;
        for (int v : g[root])
            dfs(g, visited, v);
    }
}

void marchia2(vector<int> *g)
{
    int *visited = new int[N];
    int *zones = new int[N];
    vector<int> vicere;

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        zones[i] = -1;
    }

    for (int i = 0; i < N; i++)
    {

        if (isArt[i] && !visited[i])
        {
            art.clear();
            dfs(g, visited, i);
            if (art.size() == 1)
                vicere.push_back(i);
        }
    }

    ofstream out("output.txt");
    out << vicere.size() << endl;
    for (int i : vicere)
        out << i << " ";
    out << endl;
}

void findArticulations(vector<int> *g, int n, bool *visited, int *discovered, int *low, int *parent)
{
    static int depth = 0;
    int children = 0;

    depth++;

    visited[n] = true;
    discovered[n] = depth;
    low[n] = depth;

    for (int near : g[n])
    {
        if (!visited[near])
        {
            children++;
            parent[near] = n;
            findArticulations(g, near, visited, discovered, low, parent);

            low[n] = min(low[near], low[n]);

            if (parent[n] == -1 && children > 1)
                isArt[n] = true;

            if (parent[n] != -1 && low[near] >= discovered[n])
                isArt[n] = true;
        }
        else if (near != parent[n])
        {
            low[n] = min(low[near], discovered[n]);
        }
    }
}

void findArticulationsWrapper(vector<int> *g)
{
    bool *visited = new bool[N];
    int *discovered = new int[N];
    int *low = new int[N];
    int *parent = new int[N];

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        parent[i] = -1;
        isArt[i] = false;
    }

    for (int i = 0; i < N; i++)
        if (!visited[i])
            findArticulations(g, i, visited, discovered, low, parent);
}

int main()
{

    ifstream in("input.txt");
    in >> N;
    in >> M;

    vector<int> *g = new vector<int>[N];
    isArt = new bool[N];
    artVisited = new bool[N];

    for (int i = 0; i < M; i++)
    {
        int s, e;
        in >> s;
        in >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }

    findArticulationsWrapper(g);
    marchia2(g);

    return 0;
}