#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <utility>
#include <queue>

#define MAX_LENGTH 1000000

using namespace std;

struct Travel
{
    int travelTime;
    int firstOff;
    int offTime;
    int onTime;
};

void stampaPercorso(ofstream *out, int curr);
void DJ(vector<pair<int, Travel>> *g);
int peso(int currTime, Travel t);

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int N, M;
bool visited[MAX_LENGTH];
int distanceTo[MAX_LENGTH];
int pred[MAX_LENGTH];

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

        if (travel.travelTime <= travel.offTime)
        {
            g[e].push_back(go);
            g[s].push_back(ret);
        }
    }

    DJ(g);

    bool finito = distanceTo[N - 1] != MAX_LENGTH;

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

void DJ(vector<pair<int, Travel>> *g)
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        distanceTo[i] = MAX_LENGTH;
        pred[i] = -1;
    }
    distanceTo[0] = 0;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        pair<int, int> next = q.top();
        q.pop();

        if (next.first >= MAX_LENGTH)
            break;

        //cout << "Trovata N:" << next.second << "\tDepth: " << next.first << endl;
        //for (int i = 0; i < N; i++) cout << distanceTo[i] << "\t"; cout << endl << endl;

        if (!visited[next.second])
        {
            visited[next.second] = true;
            for (auto n : g[next.second])
            {
                int alt = peso(next.first, n.second) + distanceTo[next.second];

                if (alt < distanceTo[n.first])
                {
                    pred[n.first] = next.second;
                    distanceTo[n.first] = alt;
                    q.push(make_pair(alt, n.first));
                }
            }
        }
    }
}

int peso(int currTime, Travel t)
{
    if (t.travelTime > t.offTime)
        return MAX_LENGTH;

    if (currTime <= t.firstOff)
        return (t.firstOff - currTime) + t.travelTime;

    int intervalLength = (t.offTime + t.onTime);
    int timeInInterval = (currTime - t.firstOff) % intervalLength;

    if (!(timeInInterval >= t.offTime) && (intervalLength - t.onTime - timeInInterval >= t.travelTime))
        return t.travelTime;

    return (intervalLength - timeInInterval) + t.travelTime;
}