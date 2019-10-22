#include <fstream>
#include <iostream>
using namespace std;

int N;
int arr[1000000];

void mergeSort(int str, int end);
void merge(int str, int m, const int end);

int main()
{
    int N, M;
    ifstream in("input.txt");
    in >> N;

    for (int i = 0; i < N; i++)
        in >> arr[i];

    mergeSort(0, N);

    ofstream out("output.txt");
    for (int i = 0; i < N; i++)
        out << arr[i] << " ";
    return 0;
}

void mergeSort(int str, int end)
{
    if (end - str <= 1)
        return;

    int m = ((end - str) / 2) + str;

    mergeSort(str, m);
    mergeSort(m, end);

    merge(str, m, end);
}

void merge(int str, int m, int end)
{
    int res[end - str];
    int i = str, j = m, k = 0;

    while (i < m && j < end)
        res[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];

    while (i < m)
        res[k++] = arr[i++];
    while (j < end)
        res[k++] = arr[j++];

    for (int ii = 0; ii < end - str; ii++)
        arr[ii + str] = res[ii];
}