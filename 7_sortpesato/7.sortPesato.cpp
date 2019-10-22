#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

int N;
int a[100000];

pair<int, int> getSwapAndPeso();

int main()
{
    ifstream in("input.txt");
    in >> N;
    for (int i = 1; i <= N; i++)
        in >> a[i];

    auto c = getSwapAndPeso();

    //cout << c.first << " " << c.second << endl;
    ofstream out("output.txt");
    out << c.first << " " << c.second;

    return 0;
}

pair<int, int> getSwapAndPeso()
{
    int peso = 0;
    int cicli = 0;

    int str = 1;
    while (str <= N) //Creo ciclo
    {
        int sum = 0;
        int L = 0;
        int min = N;

        int i = str;
        do
        {
            sum += a[i];
            L++;
            if (a[i] < min)
                min = a[i];

            int oldI = i;
            i = a[i];
            a[oldI] = -1;

        } while (str != i);
        sum -= min;

        int p1 = (min * (L - 1)) + sum;
        int p2 = L + sum + (2 * min) + 1;
        peso += p1 < p2 ? p1 : p2;
        cicli++;

        while (a[str] == -1)
            str++;
    }

    return make_pair(N - cicli, peso);
}
