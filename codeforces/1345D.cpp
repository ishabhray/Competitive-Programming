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
int vis[1000][1000];
char ch[1000][1000];
int n,m;
void count(int i,int j){
    if(i<0||j<0||i==n||j==m||vis[i][j]||ch[i][j]=='.')
        return;
    vis[i][j]=1;
    count(i-1,j);
    count(i+1,j);
    count(i,j-1);
    count(i,j+1);
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
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>ch[i][j];
        bool r=false,c=false,b=false;
        for(int i=0;i<n;i++){
            int cnt=0;
            bool f=false;
            for(int j=0;j<m;j++){
                if(ch[i][j]=='.')
                    cnt++;
                else if(!f)
                    f=true;
                else if(ch[i][j-1]=='.')
                    b=true;
            }
            if(cnt==m)
                r=true;
        }
        for(int i=0;i<m;i++){
            int cnt=0;
            bool f=false;
            for(int j=0;j<n;j++){
                if(ch[j][i]=='.')
                    cnt++;
                else if(!f)
                    f=true;
                else if(ch[j-1][i]=='.')
                    b=true;
            }
            if(cnt==n)
                c=true;
        }
        if(r^c||b){
            cout<<-1;
            return 0;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                vis[i][j]=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ch[i][j]=='#'&&vis[i][j]==0){
                    cnt++;
                    count(i,j);
                }
            }
        }
        cout<<cnt;
    }
}