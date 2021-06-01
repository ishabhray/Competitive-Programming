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

bool check(int x,unordered_set<int>adj[]){
    vi v;
    v.pb(x);
    for(int i:adj[x])
        v.pb(i);
    bool b=true;
    for(int i:v){
        for(int j:v){
            if(i==j)
                continue;
            if(adj[i].find(j)==adj[i].end()){
                b=false;
                break;
            }
        }
        if(!b)
            break;
    }
    if(b){
        cout<<"2\n";
        cout<<x+1<<' ';
        for(int i:adj[x])
            cout<<i+1<<' ';
        cout<<'\n';
    }
    return b;
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m,k;
        cin>>n>>m>>k;
        int deg[n]={0};
        set<ii>s;
        unordered_set<int>adj[100005];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].insert(v);
            adj[v].insert(u);
            deg[u]++;
            deg[v]++;
        }
        if(k>(1+sqrt(1+8*m))/2){
            cout<<-1<<'\n';
            continue;
        }
        for(int i=0;i<n;i++){
            s.insert({deg[i],i});
        }
        bool clique=false;
        while(!clique&&!s.empty()){
            // cout<<s.begin()->ff<<' '<<s.begin()->ss<<'\n';
            if(s.begin()->ff<k-1){
                int x=s.begin()->ss;
                s.erase(s.begin());
                for(int i:adj[x]){
                    adj[i].erase(x);
                    s.erase({deg[i],i});
                    deg[i]--;
                    s.insert({deg[i],i});
                }
                continue;
            }
            else if(s.begin()->ff==k-1){
                clique=check(s.begin()->ss,adj);
                int x=s.begin()->ss;
                s.erase(s.begin());
                for(int i:adj[x]){
                    adj[i].erase(x);
                    s.erase({deg[i],i});
                    deg[i]--;
                    s.insert({deg[i],i});
                }
            }
            else break;
        }
        if(!clique&&s.empty()){
            cout<<"-1\n";
        }
        else if(!clique&&!s.empty()){
            cout<<1<<' '<<s.size()<<'\n';
            for(auto i:s)
                cout<<i.ss+1<<' ';
            cout<<'\n';
        }
    }
}