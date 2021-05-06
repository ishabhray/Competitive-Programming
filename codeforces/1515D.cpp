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
        int n,l,r;
        cin>>n>>l>>r;
        int cnt[n+5]={0};
        for(int i=0;i<l;i++){
            int x;
            cin>>x;
            cnt[x]++;
        }
        for(int i=0;i<r;i++){
            int x;
            cin>>x;
            cnt[x]--;
        }
        vi lt,rt;
        for(int i=0;i<=n;i++){
            if(cnt[i]>0){
                for(int j=0;j<cnt[i];j++)
                    lt.pb(i);
            }
            else if(cnt[i]<0){
                for(int j=0;j<abs(cnt[i]);j++)
                    rt.pb(i);
            }
        }
        if(lt.size()<rt.size())
            swap(lt,rt);
        int ans=rt.size(),p=0;
        sort(all(lt));
        for(int i=0;i<(int)lt.size()-1;i++){
            if(lt[i]==lt[i+1])
                p++,i++;
        }
        int x=lt.size()-(int)(rt.size());
        //cout<<ans<<' '<<p<<' '<<x<<'\n';
        if(x<=p*2)
            ans+=x/2;
        else{
            x-=2*p;
            ans+=p;
            ans+=x;
        }
        cout<<ans<<'\n';
    }
}