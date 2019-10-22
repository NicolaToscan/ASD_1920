#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

int N;
int a[100000];
int b[100000];

pair<int, int> swapAndPeso();
int pesoVeloce(int ciclo[], int N);
void randomSwap();

int main()
{
    ifstream in("input.txt");
    in >> N;
    for (int i = 1; i <= N; i++)
    {
        int t;
        in >> t;
        cout << t << " ";
        a[i] = t;
        b[i] = t;
    }
    cout << endl
         << endl;

    int s1 = 0, s2 = 0;
    while (s1 != -1)
    {
        int p = 0;
        if (s1 != s2)
        {
            int t = a[s2];
            a[s2] = a[s1];
            a[s1] = t;
            p = a[s1] + a[s2];
        }

        for (int i = 1; i <= N; i++)
            cout << i << "\t";
        cout << endl;
        for (int i = 1; i <= N; i++)
        {
            b[i] = a[i];
            cout << b[i] << "\t";
        }
        cout << endl;

        pair<int, int> c = swapAndPeso();

        cout << c.first << " " << c.second + p << endl;

        cout << endl;
        cin >> s1;
        cin >> s2;
        cout << endl;
    }

    pair<int, int> c = swapAndPeso();

    ofstream out("output.txt");
    out << c.first << " " << c.second;

    return 0;
}

void randomSwap()
{
}

pair<int, int> swapAndPeso()
{
    int peso = 0;

    //TURNI
    int cicli = 0;
    int str = 1;
    while (str <= N)
    {
        int ciclo[N];
        int iCiclo = 0;

        int i = str;
        do
        {
            int oldI = i;
            ciclo[iCiclo++] = b[i];
            i = b[i];
            b[oldI] = -1;

        } while (str != i);

        peso += pesoVeloce(ciclo, iCiclo);

        while (b[str] == -1)
            str++;
        cicli++;
    }

    return make_pair(N - cicli, peso);
}

int pesoVeloce(int ciclo[], int N)
{
    cout << "CICLO:" << endl;
    for (int i = 0; i < N; i++)
        cout << ciclo[i] << " ";
    cout << endl;

    int sum = ciclo[0];
    int min = ciclo[0];
    for (int i = 1; i < N; i++)
    {
        sum += ciclo[i];
        if (ciclo[i] < min)
            min = ciclo[i];
    }
    sum -= min;

    int peso = (min * (N - 1)) + sum;
    cout << "PESO:\t" << peso << endl;
    cout << endl;
    return peso;
}

int cicli()
{
    //TURNI
    int cicli = 0;
    int str = 1;
    while (str <= N)
    {
        int i = str;
        do
        {
            int oldI = i;
            i = a[i];
            a[oldI] = -1;
        } while (str != i);

        while (a[str] == -1)
            str++;
        cicli++;
    }

    return cicli;
}
