#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
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
int MOD=3;
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
bool prime[1000001];
vi spf(1000001,1e8);
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=0;
    for (ll p=2; p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            spf[p]=p;
            for (ll i=p*p; i<=n; i += p) 
                spf[i]=min(spf[i],p),prime[i] = false; 
        } 
    } 
}
int cnt[1000005];
int BLOCK_SIZE=450;
int z=0;
struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        if (l / BLOCK_SIZE != other.l / BLOCK_SIZE)
            return l < other.l;
    return (l / BLOCK_SIZE & 1) ? (r < other.r) : (r > other.r);
    }
};
int n,a[200005];
vv<ii>factors[200005];
void add(int idx){
    for(auto i:factors[idx]){
        if(cnt[i.ff]%3) z--;
        cnt[i.ff]+=i.ss;
        if(cnt[i.ff]%3) z++;
    }
}
void remove(int idx){
    for(auto i:factors[idx]){
        if(cnt[i.ff]%3) z--;
        cnt[i.ff]-=i.ss;
        if(cnt[i.ff]%3) z++;
    }
}
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
    SieveOfEratosthenes(1000000);
    while(te--){
        int q;
        cin>>n>>q;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++){
            while(a[i]>1){
                int curr=spf[a[i]];
                int c=0;
                while(a[i]%curr==0) a[i]/=curr,c++;
                factors[i].pb({curr,c});
            }
        }
        bool ans[q]={0};
        vv<Query>v;
        for(int i=0;i<q;i++){
            Query x;
            cin>>x.l>>x.r;
            x.l--,x.r--;
            x.idx=i;
            v.pb(x);
        }
        sort(all(v));
        int cur_l=0,cur_r=-1;
        for(Query x:v){
            while(cur_l>x.l){
                cur_l--;
                add(cur_l);
            }
            while(cur_l<x.l){
                remove(cur_l);
                cur_l++;
            }
            while(cur_r>x.r){
                remove(cur_r);
                cur_r--;
            }
            while(cur_r<x.r){
                cur_r++;
                add(cur_r);
            }
            if(z==0) ans[x.idx]=1;
        }
        for(int i=0;i<q;i++) {if(ans[i]) cout<<"Yes\n"; else cout<<"No\n";}
    }
}