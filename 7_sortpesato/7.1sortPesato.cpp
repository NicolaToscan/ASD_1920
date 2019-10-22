#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

int N;
int a[100000];
int b[100000];
int c[100000];

int main()
{
    ifstream in("input.txt");
    in >> N;
    int t;
    for (int i = 0; i < N; i++)
    {
        in >> t;
        a[i] = t;
        b[i] = t;
        c[i] = t;
    }

    float turni2 = N - 1;
    for (int i = 0; i < N; i++)
    {
        if (a[i] == i + 1)
        {
            turni2--;
            cout << i << endl;
        }
        else if (a[a[i] - 1] == i + 1)
        {
            turni2 -= 0.5;
            cout << i << endl;
        }
    }
    cout << endl;

    //TURNI
    int turni = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (a[i] != i + 1)
        {
            int j = 0;
            while (a[j] != i + 1)
                j++;

            int t = a[j];
            a[j] = a[i];
            a[i] = t;
            turni++;
        }
    }

    //PESO
    int peso = 0;
    for (int f = 1; f <= N; f++)
    {
        while (b[f - 1] != f)
        {

            int i = 0;
            while (b[i] != f)
                i++;

            int j = 0;
            while (b[j] != i + 1)
                j++;

            cout << "b[" << j << "]:\t" << b[j] << "\t\t";
            cout << "b[" << i << "]:\t" << b[i] << "\t\t";

            int t = b[j];
            b[j] = b[i];
            b[i] = t;
            peso += b[j] + b[i];

            cout << peso << endl;
        }
    }

    cout << endl;

    int peso2 = 0;
    for (int j = N - 1; j >= 0; j--)
    {
        if (c[j] != j + 1)
        {

            int i = 0;
            while (c[i] != j + 1)
                i++;

            cout << "c[" << j << "]:\t" << c[j] << "\t\t";
            cout << "c[" << i << "]:\t" << c[i] << "\t\t";

            int t = c[j];
            c[j] = c[i];
            c[i] = t;
            peso2 += c[j] + c[i];

            cout << peso2 << endl;
        }
    }

    cout << endl;
    cout << turni << " " << peso << endl;
    cout << turni2 << " " << peso2 << endl;

    ofstream out("output.txt");
    out << turni << " " << peso;

    return 0;
}
