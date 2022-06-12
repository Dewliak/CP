#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back


const long long INF = 1e9;

long long L(long long n);
long long L1(long long n);
long long R1(long long n);
long long e(long long n);
long long R2(long long n);

vector<long long> q(1000,-1);
vector<long long> l1(1000,-1);
vector<long long> r1(1000,-1);

int counter{0};

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// A simple method to evaluate Euler Totient Function
long long EulerPhi(long long n)
{
    long long result = 1;
    for (long long i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}



long long L(long long n){
    //cout << "L: " << n << endl;
    if(n == 0){
        return 0;
    }

    long long a;
    if(n >= 0){
        if(l1[n] != -1){
            a = l1[n];
        }
        else{
            a = L1(n);
            l1[n] = a;
            counter++;
        }
    }
    else{
        a = 0;
    }

    long long b;
    if((n-1) >= 0){
        if(q[n-1] != -1){
            //cout << "already have: " << q[n-1] <<   endl;
            b = q[n-1];
        }
        else{
            //cout << "new" << endl;
            b = L(n-1);
            q[n-1] = b;
            counter++;
        }
    }
    else{
        b = 0;
    }

    //cout << "QQ: " << q[n-1] << endl;

    long long c;
    if(n >= 0){
        if(r1[n] != -1){
            c = r1[n];
        }
        else{
            c = R1(n);
            r1[n] = c;
        }
    }
    else{
        c = 0;
    }

    return 2*a - b + c;
}

long long L1(long long n ){
    //cout << "L1: " << n << endl;
    if(n <= 1){
        return 0;
    }

     long long a;
    if((n-1) >= 0){
        if(l1[n-1] != -1){
            a = l1[n-1];
        }
        else{
            a = L1(n-1);
            l1[n-1] = a;
            counter++;
        }
    }
    else{
        a = 0;
    }

    long long b;
    if((n-1) >= 0){
        if(q[n-1] != -1){
            b = q[n-1];
        }
        else{
            b = L(n-1);
            q[n-1] = b;
            counter++;
        }
    }
    else{
        b = 0;
    }


    return 2*b - a + R2(n);
}

long long R1(long long n){
    //cout << "R1: " << n << endl;
    if(n == 1){
        return 0;
    }
    return R1(n-1) + 4*(EulerPhi(n-1) - e(n));
}

long long e(long long n){
    if(n % 2 == 0){
        return 0;
    }
    else{
        return EulerPhi((n-1)/2);
    }
}

long long R2(long long n){
    if(n % 2 == 0){
        return (n-1)*EulerPhi(n-1);
    }
    else{
        if(n % 4 == 1){
            return (n-1)*EulerPhi((n-1))/2;
        }
        else{
            return 0;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    q[0] = 0;
    l1[0] = 0;
    l1[1] = 0;
    r1[1] = 0;
    r1[0] = 0;

    int x{1000};
    //cout << L(20) << endl;
    for(int i = 2; i < 1001; i++){
        long long a{L(i)};
        //cout << "lists: " << q[i] << " " << l1[i] << " " << r1[i] << endl;
        cout << i << "th: " << a << endl;
        if(i == x){
            cout << a << endl;
        }



    }
    cout << "counter: " << counter << endl;
    return 0;
}
