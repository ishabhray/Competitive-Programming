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
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int a[n];
        for(int &i:a) cin>>i;
        if(n<3){
            cout<<"0\n";
            continue;
        }
        if(n==3){
            cout<<(a[0]==a[2])<<'\n';
            continue;
        }
        if(n==4){
            map<int,int>m;
            for(int i:a) m[i]++;
            if(m.size()==4) cout<<"1\n";
            else if(m.size()==1) cout<<"2\n";
            else if(m.size()==2){
                if(a[0]==a[3]){
                    if(a[1]==a[2]) cout<<"0\n";
                    else cout<<"1\n";
                }
                else cout<<"1\n";
            }
            else{
                if(a[0]==a[3]) cout<<"0\n";
                else cout<<"1\n";
            }
            continue;
        }
        int ma[n+5]={0},mb[n+5]={0},mc[n+5]={0},l1=0,l2=0,l3=0;
        for(int i=0;i<n;i++){
            if(i%3==0) ma[a[i]]++,l1++;
            else if(i%3==1) mb[a[i]]++,l2++;
            else mc[a[i]]++,l3++;
        }
        int ans=n+5;
        for(int i=1;i<=n+3;i++){
            for(int j=1;j<=n+3;j++){
                if(j==i) continue;
                for(int k=1;k<=n+3;k++){
                    if(k==i||k==j) continue;
                    int ai=ma[i],bi=mb[i],ci=mc[i];
                    int aj=ma[j],bj=mb[j],cj=mc[j];
                    int ak=ma[k],bk=mb[k],ck=mc[k];
                    int d1=l1-ai;
                    int d2=l2-bj;
                    int d3=l3-ck;
                    ai=bj=ck=0;
                    int curr=0;
                    int x=min(aj,bi);
                    curr+=x;
                    d1-=x;
                    d2-=x;
                    aj-=x;
                    bi-=x;
                    x=min(ak,ci);
                    curr+=x;
                    d1-=x;
                    d3-=x;
                    ak-=x;
                    ci-=x;
                    x=min(bk,cj);
                    curr+=x;
                    d2-=x;
                    d3-=x;
                    bk-=x;
                    cj-=x;
                    x=min({aj,bk,ci});
                    curr+=2*x;
                    d1-=x;
                    d2-=x;
                    d3-=x;
                    aj-=x;
                    bk-=x;
                    ci-=x;
                    x=min({ak,bi,cj});
                    curr+=2*x;
                    d1-=x;
                    d2-=x;
                    d3-=x;
                    ak-=x;
                    bi-=x;
                    cj-=x;
                    curr+=d1+d2+d3;
                    if(curr<ans){
                        ans=curr;
                        // cout<<i<<' '<<j<<' '<<k<<' '<<curr<<'\n';
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}
2
9
1 1 1 2 2 2 3 3 3
9
1 2 3 4 5 6 7 8 9