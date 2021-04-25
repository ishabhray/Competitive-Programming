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

void dfs(int i,int vis[],vi adj[],int n,vi &ans)
{
    if(vis[i])
        return;
    vis[i]=1;
    for(auto a:adj[i]){
        if(!vis[a]){
            ans.pb(a);
            dfs(a,vis,adj,n,ans);
        }
    }
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
        int q;
        cin>>q;
        vi adj[100000];
        vv<ii >v;
        int cnt=0;
        for(int i=0;i<q;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(a==1){
                v.pb({b,c});
                for(int j=0;j<cnt;j++){
                    if(b<v[j].ff&&v[j].ff<c||b<v[j].ss&&v[j].ss<c)
                        adj[j].pb(cnt);
                    if(v[j].ff<b&&b<v[j].ss||v[j].ff<c&&c<v[j].ss)
                        adj[cnt].pb(j);
                }
                cnt++;
            }
            else{
                int vis[100000]={0};
                vi ans;
                dfs(b-1,vis,adj,cnt,ans);
                bool b=false;
                for(auto a:ans)
                    if(a==c-1)
                        b=true;
                if(b)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
        }
    }
}