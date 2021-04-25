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
bool prime[1000001];
vi primes;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=0;
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
ll fact[1000010];
ll finv[1000010];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return 0;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return fact[n]*x%MOD;
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

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        string a[n],b[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int rmn[26],rmx[26],cmn[26],cmx[26];
        memset(rmn,-1,sizeof(rmn));
        memset(rmx,-1,sizeof(rmx));
        memset(cmn,-1,sizeof(cmn));
        memset(cmx,-1,sizeof(cmx));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='.')
                    continue;
                int x=a[i][j]-'a';
                if(rmn[x]==-1)
                    rmn[x]=i,rmx[x]=i,cmn[x]=j,cmx[x]=j;
                else
                    rmn[x]=min(rmn[x],i),rmx[x]=max(rmx[x],i),cmn[x]=min(cmn[x],j),cmx[x]=max(cmx[x],j);
            }
        }
        for(int i=0;i<n;i++){
            b[i]="";
            for(int j=0;j<m;j++)
                b[i]=b[i]+'.';
        }
        bool ans=true;
        for(int i=0;i<26;i++){
            if(rmn[i]==-1)
                continue;
            if(rmn[i]==rmx[i]){
                for(int j=cmn[i];j<=cmx[i];j++)
                    b[rmn[i]][j]=(char)('a'+i);
            }
            else if(cmn[i]==cmx[i]){
                for(int j=rmn[i];j<=rmx[i];j++)
                    b[j][cmn[i]]=(char)('a'+i);
            }
            else{
                ans=false;
                break;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]!=b[i][j]){
                    ans=false;
                    break;
                }
            }
            if(!ans)
                break;
        }
        if(!ans)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
            int k=0;
            for(k=25;k>=0;k--)
                if(rmn[k]!=-1)
                    break;
            cout<<k+1<<'\n';
            for(int i=k-1;i>=0;i--){
                if(rmn[i]==-1)
                    rmn[i]=rmn[i+1],rmx[i]=rmx[i+1],cmn[i]=cmn[i+1],cmx[i]=cmx[i+1];
            }
            for(int i=0;i<=k;i++){
                cout<<rmn[i]+1<<' '<<cmn[i]+1<<' '<<rmx[i]+1<<' '<<cmx[i]+1<<'\n';
            }
        }
    }
}