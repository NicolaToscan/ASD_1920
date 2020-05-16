#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int C, N;
vector<vector<int>> DP;
int *pes;
int *val;

int solve(int i, int c);

main()
{
    ifstream in("input.txt");
    in >> C;
    in >> N;

    pes = new int[N + 1];
    val = new int[N + 1];

    DP.resize(N + 1);
    for (int i = 0; i <= N; i++)
    {
        DP[i].resize(C + 1);
        for (int j = 0; j <= C; j++)
            DP[i][j] = -1;
    }

    for (int i = 1; i <= N; i++)
    {
        pair<int, int> p;
        in >> pes[i];
        in >> val[i];
    }

    int res = solve(N, C);
    ofstream out("output.txt");
    out << res;
    return 0;
}

int solve(int i, int c)
{
    if (c < 0)
        return INT32_MIN;

    if (i <= 0 || c == 0)
        return 0;

    if (DP[i][c] < 0)
    {
        int s2 = solve(i - 1, c);
        int s1 = solve(i - 1, c - pes[i]) + val[i];

        DP[i][c] = max(s1, s2);
    }

    return DP[i][c];
}