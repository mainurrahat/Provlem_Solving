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
#define lcm(a, b) (a / __gcd(a, b)) * b
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define PI (acos(-1.0)) //(2 * acos(0))
#define SP " "
#define MOD 1000000007
#define mem(a, b) memset(a, b, sizeof(a))
#define dbg(args...)            \
    do                          \
    {                           \
        cerr << #args << " : "; \
        faltu(args);            \
    } while (0)
using namespace std;
////////////////////*/////////////////
dbl torad(dbl deg)
{
    return (deg * PI / 180.0);
}
dbl todeg(dbl rad)
{
    if (rad < 0)
        rad += 2 * PI;
    return ((rad) * (180.0 / PI));
}
dbl fixAngle(dbl A)
{
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}
/*acos,asin ei type er kaj gula korar somoy
angle gula fix korte hoi,,tkn eita use kora lage*/
ll pow(ll n, ll x)
{
    if (x == 0)
        return 1;
    if (!(x & 1))
        return pow(n * n, x >> 1);
    else
        return n * pow(n * n, (x - 1) >> 1);
}
ll mod(ll a, ll b)
{
    return ((a % b) + b) % b;
}
void printBinary(ll num)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
void BiTODec(ll num) // decimal print korbe
{
    int ans = 0, i = 0;
    while (num != 0)
    {
        int last = num % 10;
        num /= 10;
        if (last == 1)
            ans += pow(2, i);
        i++;
    }
    cout << ans << endl;
}
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
void to_int(string s)
{
    int len = s.size();
    ll ans = 0;
    for (int i = 0; i < len; i++)
        ans = ans * 10 + (int)s[i] - '0';
    cout << ans << endl;
}
void to_str(ll x)
{
    stringstream ss;
    ss << x;
    cout << ss.str() << endl;
}
void todec(string s)
{
    cout << stoi(s, 0, 2) << endl;
}
void addBinary(string a, string b)
{
    reverse(a.begin(), a.end()); // Reversing both strings (if you get this, then you got the code very well)
    reverse(b.begin(), b.end());
    if (a.size() > b.size())                      // These two conditions are for making both strings equal sized by adding '0' to smaller string
        for (int i = b.size(); i < a.size(); i++) // We need to add '0' to front so not to affect the sum, that's why we first reversed the string and then pushed back ;)
            b.push_back('0');
    else if (a.size() < b.size())
        for (int i = a.size(); i < b.size(); i++)
            a.push_back('0');
    string res;       // Result string
    char carry = '0'; // Carry
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '1' && b[i] == '1')
        {
            res.push_back(carry);
            carry = '1';
        }
        else if ((a[i] == '1' or b[i] == '1'))
        {
            if (carry == '1')
                res.push_back('0');
            else
                res.push_back('1');
        }
        else
        {
            res.push_back(carry);
            if (carry == '1')
                carry = '0';
        }
    }
    if (carry == '1')
        res.push_back('1');          // if carry is present after looping, add it at the end (remember, we first reversed strings. So everything we need to add to the front, we will push back)
    reverse(res.begin(), res.end()); // Reverse again to get the final string
    cout << res << endl;
}
vector<ll> prime_vec;
const int Lim =10000000 + 20;
int primeCnt[Lim + 1];
void sieve() /// Sieve of Eratosthenes
{
    vector<bool> primes(Lim, true);
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
            prime_vec.pb(i);
            primeCnt[i]++;
        }
    }
}
////////////////////*/////////////////////
/*torad,todeg,fixAngle,pow,
mod,printBinary,BiTODec,
addBinary,IsPrime,todec,
to_str,to_int,sieve*/
vector<int> divsor_list[Lim + 1];
int sum_div[Lim + 1];
void divisors()
{
    for (int i = 1; i <= Lim; i++)
        for (int j = i; j <= Lim; j += i)
        {
            divsor_list[j].push_back(i); // store divisor size= divsor_list.size()
            sum_div[j] += i;             // add to sum of divisors
        }
}
int cntPrime[Lim + 1];
void solve()
{
    int n;
    cin>>n;
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
                cout<<x<<"^2 +"<<y<<"^4   "<<val<<endl;
                cntPrime[val] = 1;
            }
        }
    }

    for (int i = 1; i <= Lim; i++)
    {
        cntPrime[i] += cntPrime[i - 1];
    }

    int t = 1;
    cin>>t;
    while (t--)
        solve();
    // cerr << "Run Time : " << ((double)(clock() - q) / CLOCKS_PER_SEC);
}

