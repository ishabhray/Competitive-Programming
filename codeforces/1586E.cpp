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
int p[MAXN];
int get(int a){
    return p[a]=(p[a]==a)? a:get(p[a]);
}
void uni(int a,int b){
    a=get(a);
    b=get(b);
    p[a]=b;
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
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        vi adj[n+1];
        for(int i=1;i<=n;i++) p[i]=i;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            int x=get(u),y=get(v);
            if(x==y) continue;
            adj[u].pb(v);
            adj[v].pb(u);
            uni(u,v);
        }
        int q;
        cin>>q;
        int cnt[n+1]={0};
        vv<ii>z;
        for(int i=0;i<q;i++){
            int u,v;
            cin>>u>>v;
            cnt[u]++;
            cnt[v]++;
            z.pb({u,v});
        }
        int c=0;
        for(int i=1;i<=n;i++) if(cnt[i]%2) c++;
        if(c){
            cout<<"NO\n"<<c/2<<'\n';
            break;
        }
        cout<<"YES\n";
        for(auto k:z){
            int back[n+1]={0};
            int st=k.ss,e=k.ff;
            back[st]=-1;
            queue<int>q;
            q.push(st);
            while(1){
                int a=q.front();
                q.pop();
                if(a==e) break;
                for(int i:adj[a]){
                    if(!back[i]) back[i]=a,q.push(i);
                }
            }
            vi v;
            while(e!=-1){
                v.pb(e);
                e=back[e];
            }
            cout<<v.size()<<'\n';
            for(int i:v) cout<<i<<' ';
            cout<<'\n';
        }
    }
} 