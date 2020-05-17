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
int *w;

pair<int, int> *DP;

int solve(int n, bool prendimi);

int main()
{
    int N;
    in >> N;
    g = new vector<int>[N];
    w = new int[N];
    DP = new pair<int, int>[N];

    for (int i = 0; i < N; i++) {
        DP[i] = make_pair(-1, -1);
        in >> w[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int p, c;
        in >> p >> c;
        g[p].push_back(c);
    }

    out << solve(0, false) << endl;

    return 0;
}

int solve(int n, bool prendimi)
{
    int dp = prendimi ? DP[n].first : DP[n].second;
    if (dp != -1)
        return dp;

    int a = w[n];
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