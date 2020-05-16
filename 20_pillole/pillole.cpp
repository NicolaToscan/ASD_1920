#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

ifstream in("input.txt");
#ifdef EVAL
ofstream out("output.txt");
#else
ostream &out(cout);
#endif

long long int calc(int N, int half);
long long int **DP;

int main()
{
    int N;
    in >> N;

    DP = new long long int *[N + 1];
    for (int i = 0; i <= N; i++)
    {
        DP[i] = new long long int[(2 * N) + 1];
        for (int j = 0; j <= 2 * N; j++)
            DP[i][j] = -1;
    }
    DP[0][0] = 1;

    long long int res = calc(N, 0);
    out << res << endl;

    return 0;
}

long long int calc(int n, int h)
{
    if (h < 0 || n < 0)
        return 0;

    if (DP[n][h] != -1)
        return DP[n][h];

    long long int res = calc(n - 1, h + 1) + calc(n, h - 1);
    DP[n][h] = res;
    return res;
}