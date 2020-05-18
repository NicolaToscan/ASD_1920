//#include "alpini.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <ctime>
#include <queue>

using namespace std;

ifstream in("input.txt");
#ifdef EVAL
ofstream out("output.txt");
#else
ostream &out(cout);
#endif

bool hasCycle();
void delBiggest();
void printSol();
void rann();
int countCycle();

int N, M;
vector<int> *g;
bool *removed;
int nRemoved;
int minRemoved = INT32_MAX;

int main()
{
    in >> N >> M;
    g = new vector<int>[N];

    removed = new bool[N];
    for (int i = 0; i < N; i++)
        removed[i] = false;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        in >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    delBiggest();
    rann();

    return 0;
}

void printSol()
{
    out << nRemoved << " ";
    for (int i = 0; i < N; i++)
        if (removed[i])
            out << i << " ";
    out << "#" << endl;
}

bool hasCycle()
{
    bool *visited = new bool[N];
    int *parents = new int[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        parents[i] = -1;
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && !removed[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int n = q.front();
                q.pop();

                for (int c : g[n])
                {
                    if (!removed[c])
                    {
                        parents[c] = n;
                        if (!visited[c])
                        {
                            visited[c] = true;
                            q.push(c);
                        }
                        else if (parents[n] != c)
                            return true;
                    }
                }
            }
        }
    }

    return false;
}

int countCycle()
{
    int cy = 0;

    bool *visited = new bool[N];
    int *parents = new int[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        parents[i] = -1;
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && !removed[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int n = q.front();
                q.pop();

                for (int c : g[n])
                {
                    if (!removed[c])
                    {
                        parents[c] = n;
                        if (!visited[c])
                        {
                            visited[c] = true;
                            q.push(c);
                        }
                        else if (parents[n] != c)
                            cy++;
                    }
                }
            }
        }
    }

    return cy;
}

void delBiggest()
{
    pair<int, int> *nCross_index = new pair<int, int>[N];

    priority_queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
        q.push(make_pair(g[i].size(), i));

    while (hasCycle())
    {
        removed[q.top().second] = true;
        q.pop();
        nRemoved++;
    }

    minRemoved = nRemoved;

    printSol();
}

void rann()
{
    srand(time(NULL));
    int i = 0;
    int lim = 100000 / M;
    while (i++ < lim)
    {
        nRemoved = 0;
        for (int i = 0; i < N; i++)
            removed[i] = false;

        while (hasCycle())
        {
            removed[rand() % N] = true;
            nRemoved++;
        }

        if (nRemoved < minRemoved)
        {
            minRemoved = nRemoved;
            printSol();
        }
    }
}

void bandb(int toRem, int i)
{

}