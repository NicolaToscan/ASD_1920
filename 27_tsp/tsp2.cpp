#include "tsp.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <ctime>

// g++ -DEVAL -std=c++11 -O2 -pipe -static -s -o a.out grader.cpp tsp.cpp

using namespace std;

ifstream in("input.txt");
#ifdef EVAL
ofstream out("output.txt");
#else
ostream &out(cout);
#endif

int **map;
int N;
bool *done;
int *sol;

int minSol = INT32_MAX;

void solveQuasi();
int findMin(int n);
void printSol();
int calcW();
void randomizee();

int main()
{
    srand(time(NULL));
    in >> N;

    map = new int *[N];
    done = new bool[N];
    sol = new int[N];
    for (int i = 0; i < N; i++)
    {
        sol[i] = -1;
        done[i] = false;
        map[i] = new int[N];
        map[i][i] = INT32_MAX / 100000;
    }

    int w;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            in >> w;
            map[i][j] = w;
            map[j][i] = w;
        }
    }

    solveQuasi();
    randomizee();
    return 0;
}

void solveQuasi()
{
    sol[0] = 0;
    done[0] = true;
    int next = 0;
    for (int i = 1; i < N; i++)
    {
        next = findMin(next);
        sol[i] = next;
        done[next] = true;
    }

    printSol();
}

int findMin(int n)
{
    int minVal = INT32_MAX;
    int min = -1;
    for (int i = 0; i < N; i++)
    {
        if (!done[i] && map[n][i] < minVal)
        {
            minVal = map[n][i];
            min = i;
        }
    }
    return min;
}

void printSol()
{
    for (int i = 0; i < N; i++)
        out << sol[i] << " ";
    out << sol[0] << "#";

    //out << "\t" << calcW();
    out << endl;
}

int calcW()
{
    int w = 0;
    for (int i = 0; i < N - 1; i++)
        w += map[sol[i]][sol[i + 1]];
    w += map[sol[0]][sol[N - 1]];
    return w;
}

void randomizee()
{
    int min = calcW();
    int *backUp = new int[N];
    for (int i = 0; i < N; i++)
        backUp[i] = sol[i];

    int c = 0;
    while (true)
    {
        int T = 20;
        pair<int, int> sw[T];
        int minW = INT32_MAX;
        int minWIndex = INT32_MAX;
        for (int t = 0; t < T; t++)
        {
            int a = rand() % N;
            int b = rand() % N;
            sw[t] = make_pair(a, b);
            swap(sol[a], sol[b]);
            int w = calcW();
            swap(sol[a], sol[b]);

            if (w < minW)
            {
                minW = w;
                minWIndex = t;
            }
        }
        swap(sw[minWIndex].first, sw[minWIndex].second);

        if (minW < min)
        {
            printSol();
            min = minW;
        }
        c++;

        if (c % N * 4000 == 0)
        {
            for (int i = 0; i < N; i++)
                sol[i] = i;
            random_shuffle(&sol[0], &sol[N]);
        }
    }
}