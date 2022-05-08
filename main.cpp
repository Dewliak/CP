#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;

bool marked[MAX];

vector <PII> adj[100001];

vector<pair<int,int>> points{};

vector<bool> visited(40,false);

/*
    A Manhattan t�vols�g kisz�mol�sa x kordin�t�k k�l�nbs�ge + y kordin�t�k k�l�nbs�ge
*/
int calc_Manhattan_dist(pair<int,int> p1, pair<int,int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);

}

long long prim(int source){

    priority_queue<PII, vector<PII>, greater<PII> > Q;

    int y;
    long long minimumCost = 0;

    PII p;

    Q.push(make_pair(0, source));
    visited[source] = true;
    while(!Q.empty())
    {

        p = Q.top();
        Q.pop();

        source = p.second;
        visited[source] = true;

        // Ha m�r volt tov�bb megy
        if(marked[source] == true){
            continue;
        }

        minimumCost += p.first;
        marked[source] = true;
        visited[source] = true;

        for(int i = 0;i < adj[source].size();++i)
        {
            y = adj[source][i].second;
            if(marked[y] == false)
                Q.push(adj[source][i]);
        }
    }

    return minimumCost;
}

int main()
{

    int N;

    cin >> N;

    /*
        A pontokat elmentj�k egy t�mbben
    */
    for(int i =0; i < N; i++){
        int a,b;
        cin >> a >> b;
        points.PB(MP(a,b));
    }
    /*
        A pontokat �sszek�tj�k �s a manhattan t�vols�ggal kisz�moljuk az �lek hossz�t, mivel a cs�vek csak a pontokban �gazhatnak el,
        ez�rt csak akkor vesz�nk fel egy �lt, ha azonos oszlopban vagy sorban van
    */
    for(int i =0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(points[i].first == points[j].first || points[i].second == points[j] .second){
                int dist = calc_Manhattan_dist(points[i],points[j]);

                adj[i].PB(MP(dist,j));
                adj[j].PB(MP(dist,i));
            }

        }
    }

    /*
        A legr�videbb cs�h�l�zat hossza
    */
    long long minimumLength;

    /*
        Ez m�g lehet nem pontos, mivel a cs�csoknak nincsenek neveik, �gy a 0 a gr�f legels� eleme lesz
    */
    minimumLength = prim(0);

    bool flag{true};

    /*
        Ha a fesz�t� f�ban nincs benne valamelyik �l, akkor nincs megold�s
    */
    for(int i =0; i< N; i++){
        cout << i << " : " << visited[i] << endl;
        if(visited[i] == false){
            flag = false;
        }

    }

    if(flag){
        cout << minimumLength << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}
