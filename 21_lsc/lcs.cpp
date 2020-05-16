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

int **DP;
string s1, s2;

int lcs(int n, int m);

int main()
{
    in >> s1;
    in >> s2;

    int N = s1.length();
    int M = s2.length();

    DP = new int *[N];
    for (int i = 0; i < N; i++)
    {
        DP[i] = new int[M];
        for (int j = 0; j < M; j++)
            DP[i][j] = -1;
    }

    out << lcs(N - 1, M - 1) << endl;
    return 0;
}

int lcs(int n, int m)
{
    if (n < 0 || m < 0)
        return 0;

    if (DP[n][m] != -1)
        return DP[n][m];

    int res = 0;
    if (s1[n] == s2[m])
        res = lcs(n - 1, m - 1) + 1;
    else
        res = max(lcs(n, m - 1), lcs(n - 1, m));
    
    DP[n][m] = res;
    return res;
}