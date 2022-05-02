#include <bits/stdc++.h>

using namespace std;

vector<int> g[100001];
vector<bool> visited(100001,false);

int counter{0};


int BFS(int source){

    queue<int> q;
    q.push(source);

    vector<bool> color(100001,false);
    visited[source] = true;
    int gsize = 1;
    int m_counter = 1;
    color[source] = true;
    while(!q.empty()){
        int node = q.front();

        for(auto child:g[node]){
            if(!visited[child]){
                gsize++;
                visited[child] = true;
                color[child] = !color[node];
                if(color[child] == true){
                    m_counter++;
                }

            }
            else{
                if(color[child] == color[node]){
                    return -1;
                }

            }

        }

    }
    return max(m_counter, g_size - m_counter);


}

int main()
{
    int N,M;

    cin >> N >> M;

    for(int i =0; i < M; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);

    }

    bool flag{true};

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            int x =BFS(i);
            if(x == -1){
                flag = false;
                break;
            }
            else{
                counter += x;
            }

        }
    }

    if(flag){
        cout << counter << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}
