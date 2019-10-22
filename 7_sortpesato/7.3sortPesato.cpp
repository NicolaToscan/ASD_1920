#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

struct cicloData
{
    int i;
    bool deleted;
    int min;
    int N;
    int sum;
};

int N;
int a[100000];
int b[100000];

int pesoExtra = 0;

cicloData cicli[100000];
int nCicli = 0;

pair<int, int> swapAndPeso();
void getCicli();
void printCicli();
int pesoTot();
cicloData getCicloData(int ciclo[], int N);
void unisciCicli();
int peso(cicloData c);

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

    getCicli();
    printCicli();
    unisciCicli();
    printCicli();

    int S = N - nCicli;
    int P = pesoTot() + pesoExtra;
    cout << S << " " << P << endl;
    ofstream out("output.txt");
    out << S << " " << P;

    return 0;
}

void getCicli()
{
    int peso = 0;

    //TURNI
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

        cicli[nCicli++] = getCicloData(ciclo, iCiclo);

        while (b[str] == -1)
            str++;
    }
}

int cont = 0;
cicloData getCicloData(int ciclo[], int N)
{
    cout << cont << ":\t";
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

    cicloData res;
    res.min = min;
    res.sum = sum;
    res.N = N;
    res.deleted = false;
    res.i = cont++;

    return res;
}

void printCicli()
{
    for (int i = 0; i < nCicli; i++)
        if (!cicli[i].deleted)
            cout << cicli[i].i << ": Ciclo\t" << peso(cicli[i]) << endl;
    cout << endl;
}

void unisciCicli()
{
    int i = 0;
    int j = 1;
    while (j < nCicli)
    {
        if (!cicli[j].deleted)
        {
            cicloData uniti;
            uniti.min = cicli[i].min;
            uniti.N = cicli[i].N + cicli[j].N;
            uniti.sum = cicli[i].sum + cicli[j].sum + cicli[j].min;
            uniti.i = cicli[i].i;

            if (peso(uniti) + cicli[i].min + cicli[j].min < peso(cicli[i]) + peso(cicli[j]))
            {
                pesoExtra += cicli[i].min + cicli[j].min;
                cout << "FUSO: " << i << " " << j << endl;
                cicli[j].deleted = true;
                cicli[i] = uniti;
                j = 0;
            }
        }
        j++;
    }
}

int pesoTot()
{
    int res = 0;
    for (int i = 0; i < nCicli; i++)
        if (!cicli[i].deleted)
            res += peso(cicli[i]);
    return res;
}

int peso(cicloData c)
{
    return c.min * (c.N - 1) + c.sum;
}
