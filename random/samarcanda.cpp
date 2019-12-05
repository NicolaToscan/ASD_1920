#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

const int N = 10;

int P[N] = {3, 4, 1, 6, 1, 10, 6, 1, 5, 9};
int MAX[N];
int MIN[N];

int main()
{
    int tMax = P[N - 1];
    for (int i = N - 1; i >= 0; i--)
    {
        if (P[i] > tMax)
            tMax = P[i];
        MAX[i] = tMax;
    }

    int tMin = P[0];
    for (int i = 0; i < N; i++)
    {
        if (P[i] < tMin)
            tMin = P[i];
        MIN[i] = tMin;
    }

    int maxrev = 0;
    int maxPoint = 0;
    int minPoint = 0;
    for (int i = 0; i < N; i++)
    {
        if (MAX[i] - MIN[i] > maxrev)
        {
            maxrev = MAX[i] - MIN[i];
            maxPoint = MAX[i];
            minPoint = MIN[i];
        }
    }

    for (int i = 0; i < N; i++)
    {

        if (minPoint == P[i])
        {
            cout << i << endl;
            break;
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {

        if (maxPoint == P[i])
        {
            cout << i << endl;
            break;
        }
    }
}