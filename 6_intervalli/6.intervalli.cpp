#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

void insertData();
long findIntervals();
pair<long, long> findMax(int j);
void mergeSort(long str, long end);
void merge(long str, long m, long end);

pair<long, long> arr[100000];
long N;

int main()
{
    insertData();
    mergeSort(0, N);
    long j = findIntervals();
    pair<long, long> res = findMax(j);

    ofstream out("output.txt");
    out << res.first << " " << res.second;

    return 0;
}

void insertData()
{
    ifstream in("input.txt");
    in >> N;
    for (long i = 0; i < N; i++)
    {
        pair<long, long> c;
        in >> c.first;
        in >> c.second;
        arr[i] = c;
    }
}

long findIntervals()
{
    long j = 0;
    long i = 0;
    while (i < N)
    {
        pair<long, long> c;
        c.first = arr[i].first;
        c.second = arr[i].second;
        i++;

        while (i < N && c.second > arr[i].first)
        {
            if (arr[i].second > c.second)
                c.second = arr[i].second;
            i++;
        }

        arr[j++] = c;
    }
    return j;
}

pair<long, long> findMax(int j)
{
    long max = 0;
    pair<long, long> res;

    for (long i = 0; i < j - 1; i++)
    {
        long t = arr[i + 1].first - arr[i].second;
        if (t > max)
        {
            max = t;
            res.first = arr[i].second;
            res.second = arr[i + 1].first;
        }
    }
    return res;
}

void mergeSort(long str, long end)
{
    if (end - str <= 1)
        return;

    long m = ((end - str) / 2) + str;

    mergeSort(str, m);
    mergeSort(m, end);

    merge(str, m, end);
}

void merge(long str, long m, long end)
{
    pair<long, long> res[end - str];
    long i = str, j = m, k = 0;

    while (i < m && j < end)
        res[k++] = (arr[i].first < arr[j].first) ? arr[i++] : arr[j++];

    while (i < m)
        res[k++] = arr[i++];
    while (j < end)
        res[k++] = arr[j++];

    for (long ii = 0; ii < end - str; ii++)
        arr[ii + str] = res[ii];
}