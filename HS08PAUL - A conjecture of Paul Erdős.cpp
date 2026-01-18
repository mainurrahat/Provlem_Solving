#include <bits/stdc++.h>
#define dbl double
#define ldbl long double
#define ll long long
#define sz(x) ((int)x.size())
#define vi vector<int>
#define vecin(a, n)             \
    vi a(n);                    \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define print(v)          \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << '\n';
#define sp(n, m) cout << fixed << setprecision(n) << m << endl
#define pb push_back
#define all(a) ((a).begin(), (a).end())
#define rall(a) ((a).rbegin(), (a).rend())
#define LB lower_bound
#define UB upper_bound
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define endl '\n'
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
////////////////////*/////////////////

/*acos,asin ei type er kaj gula korar somoy
angle gula fix korte hoi,,tkn eita use kora lage*/

bool IsPrime(ll n)
{
    if (n == 1)
        return false;
    else
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}
vector<ll> prime_vec;
const int Lim = 1e7 + 20;
int cntPrime[Lim + 1];
void solve()
{
    int n;
    cin >> n;
    cout << cntPrime[n] << endl;
}

int main()
{
    FIO;
    clock_t q = clock();
    int limX = 3200;
    int limY = 60;
    for (int x = 1; x <= limX; x++)
    {
        for (int y = 1; y <= limY; y++)
        {
            int val = (x * x) + (y * y * y * y);
            if (val <= Lim && IsPrime(val))
            {
                //                cout<<x<<"^2 +"<<y<<"^4   "<<val<<endl;
                cntPrime[val] = 1;
            }
        }
    }
    for (int i = 1; i <= Lim; i++)
    {
        cntPrime[i] += cntPrime[i - 1];
    }
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    // cerr << "Run Time : " << ((double)(clock() - q) / CLOCKS_PER_SEC);
}
