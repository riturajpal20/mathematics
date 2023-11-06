#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<int> os; os.find_by_order(k)): kth element in os, os.order_of_key(k): no of items strictly less than k
// using namespace std;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// // oset<int> os; os.find_by_order(k)): kth element in os, os.order_of_key(k): no of items strictly less than k
#define ll long long int
#define vii vector<pair<ll, ll>>
#define ff(i, a, b) for (ll i = a; i < b; ++i)
#define fr(i, a, b) for (ll i = a; i >= b; --i)
#define vs vector<string>
#define vec vector<ll>
#define mpll map<ll, ll>
#define mpcl map<char, ll>
#define mpsl map<string, ll>
#define pb push_back
#define vvi vector<vector<ll>>
#define bs(v, a) binary_search(v.begin(), v.end(), a)
// #define endl
typedef pair<int, int> pi;

#define srtv(v, n) sort(v.begin(), v.end())
#define isortarry(arr, n) sort(arr, arr + n)
#define dsortarry(arr, n) sort(arr, arr + n, greater<int>())
#define mod 1000000007

ll f(vector<ll> &arr, ll ind, ll k, vector<ll> &dp)
{
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    ll maxi = INT_MAX;
    ff(i, 1, k + 1)
    {
        if (ind - i >= 0)
        {
            ll j = f(arr, ind - i, k, dp) + abs(arr[ind] - arr[ind - i]);
            maxi = min(maxi, j);
        }
    }
    return dp[ind] = maxi;
}
// get total set bit
ll getsetbit(ll num)
{
    return __builtin_popcount(num);
}
// check whether it is possible to place cow at min distance of mid or not
bool check(int x, vec &v, ll n, ll k)
{
    ll cnt = 1;
    ll co = v[0];
    ff(i, 1, n)
    {
        if (v[i] - co >= x)
        {
            cnt++;
            co = v[i];
        }
        if (cnt == k)
        {
            return true;
        }
    }
    return false;
}
/*************FIND GCD OF TWO NUMBERS*************/
ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(a, b % a);
    }
}
/*************FIND LCM OF TWO NUMBERS*************/
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
// extended euclid
ll egcd(int a, int b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    };
    ll x1, y1;
    ll d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
/*************POWER OF A TO B*************/
ll ul = 1e9 + 7;
ll power(ll a, ll b)
{
    ll ans = 1;
    while (b != 0)
    {
        if (b & 1)
        {
            b--;
            ans = (ans * a) % ul;
        }
        else
        {
            a = (a * a) % ul;
            b = (b / 2) % ul;
        }
    }
    return ans % ul;
}

