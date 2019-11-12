#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int N, M;
int counter = 0;
bool visited[10000];

void visita(vector<int> *g, int da);

int main()
{
    int start;

    ifstream in("input.txt");
    in >> N;
    in >> M;
    in >> start;

    vector<int> g[N];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < M; i++)
    {
        int s, e;
        in >> s;
        in >> e;
        g[s].push_back(e);
    }

    visita(g, start);

    ofstream out("output.txt");
    out << counter;

    return 0;
}

void visita(vector<int> *g, int da)
{
    if (visited[da])
        return;
    counter++;
    visited[da] = true;

    for (std::vector<int>::iterator it = g[da].begin(); it != g[da].end(); ++it)
        visita(g, *it);
    
}