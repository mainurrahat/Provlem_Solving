#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> prime_vec;
const int Lim = 1e6;
int primeCnt[Lim + 1];
vector<bool> primes(Lim, true);
void sieve() /// Sieve of Eratosthenes
{
    primes[0] = primes[1] = false;
    for (ll i = 2; i * i <= Lim; i++)
    {
        if (primes[i] == true)
        {
            for (ll j = i * i; j <= Lim; j += i)
                primes[j] = false;
        }
    }
    primeCnt[0] = primeCnt[1] = 0;
    for (ll i = 2; i < Lim; i++)
    {
        primeCnt[i] = primeCnt[i - 1];
        if (primes[i] == true)
        {
            prime_vec.push_back(i);
            primeCnt[i]++;
        }
    }
}
void solve()
{
    //    cout << primeCnt[10]<<endl;;
    //     cout<<prime_vec[20]<<endl;;
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        bool flag = 0;
        for (auto u : prime_vec)
        {
            if (u > n)
                break;
            int a = u;
            int b = n - a;
            if (primes[b])
            {
                cout << n << " = " << a << " + " << b << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "Goldbach's conjecture is wrong." << endl;
    }
}
int main()
{
    //    FIO;
    clock_t q = clock();
    int t = 1;
    sieve();
    //    cin>>t;
    while (t--)
        solve();
    cerr << "Run Time : " << ((double)(clock() - q) / CLOCKS_PER_SEC);
}
