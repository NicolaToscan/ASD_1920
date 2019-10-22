#include <fstream>
#include <iostream>
using namespace std;

int R, C;
int _mat[1000000];

int mat(int r, int c)
{
    return _mat[(r * C) + c];
}

int main()
{
    ifstream in("input.txt");
    in >> R;
    in >> C;

    for (int i = 0; i < R * C; i++)
        in >> _mat[i];

    int max = 0;
    int tempArr[C];


    for (int i = 0; i < R; i++)
    {
        for (int r = i; r < R; r++)
        {
            int tempMax = 0;
            for (int c = 0; c < C; c++)
            {
                if (r == i)
                    tempArr[c] = 0;
                tempArr[c] += mat(r, c);

                tempMax += tempArr[c];

                if (tempMax < 0)
                    tempMax = 0;

                if (tempMax > max)
                    max = tempMax;
            }
        }
    }

    ofstream out("output.txt");
    out << max << endl;
    return 0;
}
