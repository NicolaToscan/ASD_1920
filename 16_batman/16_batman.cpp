#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define MAX_LENGTH 1000000

using namespace std;

int N, M;

int S, E;
bool visited[1000000];

stack<int>* ordTop(vector<int> *g);
void visita(vector<int> *g, int from, stack<int> *res);

int main()
{

    ifstream in("input.txt");
    in >> N;
    in >> M;
    in >> S;
    in >> E;

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

    ordTop(g);

    //ofstream out("output.txt");
    return 0;
}

bool backFrom[1000];

stack<int>* ordTop(vector<int> *g)
{
    for (int i = 0; i < N; i++)
        visited[i] = true;

    stack<int> res;
    visita(g, S, &res);

    return &res;
}

void visita(vector<int> *g, int from, stack<int> *res)
{
    if (visited[from]) {
        return;
    }

    visited[from] = true;
    for (auto n : g[from])
        visita(g, n, res);

    (*res).push(from);
}