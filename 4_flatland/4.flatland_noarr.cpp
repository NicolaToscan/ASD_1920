#include <fstream>
#include <iostream>
using namespace std;

int N;
char d;
int leftSD = -1;
int rightSD = -1;
int j = 0;

bool checkL(int i, char c);
bool checkR(int i, char c);

int main()
{
    ifstream in("input.txt");
    in >> N;
    //in >> d;

    //Search for SDs
    leftSD = N;
    rightSD = -1;

    char d0, d1, d2;
    in >> d0;

    int i = 1;
    do
    {
        if (i == 1)
            in >> d0;
        else
            d0 = d2;
        in >> d1;
        in >> d2;

        if (leftSD == N && d0 == 's' && d1 == 'd')
            leftSD = i;
        if (d1 == 's' && d2 == 'd')
            rightSD = i + 1;

        i += 2;
    } while (i < N - 3);

    ifstream in2("input.txt");

    char cPrev = 's', c, cSucc = 's';
    in2 >> N;
    //Check all number
    for (int i = 0; i < N; i += 2)
    {

        cPrev = cSucc;
        in2 >> c;
        in2 >> cSucc;

        cout << i << "\t" << checkL(i, cPrev) << checkR(i, cSucc) << endl;
        cout << cPrev << c << cSucc << endl;
        cout << endl;

        if (checkL(i, cPrev) && checkR(i, cSucc) && false)
            cout << i;
    }
    cout << endl;

    return 0;
}

bool checkL(int i, char c)
{
    return ((i == 0) || (c == 's') || (leftSD <= i - 3));
}

bool checkR(int i, char c)
{
    return ((i == N - 1) || (c == 'd') || (rightSD >= i + 2));
}
