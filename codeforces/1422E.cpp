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
ll fact[100010];
ll finv[100010];
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
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        string s;
        cin>>s;
        int n=s.size();
        vi ans;
        vv<string>ans1;
        ans.pb(1);
        
        string curr="";
        curr=s[n-1];
        char nextdiff[n];
        nextdiff[n-1]='a'-1;
        ans1.pb(curr);
        int currsize=1;
        bool b=true;
        for(int i=n-2;i>=0;i--){
            if(!b||s[i]!=curr[0]||s[i]<=nextdiff[i+1]){
                b=true;
                if(currsize>=1&&s[i]!=curr[0])
                    nextdiff[i]=curr[0];
                else
                    nextdiff[i]=nextdiff[i+1];
                currsize++;
                curr=s[i]+curr;
                ans.pb(currsize);
                if(curr.size()<=15)
                    ans1.pb(curr);
                else{
                    string t="";
                    for(int i=0;i<13;i++)
                        t=t+curr[i];
                    t+=curr[curr.size()-2];
                    t+=curr[curr.size()-1];
                    curr=t;
                    ans1.pb(t);
                }
            }
            else{
                if(currsize<=2)
                    nextdiff[i]='a'-1;
                else if(curr[1]!=curr[2])
                    nextdiff[i]=curr[2];
                else
                    nextdiff[i]=nextdiff[i+2];
                currsize--;
                
                ans.pb(currsize);
                string t="";
                for(int i=1;i<curr.size();i++)
                    t=t+curr[i];
                curr=t;
                ans1.pb(curr);
                b=false;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            cout<<ans[i]<<' ';
            if(ans1[i].size()<=10)
                cout<<ans1[i]<<'\n';
            else{
                for(int j=0;j<5;j++)
                    cout<<ans1[i][j];
                cout<<"..."<<ans1[i][ans1[i].size()-2]<<ans1[i][ans1[i].size()-1]<<'\n';
            }
        }
    }
}