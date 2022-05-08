#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef pair<int,pair<int,int>> pipii;

vector<int> graph[100001];

vector<bool> visited(100001,false);
vector<bool> color(100001,false);

/*
    Az adó tornyok száma
*/
int counter{0};

int BFS(int source){
    /*
        A program elve, hogy csinál egy BFS-t pepitában, minden lépésben más "szinû" az adott él, hiszen ha az út akkor lefedett
        ha az egyiken van adótorony és a másikon nem, ezzel kis is tudjuk küszöbölni a nem lehetséges gráfokat, mivel ha már abban az élben volt
        és más színe lesz akkor nem lehet kirakni, mivel mi minden lépésben szabályosan jártunk el, mert felváltva megyünk. Nem számít, hogy
        melyik színû lesz az adó torony, mive számon tartjuk a színezettek számát és megnézzük hogy melyikbõl van több.
    */

    int all_counter{1},color_counter{1};

    queue<int> q;

    q.push(source);
    visited[source] = true;
    color[source] = true;

    while(!q.empty()){
        int parent = q.front();
        q.pop();
        //cout << "Parent: " << parent << "Children: ";
        for(auto node: graph[parent]){

            if(!visited[node]){
                q.push(node);
                visited[node] = true;
                /*
                    A színek boolean ként kezeljük, így hogy átszínezzük csak negáljuk az adott szülõ színét
                */
                color[node] = !color[parent];

                /*
                    Számon tartjuk az összes élek számát a gráfban, mivel lehet hogy több kisebb gráfunk lesz, így nem számolhatunk N-el
                */
                all_counter++;

                if(color[node] == true){
                    color_counter++;
                }

                // cout << "node: " << node << " color: " << color[node] << endl;
            }

            else{
                /*
                    Ha már voltunk abban a csúcsban, és ha most más színt kapunk, akkor nem lehet úgy elhelyezni az adótornyokat, hogy jó legyen
                */

                /*
                    DEBUG
                */
                //cout << "node: " << node << " color: " << color[node] << endl;
                //cout << "parent: " << parent << " color: " << color[parent] << endl;
                if(color[parent] == color[node]){
                    return -1;
                }
            }

        }

    }

    /*
        A pepita két szine közül visszahozzuk a nagyobbat
    */
    return max(color_counter, all_counter - color_counter);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;

    cin >> N >> M;


    for(int i =0; i < M; i++){
        int honnan,hova;
        cin >> honnan >> hova;
        //cout << honnan << hova << endl;
        graph[honnan].PB(hova);
        graph[hova].PB(honnan);

    }

    /*
        DEBUG
    */
    /*
    for(int i =0; i < 5; i++){
        cout << i << " : ";
        for(auto n: graph[i]){
            cout << n << " ";
        }
        cout << endl;
    }
    */
    for(int i =1; i <= N; i ++){
        int ans;
        /*
            Minden csúcsból, amelybe még nem ért el a BFS, indítunk egy BFS-t, mivel lehet hogy több kis szigetünk lesz
        */
        if(!visited[i]){
            ans = BFS(i);
            //cout << "ans: " << ans << endl;
            /*
                Ha -1-et kapunk vissza, akkor nem lehet kirakni
            */
            if(ans == -1){
                // nem lehet kmirakni
                counter = -1;
                break;
            }
            else{
                counter += ans;
            }
        }
    }
    /*
    cout << "colors: ";
    for(int i =0; i <= N;i++){
        cout << i << " : " << color[i] << endl;
    }
    */

    cout << counter << endl;

    return 0;
}
