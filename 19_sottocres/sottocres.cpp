#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int N;
    in >> N;

    int A[N + 1];
    int DP[N + 1];
    int presi[N + 1];
    A[0] = 0;
    DP[0] = 0;
    presi[0] = 0;

    for (int i = 1; i < N + 1; i++)
    {
        in >> A[i];
        DP[i] = 0;
        presi[i] = 0;
    }

    int mx = 0;
    for (int i = 1; i < N + 1; i++)
    {
        DP[i] = A[i];
        for (int j = 1; j < i; j++)
            if (A[i] >= A[j])
                DP[i] = max(DP[i], DP[j] + A[i]);
        if (DP[i] > mx)
            mx = DP[i];
    }

    ofstream out("output.txt");
    cout << mx << endl;
    out << mx << endl;
    return 0;
}
