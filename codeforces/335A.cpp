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
ll fact[100005];
ll finv[100005];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return fact[n]*x%MOD;
    }
}

string s,an;
int n,cnt[26];
bool check(int mid)
{

    string r="";
    int sz=0;
    for(int i=0;i<26;i++){
        if(!cnt[i])
            continue;
        int c=(cnt[i]+mid-1)/mid;
        sz+=c;
        for(int j=0;j<c;j++)
            r+=(char)(97+i);
    }
    //cout<<mid<<' '<<sz<<' '<<r<<'\n';
    if(sz<=n){
        an=r;
        return true;
    }
    return false;
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
    //factorial(100005);
    while(t--){
        cin>>s>>n;
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        int d=0;
        for(int i=0;i<26;i++){
            if(cnt[i])
                d++;
        }

        if(d>n)
            cout<<-1;
        else if(n>=s.size()){
            an=s;
            for(int j=0;j<n-s.size();j++)
                an+='a';
            cout<<"1\n"<<an;
        }
        else{
            int l=1,r=1000,ans;
            while(l<=r){
                int mid=(l+r)/2;
                if(check(mid))
                    r=mid-1,ans=mid;
                else
                    l=mid+1;
            }
            cout<<ans<<'\n'<<an;
            for(int i=0;i<n-an.size();i++)
                cout<<'a';
        }
    }
}