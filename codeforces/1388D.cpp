#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
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
bool prime[1000001];
vi primes;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for(int p=2;p<1000001;p++)
        if(prime[p])
            primes.pb(p);
}

vi adj[200001];
int vis[200001]={0};
vi s;

void topo(int i)
{
    if(vis[i])
        return;
    vis[i]=1;
    for(auto a:adj[i]){
        if(vis[a])
            continue;
        topo(a);
    }
    s.pb(i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	//cin>>t;
	//SieveOfEratosthenes(1000000);
    while(t--){
        int n;
        cin>>n;
        ll a[n+1];
        int b[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i+1];
        for(int i=0;i<n;i++)
            cin>>b[i+1];
        s.clear();
        for(int i=1;i<=n;i++){
            adj[i].clear();
            vis[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(b[i]==-1)
                continue;
            adj[i].pb(b[i]);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i])
            topo(i);
        }
        vi v,ans;
        ll c=0;
        while(!s.empty()){
            if(a[s.back()]<0)
                v.pb(s.back());
            else{
                ans.pb(s.back());
                c+=a[s.back()];
                if(b[s.back()!=-1])
                    a[b[s.back()]]+=a[s.back()];
            }
            s.pop_back();
        }
        while(!v.empty()){
            ans.pb(v.back());
            c+=a[v.back()];
            v.pop_back();
        }
        cout<<c<<'\n';
        for(int i:ans)
            cout<<i<<' ';
    }
}