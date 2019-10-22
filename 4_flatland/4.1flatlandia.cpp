#include <fstream>
#include <iostream>
using namespace std;

int N;
string d;
int res[1000];

bool remains(int str, int end, bool left);

int main()
{
    ifstream in("input.txt");
    in >> N;
    in >> d;

    int j = 0;
    for (int i = 0; i < N; i += 2)
    {
        bool cl = remains(0, i, true);
        bool cr = remains(i + 1, N, false);

        cout << i << endl;
        cout << "Left  " << cl << endl;
        cout << "Right " << cr << endl;
        cout << endl;

        if (cl && cr)
            res[j++] = i;
    }

    ofstream out("output.txt");
    out << j << endl;
    for (int i = 0; i < j; i++)
        out << res[i] << " ";
    return 0;
}

bool remains(int str, int end, bool left)
{
    if (end - str == 0)
        return true;

    //Maybe inutile
    if (end - str == 2)
        return left ? (d[str + 1] == 's') : (d[str] == 'd');

    if ((left && d[end - 1] == 's') ||
        (!left && d[str] == 'd'))
        return true;

    for (int i = str + 1; i < end - 1; i += 2)
        if (d[i] == 's' && d[i + 1] == 'd')
            return true;

    return false;
}