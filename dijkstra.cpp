#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <long long,int> pp;
const long long int MAXN=1e18+10;

int n,m;
struct el
{
    int meddig,suly;
};
vector <el> g[100010];

void beolvas()
{
    //scanf("%d%d",&n,&m);
    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        int mettol,meddig,suly;
        cin >> mettol >> meddig >> suly;
        //scanf("%d%d%d",&mettol,&meddig,&suly);
        g[mettol].push_back(el{meddig,suly});
        g[meddig].push_back(el{mettol,suly});
    }
}

int main ()
{
    beolvas();
    vector <int> szulo(n+1,0);
    vector <long long> tav(n+1,MAXN);
    priority_queue <pp,vector <pp>,greater <pp>> pq;
    //start dummy
    pq.push(make_pair(0,1));
    szulo[1]=1;
    tav[1]=0;
    while (!pq.empty())
    {
        pp p=pq.top();
        pq.pop();
        if (p.first>tav[p.second])continue;
        for (int i=0; i<g[p.second].size(); i++)
        {
            if (tav[g[p.second][i].meddig]>tav[p.second]+g[p.second][i].suly)
            {
                tav[g[p.second][i].meddig]=tav[p.second]+g[p.second][i].suly;
                szulo[g[p.second][i].meddig]=p.second;
                pq.push(make_pair(tav[p.second]+g[p.second][i].suly,g[p.second][i].meddig));
            }
        }
    }
    if (tav[n]==MAXN) {cout<<-1<<endl;}
    else{
        vector <int> ans;
        while (n!=1)
        {
            ans.push_back(n)
;
            n=szulo[n];
        }
        ans.push_back(1);
        for (int i=ans.size()-1; i>=0; i--)
        {
            printf("%d ",ans[i]);
        }
    }
    return 0;
}
