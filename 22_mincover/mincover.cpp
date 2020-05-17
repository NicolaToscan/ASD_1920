#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

ifstream in("input.txt");
#ifdef EVAL
ofstream out("output.txt");
#else
ostream &out(cout);
#endif

vector<int> *g;
int *parents;

pair<int, int> *DP;

int solve(int n, bool prendimi);

int main()
{
    int N;
    in >> N;
    g = new vector<int>[N];
    parents = new int[N];
    DP = new pair<int, int>[N];

    for (int i = 0; i < N; i++)
        DP[i] = make_pair(-1, -1);

    parents[0] = -1;

    for (int i = 0; i < N - 1; i++)
    {
        int p, c;
        in >> p >> c;
        g[p].push_back(c);
        parents[c] = p;
    }

    out << solve(0, false) << endl;

    return 0;
}

int solve(int n, bool prendimi)
{
    int dp = prendimi ? DP[n].first : DP[n].second;
    if (dp != -1)
        return dp;

    int a = 1;
    for (auto c : g[n])
        a += solve(c, false);

    if (prendimi) {
        DP[n].first = a;
        return a;
    }

    int b = 0;
    for (auto c : g[n])
        b += solve(c, true);

    int res = min(a, b);
    if (prendimi)
        DP[n].first = res;
    else
        DP[n].second = res;
    
    return res;
}