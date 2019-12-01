#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <utility>
using namespace std;

struct Travel
{
    int travelTime;
    int firstOff;
    int offTime;
    int onTime;
};

void stampaPercorso(ofstream *out, int curr);
void initDJ(vector<pair<int, Travel>> *g);
void DJ(vector<pair<int, Travel>> *g);
bool allVisited();
int peso(int currTime, Travel t);
int waitingTime(int currTime, Travel t);
int test();

int N, M;
bool visited[1000000];
int distanceTo[1000000];
int pred[1000000];

void prt(int *v);
void prt(bool *v);

int main()
{

    ifstream in("input.txt");
    in >> N;
    in >> M;

    vector<pair<int, Travel>> g[N];

    for (int i = 0; i < M; i++)
    {
        int s, e;
        Travel travel;
        in >> s;
        in >> e;
        in >> travel.travelTime;
        in >> travel.firstOff;
        in >> travel.offTime;
        in >> travel.onTime;
        pair<int, Travel> go;
        pair<int, Travel> ret;
        go.first = s;
        go.second = travel;
        ret.first = e;
        ret.second = travel;

        g[e].push_back(go);
        g[s].push_back(ret);
    }

    initDJ(g);
    DJ(g);

    bool finito = distanceTo[N - 1] != 1000000;

    ofstream out("output.txt");
    if (!finito)
    {
        out << -1 << endl;
    }
    else
    {
        out << distanceTo[N - 1] << endl;
        stampaPercorso(&out, N - 1);
    }

    return 0;
}

void stampaPercorso(ofstream *out, int curr)
{
    if (curr == -1)
        return;
    stampaPercorso(out, pred[curr]);
    *out << curr << endl;
}

void initDJ(vector<pair<int, Travel>> *g)
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        distanceTo[i] = 1000000;
        pred[i] = -1;
    }

    visited[0] = true;
    distanceTo[0] = 0;
    for (auto nearNode : g[0])
    {
        distanceTo[nearNode.first] = peso(0, nearNode.second);
        pred[nearNode.first] = 0;
    }
}

void DJ(vector<pair<int, Travel>> *g)
{

    int from = 0;
    while (!allVisited())
    {

        //cout << endl;
        //cout << endl;
        int minDist = 1000000;
        int minNode = 1000000;
        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && distanceTo[i] < minDist)
            {
                //cout << "--------" << i << "\t" << visited[i] << endl;
                minDist = distanceTo[i];
                minNode = i;
            }
        }

        //cout << endl;
        //cout << "Min ditance: " << minDist << endl;
        //cout << "Min node: " << minNode << endl;
        //prt(distanceTo);
        //prt(visited);

        if (minDist == 1000000)
            return;

        visited[minNode] = true;
        for (auto n : g[minNode])
        {
            int alt = peso(minDist, n.second);
            if (alt < 1000000)
                alt += distanceTo[minNode];

            if (alt < distanceTo[n.first])
            {
                distanceTo[n.first] = alt;
                pred[n.first] = minNode;
            }
        }
    }
}

bool allVisited()
{
    for (int i = 0; i < N; i++)
        if (visited[i] == false)
            return false;
    return true;
}

int peso(int currTime, Travel t)
{
    int w = waitingTime(currTime, t);
    if (w < 1000000)
        w += t.travelTime;
    return w;
}

int waitingTime(int currTime, Travel t)
{
    if (t.travelTime > t.offTime)
        return 1000000;

    if (currTime <= t.firstOff)
        return t.firstOff - currTime;

    int intervalLength = (t.offTime + t.onTime);
    int timeInInterval = (currTime - t.firstOff) % intervalLength;

    int res;
    if (timeInInterval >= t.offTime) //Is in on time, waiting for next off
    {
        res = intervalLength - timeInInterval;
    }
    else // Off time
    {
        if (intervalLength - t.onTime - timeInInterval >= t.travelTime) // Is off, can make it in time
            res = 0;
        else //Waiting next interval
            res = intervalLength - timeInInterval;
    }

    return res;
}

int test()
{
    Travel t;
    cout << "Traveling time:\t";
    cin >> t.travelTime;
    cout << "First Off:\t";
    cin >> t.firstOff;
    cout << "Off Time:\t";
    cin >> t.offTime;
    cout << "On Time:\t";
    cin >> t.onTime;

    int currTime = 0;
    while (currTime != -1)
    {
        cout << "Current time:\t";
        cin >> currTime;
        int res = waitingTime(currTime, t);
        cout << "Result:\t\t\t" << res << endl;
    }
}

void prt(int *v)
{
    for (int i = 0; i < N; i++)
        cout << v[i] << "\t";
    cout << endl;
}

void prt(bool *v)
{
    for (int i = 0; i < N; i++)
        cout << v[i] << "\t";
    cout << endl;
}