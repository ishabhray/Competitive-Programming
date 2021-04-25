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
        int n;
        cin>>n;
        ll a[n];
        set<ll>s;
        map<ll,ll>m;
        ll mx=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s.insert(a[i]);
            mx=max(mx,a[i]);
        }
        cout<<mx<<'\n';
        for(ll i=1;i<=1e4;i++){
            for(ll j=1;i*i*i+j*j*j<=mx;j++){
                if(s.find(i*i*i+j*j*j)!=s.end())
                    m[i*i*i+j*j*j]++;
            }
        }
        for(int i=0;i<n;i++){
            if(m[a[i]])
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}