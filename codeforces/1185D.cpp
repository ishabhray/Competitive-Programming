#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
#define all(v) (v).begin(),(v).end()
#define MAXN 300005
int MOD=1e9+7;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll n;
        cin >> n;
        vector <pair<ll, ll>> v(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i].ff;
            v[i].ss = i;
        }
        sort(all(v));
        set <ll> cur;
        map <ll, ll> freq;
        if (n == 2) {
            cout << "1\n";
            return 0;
        }
        for (ll i = 1; i < n; i++) {
            cur.insert(v[i].ff - v[i - 1].ff);
            freq[v[i].ff - v[i - 1].ff]++;
        }
        for (ll i = 0; i < n; i++) {
            ll x;
            if (i) {
                x = v[i].ff - v[i - 1].ff;
                freq[x]--;
                if (freq[x] == 0)
                    cur.erase(x);
            }
            if (i + 1 < n) {
                x = v[i + 1].ff - v[i].ff;
                freq[x]--;
                if (freq[x] == 0)
                    cur.erase(x);
            }
            if (i && i + 1 < n) {
                x = v[i + 1].ff - v[i - 1].ff;
                freq[x]++;
                if (freq[x] == 1)
                    cur.insert(x);
            }
            if (cur.size() == 1) {
                cout << v[i].ss + 1 << "\n";
                return 0;
            }
            if (i) {
                x = v[i].ff - v[i - 1].ff;
                freq[x]++;
                if (freq[x] == 1)
                    cur.insert(x);
            }
            if (i + 1 < n) {
                x = v[i + 1].ff - v[i].ff;
                freq[x]++;
                if (freq[x] == 1)
                    cur.insert(x);
            }
            if (i && i + 1 < n) {
                x = v[i + 1].ff - v[i - 1].ff;
                freq[x]--;
                if (freq[x] == 0)
                    cur.erase(x);
            }
        }
        cout << "-1\n";
    }
}