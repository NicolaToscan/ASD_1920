#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

int ccc(vector<int> *g, int exploded);
void marchiaDFS(vector<int> *g, int zoneCount, int from, int exploded);
int zones[1000000];
bool isFulcro[1000000];

int N, M;

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

    int baseCC = ccc(g, -2);
    int max = baseCC;
    for (int i = 0; i < N; i++)
    {
        int t = ccc(g, i);
        if (t > baseCC)
            isFulcro[i] = true;
        if (t > max)
            max = t;
    }


    cout << max + 1 << endl;

    return 0;
}

int ccc(vector<int> *g, int exploded)
{
    for (int i = 0; i < N; i++)
    {
        zones[i] = -1;
    }

    int zoneCount = 0;

    for (int n = 0; n < N; n++)
        if (n != exploded)
            if (zones[n] == -1)
                marchiaDFS(g, ++zoneCount, n, exploded);

    return zoneCount;
}

void marchiaDFS(vector<int> *g, int zoneCount, int from, int exploded)
{
    if (zones[from] != -1 || from == exploded)
        return;

    zones[from] = zoneCount;
    for (auto n : g[from])
        marchiaDFS(g, zoneCount, n, exploded);
}