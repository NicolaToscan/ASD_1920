#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <utility>
#include <queue>

#define MAX_LENGTH 1000000

using namespace std;

int N, M;

int main()
{

    ifstream in("input.txt");
    in >> N;
    in >> M;
    
    vector<int> g[N];

    for (int i = 0; i < M; i++)
    {
        int s, e;
        in >> s;
        in >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }

    //ofstream out("output.txt");
    return 0;
}