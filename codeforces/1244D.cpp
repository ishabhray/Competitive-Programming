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
        vi adj[n+1];
        ll cost[4][n+1];
        for(int i=1;i<=3;i++){
            for(int j=1;j<=n;j++){
                cin>>cost[i][j];
            }
        }
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        bool f=true;
        int j;
        for(int i=1;i<=n;i++){
            if(adj[i].size()>2){
                f=false;
                break;
            }
            if(adj[i].size()==1)
                j=i;
        }
        if(!f){
            cout<<-1;
            return 0;
        }
        vi v;
        int vis[n+1]={0};
        int cnt=0;
        while(cnt<n){
            v.pb(j);
            vis[j]=1;
            cnt++;
            if(vis[adj[j][0]])
                j=adj[j][1];
            else
                j=adj[j][0];
        }

        vi arr={1,2,3};
        ll ans=1e18;
        vi x;
        do{
            ll c=0;
            for(int i=0;i<n;i++)
                c+=cost[arr[i%3]][v[i]];
            if(c<ans){
                ans=c;
                x=arr;
            }
        }while(next_permutation(arr.begin(),arr.end()));
        cout<<ans<<'\n';
        int y[n+1];
        for(int i=0;i<n;i++)
            y[v[i]]=x[i%3];
        for(int i=1;i<=n;i++)
            cout<<y[i]<<' ';
    }
}