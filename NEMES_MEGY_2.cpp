#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define MP make_pair
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 1e9;


bitset<44> higher_num(bitset<44> bs){
    int k = 0;
    int counter = 0;
    for (int i = 0; i < bs.size()-1; i++){
        if(bs[i] == 1 && bs[i+1] == 0){
            bs[i] = 0;
            bs[i+1] = 1;
            counter = i;
            break;
        }
        if(bs[i] == 1){
            k++;
        }

    }
    cout << "counter:"  << counter << " k:" << k << endl;
    for(int i =0; i < counter; i++){
        if(k > 0){
            bs[i] = 1;
            k--;
        }
        else{
            bs[i] = 0;
        }
    }

    return bs;

}


bitset<44> lower_num(bitset<44> bs){
    for (int i = 0; i < bs.size()-1; i++){
        if(bs[i] == 0 && bs[i+1] == 1){
            bs[i] = 1;
            bs[i+1] = 0;
            return bs;
        }
    }
}

void bitset_to_long(bitset<44> bs){
    long long num{0};

    for(int i =0; i < bs.size();i++)
        num += bs[i]*pow(2,i);

    cout << num << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N;

    cin >> N;

    bitset<44> bitset1(N);
    cout << bitset1 << endl;
    cout << bitset1[2] << endl;
    cout << "LOWER: " << lower_num(bitset1) << endl;
    cout << "HIGHER: " << higher_num(bitset1) << endl;
    bitset_to_long(lower_num(bitset1));
    bitset_to_long(higher_num(bitset1));
    return 0;
}
