#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <long long,pair<int, int>> pipii;
const long long int MAXN=1e18+10;

int n,m;
struct el
{
    int meddig,suly;
};
vector <el> g[100010];

void beolvas()
{
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; i++)
    {
        int mettol,meddig,suly;
        scanf("%d%d%d",&mettol,&meddig,&suly);
        g[mettol].push_back(el{meddig,suly});
        g[meddig].push_back(el{mettol,suly});
    }
}

int main ()
{
    beolvas();
    priority_queue <   pipii,vector <pipii>,greater <pipii>    > pq;
    bool intree[10000];
    pq.push(make_pair(0,1,1));

    while (!pq.empty())
    {
        pair<long long, pair<int, int>> p=pq.top();
        pq.pop();

        if (intree[p.second.second]){
            continue;
        }

        intree[p.second.second] = true;

        if (!(p.second.first == 1 && p.second.second == 1)){
            cout<<p.second.first<<" "<<p.second.second<<endl;
        }

        for (int i=0; i<g[p.second.second].size(); i++)
        {
            if (!intree[g[p.second.second][i].meddig])
            {
                pq.push(make_pair(g[p.second.second][i].suly,make_pair(p.second.second, g[p.second.second][i].meddig)));
            }
        }
    }

    return 0;
}
