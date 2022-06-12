#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef pair<int,pair<int,int>> pipii;

vector<int> tree{-1};
vector<int> Q{};

vector<pair<int,int>> maxt(100001,MP(0,-1)); // first value, second index

int treeSize{0};
int q{0};
int parentCounter{0};

int get_right_child(int index)
{
    // node is not null
    // and the result must lie within the number of nodes for a complete binary tree
    if(tree[index]!= -1 && ((2*index)+1)<=treeSize)
        return (2*index)+1;
    // right child doesn't exist
    return 0;
}


int get_left_child(int index)
{
    // node is not null
    // and the result must lie within the number of nodes for a complete binary tree
    if(tree[index]!= -1 && (2*index)<=treeSize)
        return 2*index;
    // left child doesn't exist
    return 0;
}

int get_parent(int index){

    if(index/2 > 0){
        return index/2;
    }
    return 0;

}

int postorder(int index)
{
    // checking for valid index and null node
    if(index>0 && tree[index]!=-1)
    {
        int a,b;
        a = postorder(get_left_child(index)); //visiting left subtree
        b = postorder(get_right_child(index)); //visiting right subtree
        //maxt[index] = max(tree[index],max(maxt[a],maxt[b]));
        int ind,m;
        ind = (maxt[a].first > maxt[b].first) ? (maxt[a].second) : (maxt[b].second);
        m = max(maxt[a].first,maxt[b].first);

        maxt[index].first = max(tree[index],m);
        maxt[index].second = (tree[index] > m) ? index : ind;

        cout << "debug: " << tree[index] << " " << tree[a] << " " << tree[b] << endl;

        if(tree[index] > tree[a] && tree[a] != -1){
            parentCounter++;
            cout << tree[a] << " YES" << endl;
        }
        else{
            cout << tree[a] << " NO" << endl;
        }
        if(tree[index] > tree[b] && tree[b] != -1){
            parentCounter++;
            cout << tree[b] << " YES" << endl;
        }
        else{
            cout << tree[b] << " NO" << endl;
        }


        cout <<  tree[index] << " ";
        return index;
    }
}

void aswap(int a, int b){
    int temp{tree[a]};
    tree[a] = tree[b];
    tree[b] = temp;

    maxt[a].second = a;
    maxt[b].second = b;
    maxt[a].first = tree[a];
    maxt[b].first = tree[b];
}

void recursion(int index){
    if(index > 0){
        int ind,m;
        //ind = (tree[(index/2)*2] > tree[(index/2)*2 + 1]) ? (maxt[(index/2)*2].second) : (maxt[(index/2)*2 + 1].second);
        //m = max(tree[(index/2)*2],tree[(index/2)*2 + 1]);

        //maxt[index].first = max(tree[index],m);
        //maxt[index].second = (tree[index] > m) ? index : ind;


        ind = (tree[get_left_child(index)] > tree[get_right_child(index)]) ? (maxt[get_left_child(index)].second) : (maxt[get_right_child(index)].second);
        m = max(tree[get_left_child(index)],tree[get_right_child(index)]);

        maxt[index].first = max(tree[index],m);
        maxt[index].second = (tree[index] > m) ? index : ind;

        //maxt[get_parent(index)] = max(tree[get_parent(index)],max(tree[get_parent(index)*2],tree[get_parent(index)*2 + 1]));
        recursion(index/2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> treeSize;

    for(int i =0; i < treeSize; i++){
        int t;
        cin >> t;
        tree.PB(t);
        maxt.PB(MP(t,i+1));
    }

    cin >> q;

    for(int i=0; i < q; i++){
        int a;
        cin >> a;
        Q.PB(a);
    }
    postorder(1);

    for(int  i=0; i <= treeSize; i++){
        cout << i << ". th:  " << maxt[i].first << endl;
    }

    //cout << "Parent: " << parentCounter << endl;
    cout << "default" << endl;
    cout << "tree: " << endl;
        for(auto i: tree){
            cout << i << " ";
        }
        cout << endl;

        cout << "max tree" << endl;
        for(int i = 0 ; i < treeSize ; i++){
            cout << maxt[i].first << " ";
        }
    cout << endl;

    for(int i =0; i < q; i++){
        pair<int,int> t{maxt[Q[i]]};
        cout << "tree before swap: " << tree[Q[i]] << " index: " << Q[i] << " " << t.first << " index: " << t.second << endl;
        for(auto i: tree){
            cout << i << " ";
        }
        cout << endl;
        aswap(Q[i],t.second);

        recursion(t.second);
        recursion(Q[i]);

        cout << i << "th round " << endl;
        cout << "tree: " << endl;
        for(auto i: tree){
            cout << i << " ";
        }
        cout << endl;

        cout << "max tree" << endl;
        for(int i = 0 ; i < treeSize ; i++){
            cout << maxt[i].first << " ";
        }
        cout << endl;
        for(int i = 0 ; i < treeSize ; i++){
            cout << maxt[i].second << " ";
        }
        cout << endl;

    }
    parentCounter = 0;
    postorder(1);
    cout << "Parent: " << parentCounter << endl;

    return 0;
}

/*

7
1 4 6 9 2 3 7
3
3 2 1

11
2 1 4 8 11 9 3 5 10 6 7
1
1
*/
