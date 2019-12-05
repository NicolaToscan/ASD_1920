#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

const int N = 10;

int A[N];
int cerca1(int from, int to);
int cerca2(int from, int to);
int cerca3(int from, int to);

int main()
{
    int r;

    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 4;
    A[4] = 5;
    A[5] = 6;
    A[6] = 7;
    A[7] = 8;
    A[8] = 9;
    A[9] = 10;
    r = A[0] == 0 ? cerca1(0, N) : 0;
    cout << r << endl;

    A[0] = -5;
    A[1] = -3;
    A[2] = -2;
    A[3] = 0;
    A[4] = 4;
    A[5] = 6;
    A[6] = 7;
    A[7] = 8;
    A[8] = 9;
    A[9] = 11;
    r = cerca2(0, N);
    cout << r << endl;

    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 4;
    A[4] = 5;
    A[5] = 6;
    A[6] = 7;
    A[7] = 8;
    A[8] = 9;
    A[9] = 10;
    r = cerca3(0, N);
    cout << r << endl;
}

int cerca1(int from, int to)
{

    if (from == to - 1)
        return from + 1;

    int mid = (to + from) / 2;
    if (A[mid] != mid)
        return cerca1(from, mid);
    else
        return cerca1(mid, to);
}

int cerca2(int from, int to)
{
    int mid = (to + from) / 2;
    if (A[mid] == mid)
        return mid;

    if (A[mid] > mid)
        return cerca2(from, mid);
    else
        return cerca2(mid, to);
}

int cerca3(int from, int to)
{
    if (from == to - 1)
        return from;

    int mid = (to + from) / 2;
    if (A[mid] < A[mid + 1])
        return cerca3(from, mid);
    else
        return cerca3(mid + 1, to);
}