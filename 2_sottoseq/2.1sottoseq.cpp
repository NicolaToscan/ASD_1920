#include <fstream>
using namespace std;

int main()
{
    int N;
    int mx = 0;
    
    ifstream in("input.txt");
    in >> N;

    int tempMax = 0;
    int t;
    for (int i = 0; i < N; i++) {
        in >> t;
        tempMax += t;
        if (tempMax < 0)
            tempMax = 0;
        if (tempMax > mx)
            mx = tempMax;
    }


    ofstream out("output.txt");
    out << mx << endl;
    return 0;
}