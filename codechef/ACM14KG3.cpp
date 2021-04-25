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

void dfs(int i,int vis[26],vi adj[26],vi &ans){
    if(vis[i])
        return;
    vis[i]=1;
    ans.pb(i);
    for(auto a:adj[i]){
        dfs(a,vis,adj,ans);
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
	cin>>t;
	//SieveOfEratosthenes(1000000);
    while(t--){
        int m;
        string s,r;
        cin>>s>>r>>m;
        vi adj[26];
        for(int i=0;i<m;i++){
            string x;
            cin>>x;
            adj[x[0]-97].pb(x[3]-97);
        }
        if(s.size()!=r.size()){
            cout<<"NO\n";
            continue;
        }
        vi df[26];
        for(int i=0;i<26;i++){
            int vis[26]={0};
            dfs(i,vis,adj,df[i]);
        }
        bool b=true;
        for(int i=0;i<s.size();i++){
            bool f=false;
            for(auto a:df[s[i]-97])
                if(a==r[i]-97)
                    f=true;
            if(!f){
                b=false;
                break;
            }
        }
        if(b)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}