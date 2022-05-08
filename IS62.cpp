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
    Az ad� tornyok sz�ma
*/
int counter{0};

int BFS(int source){
    /*
        A program elve, hogy csin�l egy BFS-t pepit�ban, minden l�p�sben m�s "szin�" az adott �l, hiszen ha az �t akkor lefedett
        ha az egyiken van ad�torony �s a m�sikon nem, ezzel kis is tudjuk k�sz�b�lni a nem lehets�ges gr�fokat, mivel ha m�r abban az �lben volt
        �s m�s sz�ne lesz akkor nem lehet kirakni, mivel mi minden l�p�sben szab�lyosan j�rtunk el, mert felv�ltva megy�nk. Nem sz�m�t, hogy
        melyik sz�n� lesz az ad� torony, mive sz�mon tartjuk a sz�nezettek sz�m�t �s megn�zz�k hogy melyikb�l van t�bb.
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
                    A sz�nek boolean k�nt kezelj�k, �gy hogy �tsz�nezz�k csak neg�ljuk az adott sz�l� sz�n�t
                */
                color[node] = !color[parent];

                /*
                    Sz�mon tartjuk az �sszes �lek sz�m�t a gr�fban, mivel lehet hogy t�bb kisebb gr�funk lesz, �gy nem sz�molhatunk N-el
                */
                all_counter++;

                if(color[node] == true){
                    color_counter++;
                }

                // cout << "node: " << node << " color: " << color[node] << endl;
            }

            else{
                /*
                    Ha m�r voltunk abban a cs�csban, �s ha most m�s sz�nt kapunk, akkor nem lehet �gy elhelyezni az ad�tornyokat, hogy j� legyen
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
        A pepita k�t szine k�z�l visszahozzuk a nagyobbat
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
            Minden cs�csb�l, amelybe m�g nem �rt el a BFS, ind�tunk egy BFS-t, mivel lehet hogy t�bb kis sziget�nk lesz
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
