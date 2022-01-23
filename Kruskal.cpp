#include <bits/stdc++.h>

using namespace std;

int vertices;
int edges;
int parent[1000];
int Noderank[1000];
typedef pair<int, pair<int, int>> pipii;

//DSU IMPLEMENTATION ///////
void make_set(int v) {
    parent[v] = v;
    Noderank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}


bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (Noderank[a] < Noderank[b]){
            swap(a, b);
        }
        parent[b] = a;
        if (Noderank[a] == Noderank[b]){
            Noderank[a]++;
        }
        return true;
    }
    return false;
}
////////


int main(){

    cin>>vertices;
    priority_queue <pipii, vector<pipii>, greater<pipii> > pq;
    //initilization of the vertices
    for(int i =0; i < vertices; i++){
        make_set(i);
    }
    //Read in data
    for (int i=0; i<n; i++){
        int honnan, hova,suly;
        cin>>honnan>>hova>>suly;
        // pushes the edge to the priority queue
        pq.push(make_pair(suly, make_pair(honnan-1, hova-1)));
    }
    while(!pq.empty()){
        pipii edge=pq.top();
        pq.pop();
        // if a union can be made, then
        if (union_sets(edge.second.first, edge.second.second)){
            // Prints out the edges of the minimum spanning tree
            cout <<edge.second.first<<" "<<edge.second.second<<endl;
        }
    }
    return 0;
}
