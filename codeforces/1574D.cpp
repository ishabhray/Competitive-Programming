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
vv<vi>a;
set<vi>ban;
vi ans;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        cin>>n;
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            vi v(c);
            for(int &j:v) cin>>j;
            a.pb(v);
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            vi v(n);
            for(int &j:v) cin>>j;
            ban.insert(v);
        }
        vi v(n);
        for(int i=0;i<n;i++){
            for(int j=a[i].size()-1;j>0;j--){
                a[i][j]-=a[i][j-1];
            }
        }
        set<pair<ll,vi>>q;
        for(int i=0;i<n;i++) v[i]=a[i].size();
        q.insert({0,v});
        do{
            auto x=*q.begin();
            q.erase(q.begin());
            if(!ban.count(x.ss)){
                ans=x.ss;
                break;
            }
            v=x.ss;
            for(int i=0;i<n;i++){
                if(v[i]>1){
                    v[i]--;
                    q.insert({x.ff+a[i][v[i]],v});
                    v[i]++;
                }
            }
        }while(1);
        for(int i:ans) cout<<i<<' ';
        cout<<'\n';
    }
}
