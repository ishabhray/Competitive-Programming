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
	cin>>t;
	//SieveOfEratosthenes(1000000);
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        int b[n];
        vi col[n+2];
        for(int i=0;i<n;i++){
            cin>>b[i];
            col[b[i]].pb(i);
        }
        vi hist[n+1];
        for(int i=1;i<=n+1;i++)
            hist[col[i].size()].pb(i);
        int mis=hist[0][0];
        vi xi;
        int idx=n;
        for(int i=0;i<x;i++){
            while(hist[idx].empty())
                idx--;
            int c=hist[idx].back();
            xi.pb(col[c].back());
            col[c].pop_back();
            hist[idx].pop_back();
            hist[idx-1].pb(c);
        }
        while(hist[idx].empty()&&idx>0)
            idx--;
        if(2*idx-(n-x)>n-y){
            cout<<"NO\n";
            continue;
        }
        else{
            cout<<"YES\n";
            vi v;
            for(;idx>0;idx--){
                for(auto a:hist[idx])
                    v.insert(v.end(),col[a].begin(),col[a].end());
            }
            int cnt=n-y;
            int ans[n]={0};
            for(auto a:xi)
                ans[a]=b[a];
            vi mismat;
            for(int i=0;i<n-x;i++){
                ans[v[i]]=b[v[(i+(n-x)/2)%(n-x)]];
                if(ans[v[i]]==b[v[i]])
                    ans[v[i]]=mis,cnt--;
                else
                    mismat.pb(v[i]);
            }
            int k=0;
            while(cnt--)
                ans[mismat[k++]]=mis;
            for(int i=0;i<n;i++)
                cout<<ans[i]<<' ';
            cout<<'\n';
        }
        
    }
}