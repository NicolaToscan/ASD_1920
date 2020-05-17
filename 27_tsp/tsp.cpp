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
bool *toDo;
int *sol;

int minSol = INT32_MAX;

void solveQuasi();
int findMin(int n);
void printSol();
int calcW();
void bedandbreakfast(int i, int cost);

int main()
{
    srand(time(NULL));
    in >> N;

    map = new int *[N];
    done = new bool[N];
    toDo = new bool[N];
    sol = new int[N];
    for (int i = 0; i < N; i++)
    {
        sol[i] = -1;
        done[i] = false;
        toDo[i] = true;
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
    minSol = calcW();
    printSol();

    for (int i = 0; i < N; i++)
        done[i] = false;

    bedandbreakfast(0, 0);

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

void bedandbreakfast(int i, int cost)
{
    int ch[N];
    int num[N];
    for (int i = 0; i < N; i++)
    {
        ch[i] = toDo[i];
        num[i] = i;
    }
    random_shuffle(&num[0], &num[N]);

    for (int ff = 0; ff < N; ff++)
    {
        int c = num[ff];
        if (ch[c])
        {

            sol[i] = c;
            toDo[c] = false;

            if (i < N - 1)
            {
                int lb = 0;

                // # LB #
                // int out = INT32_MAX;
                // int back = INT32_MAX;
                // int transTot = 0;
                // int toDos = 0;
                // for (int k = 0; k < N; k++)
                // {
                //     if (toDo[k])
                //     {
                //         if (map[k][c] < out)
                //             out = map[k][c];
                //         if (map[k][sol[0]] < back)
                //             back = map[k][sol[0]];

                //         toDos++;
                //     }
                // }

                // if (toDos > 2)
                //     for (int k = 0; k < N; k++)
                //     {
                //         int transLoc = INT32_MAX;
                //         for (int p = 0; p < N; p++)
                //             if (toDo[p] && p != k)
                //                 for (int q = 0; q < N; q++)
                //                     if (toDo[q] && q != p)
                //                         if (map[q][k] + map[k][p] < transLoc)
                //                             transLoc = map[q][k] + map[k][p];
                //         transTot += transLoc;
                //     }

                // lb = cost + ((out + transTot + back) / 2) + 1;

                if (lb < minSol)
                {

                    int nxCost = 0;
                    if (i != 0)
                        nxCost = cost + map[sol[i - 1]][c];
                    bedandbreakfast(i + 1, nxCost);
                }
            }
            else
            {
                cost += map[c][sol[0]] + map[c][sol[i - 1]];
                if (cost < minSol)
                {
                    printSol();
                    minSol = cost;
                }
            }

            toDo[c] = true;
        }
    }
}