/*************FIND NUMBER OF DIGIT IN A*************/
ll digits(ll n)
{
    ll k = 0;

    ll q = n;
    while (q > 0)
    {
        q = q / 10;
        k++;
    }
    return k;
}
bool prime(ll n)
{
    if (n == 1 || n == 0)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    ff(i, 2, sqrt(n) + 1)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void factor(ll p, vector<ll> &ans)
{

    for (int i = 2; i * 1ll * i <= p; ++i)
    {
        if (p % i == 0)
        {
            ans.pb(i);
            if (i != p / i)
            {
                ans.pb(p / i);
            }
        }
    }
}

/*************YOUR CODE GOES HERE*************/
// const int N = (int)1e5 + 5;
// int a[N], b[N];
// ll xxx = 1e9;
// string s;
// vec parent(1e5 + 1)
// bfson grid
void bfsg(vector<vector<char>> &v, ll row, ll col, vector<vector<ll>> &vis, ll n, ll m)
{
    queue<pair<ll, ll>> q;
    q.push({row, col});
    vis[row][col] = 1;
    ll delr[4] = {-1, 0, 1, 0};
    ll delc[4] = {0, 1, 0, -1};
    while (!q.empty())
    {
        pair<ll, ll> p = q.front();
        q.pop();
        ll x = p.first;
        ll y = p.second;
        ff(i, 0, 4)
        {
            ll newr = x + delr[i];
            ll newc = y + delc[i];
            if (newr > 0 && newc > 0 && m > newc && n > newr && vis[newr][newc] == 0)
            {
                q.push({newr, newc});
            }
        }
    }
}
map<ll, ll> parent;
void bfs(ll root, vector<ll> adj[])
{
    queue<pair<ll, ll>> q;
    q.push({root, -1});
    ll height = 0;
    ll maxi = INT_MIN;
    // parent[root] = -1;
    while (!q.empty())
    {

        ll sz = q.size();

        // maxi = max(maxi, sz);

        ll node = q.front().first;
        ll par = q.front().second;
        q.pop();
        parent[node] = par;

        for (auto it : adj[node])
        {
            if (it == par)
            {
                continue;
            }
            q.push({it, node});
        }
    }
}

// factorial function
ll fact(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
// ll mod = 1e9 + 7;

// ll n;
// map<ll, vector<ll>> mp;
// ll ti = 0;
// // vec d;
// map<ll, ll> m;
// vector<ll> d(1e5 + 1);
// ll res = 0;
// ll N = 2e5 + 1;
// vector<ll> path(N, 0);
// ll c = 0;
// // ll N = 2e5 + 1;
// // vector<ll> path(N, 0);
// ll sums = 0;
// // can i use dp ??
// // but how??
// map<ll, ll> mp;
// ll idx = 0;
// vec flat;
// // ll n;
// // vec level(20);
// vec ln;
// vec vis(n + 1, 0);

ll d = 1;

void dfs(ll node, vector<ll> adj[], vec &vis, ll color)
{
    vis[node] = color;

    for (auto it : adj[node])
    {

        if (!vis[it])
        {
            dfs(it, adj, vis, 3 - color);
        }
        else if (vis[it] == vis[node])
        {
            d = 0;
        }

        // dfs(it, node, adj);
    }
}
void shortestPath(ll src, ll V, vector<pair<ll, ll>> adj[], vec &dist)
{

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {

        ll node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {

            ll nnode = it.first;
            ll nweight = it.second;
            if (dist[nnode] > dist[node] + nweight)
            {
                dist[nnode] = dist[node] + nweight;
                pq.push({dist[nnode], nnode});
            }
        }
    }
}
ll mods = 1000000007;

// all prime factor of a number
const ll N1 = 1e6 + 3;
vec allfs;
// ll spf[N1 + 1];
vec spf(1e7 + 3);
// set<ll> st;
void allf(ll n, set<ll> &ans)
{
    // ll spf[N1 + 1];
    ff(i, 2, N1 + 1)
    {
        spf[i] = i;
    }
    for (ll i = 2; i * i <= N1; i++)
    {
        if (spf[i] != i)
        {
            continue;
        }

        for (ll j = i * i; j <= N1; j += i)
        {

            if (spf[j] == j)
            {
                spf[j] = i;
            }
        }
    }
    while (n != 1)
    {
        // vec allfs;

        ans.insert(spf[n]);
        n = n / spf[n];
        // allfs.pb(spf[n]);
        // n = n / spf[n];
    }
}
// find all prime upto number n
vec allp;
ll N2 = 1e6 + 6;
void sieve()
{

    // bool prime[N2 + 1];
    vector<bool> prime(N2 + 1, 1);
    // memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= N2; p++)
    {

        if (prime[p] == true)
        {

            for (ll i = p * p; i <= N2; i += p)
            {
                prime[i] = false;
            }
        }
    }

    for (ll p = 2; p <= N2; p++)
    {
        if (prime[p])
        {
            allp.pb(p);
        }
    }
}
// comperator function

bool cmp(const pair<ll, ll> &p1, const pair<ll, ll> &p2)
{
    if (p1.first > p2.first)
    {
        return true;
    }
    else if (p1.first == p2.first && p1.second < p2.second)
    {
        return true;
    }
    return false;
}
void dp_on_tree(ll node, vector<ll> adj[], vector<ll> &dp, ll par)
{
    dp[node] = node;
    for (auto it : adj[node])
    {
        if (it == par)
        {
            continue;
        }
        dp_on_tree(it, adj, dp, node);
        dp[node] += dp[it];
    }
}
// ll sum = 0;

// ll mod = 109 + 7;
void binarylifting(ll node, ll par, vector<ll> adj[], vector<vector<ll>> &dp, vec &level, ll l = 0)
{
    dp[node][0] = par;
    ff(i, 1, 17)
    {

        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    level[node] = l;
    // dfs
    for (auto it : adj[node])
    {
        if (it == par)
        {
            continue;
        }
        binarylifting(it, node, adj, dp, level, l + 1);
    }
}

ll kthparent(ll k, ll node, vector<vector<ll>> &dp)
{
    ll cnt = 0;
    while (k)
    {
        if (k & 1)
        {
            node = dp[node][cnt];
        }
        k = k >> 1;
        cnt++;
    }
    return node;
}

vec level(2e5 + 1);

void getl(ll node, ll par, vec adj[], ll l = 0)
{
    level[node] = l;
    for (auto it : adj[node])
    {
        if (it == par)
        {
            continue;
        }
        getl(it, node, adj, l + 1);
    }
}

// set<ll> st;
// bool frs(ll n)
// {
//     ll f = 0;
//     if (n % 2 == 0)
//     {
//         if (st.find(2) != st.end())
//         {
//             return true;
//         }
//         else
//         {
//             st.insert(2);
//         }
//         // st.insert(2);
//         n = n / 2;
//     }

//     while (n % 2 == 0)
//     {
//         n /= 2;
//     }

//     for (ll i = 3; i <= sqrt(n); i = i + 2)
//     {

//         if (st.find(i) != st.end())
//         {
//             return 1;
//         }
//         else
//         {
//             st.insert(i);
//         }
//         n = n / i;

//         while (n % i == 0)
//         {
//             n /= i;
//         }
//     }

//     if (n > 2)
//     {
//         if (st.find(n) != st.end())
//         {
//             return true;
//         }
//         else
//         {
//             st.insert(n);
//         }
//     }
//     return false;
// }
bool machine(ll mid, vec &v, ll t)
{
    ll sum = 0;
    ff(i, 0, v.size())
    {
        sum += min(mid / v[i], (ll)1e9);
    }
    return sum >= t;
}
bool checks(ll tot, ll n, vec &v, ll k)
{
    ll temp = 0, cnt = 1;
    for (ll i = 0; i < n; ++i)
    {
        if (v[i] > tot)
            return false;
        if (v[i] + temp <= tot)
            temp += v[i];
        else
        {
            temp = v[i];
            cnt++;
        }
    }

    return cnt <= k;
}
ll p = 1e6 + 5;
vec r(p, 0);
void solve()
{

    // oset<pair<ll, ll>> st;

    // ll n, k;
    // cin >> n >> k;
    // vec v(n);
    // ff(i, 0, n)
    // {
    //     cin >> v[i];
    // }

    // ff(i, 0, k)
    // {
    //     st.insert({v[i], i});
    // }
    // ll d = 0;
    // ll mid = (k + 1) / 2 - 1;
    // pair<ll, ll> pt = *(st.find_by_order(mid));
    // ll res = pt.first;

    // ff(i, 0, k)
    // {
    //     d += abs(v[i] - res);
    // }
    // cout << d << " ";

    // ff(i, 0, n - k)
    // {
    //     st.erase(st.find_by_order(st.order_of_key({v[i], i})));
    //     st.insert({v[i + k], i + k});
    //     pair<ll, ll> pr = *st.find_by_order((k + 1) / 2 - 1);
    //     ll p = pr.first;
    //     d += abs(p - v[i + k]) - abs(res - v[i]);
    //     if (!(k & 1))
    //         d -= p - res;
    //     res = p;
    //     cout << d << " ";
    // }
    ll n;
    cin >> n;
    vec v(n);
    map<ll, ll> mp;
    vec cnt(1e6 + 5, 0);
    ff(i, 0, n)
    {
        cin >> v[i];
        // set<ll> st;
        // allf(v[i], st);
        // // mp[allfs[allfs.size() - 1]]++;
        // // ff(i, 0, allfs.size())
        // // {
        // //     mp[allfs[i]]++;
        // // }
        // for (auto it : st)
        // {
        //     mp[it]++;
        // }
        cnt[v[i]]++;
    }
    // ll ans = 0;
    ll maxi = INT_MIN;
    for (ll i = 1e6 + 5; i >= 1; i--)
    {
        ll f = 0;
        ll ans = 0;
        for (ll j = i; j <= 1e6 + 5; j += i)
        {
            ans += cnt[j];
            if (ans >= 2)
            {
                f = 1;
                cout << i;
                break;
                // maxi = max(maxi, i);
            }
        }
        if (f)
        {
            break;
        }
    }
}

/*************YOUR CODE GOES HERE*************/
int main()
{
    // ll t;
    // cin >> t;
    // for (ll i = 1; i < p; i++)
    // {
    //     for (ll j = i; j < p; j += i)
    //     {
    //         r[j]++;
    //     }
    // }

    // while (t--)
    // {
    //     // ll p = 1e6 + 5;
    //     // vec r(p, 0);
    //     // for (ll i = 1; i < p; i++)
    //     // {
    //     //     for (ll j = i; j < p; j += i)
    //     //     {
    //     //         r[j]++;
    //     //     }
    //     // }
    //     solve();
    // }
    solve();

    return 0;
}
