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

int p[500005];
int get(int a){
    return p[a]=(p[a]==a)?a:get(p[a]);
}
void uni(int a,int b){
    a=get(a);
    b=get(b);
    if(a==b)
        return;
    p[b]=a;
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
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=m;i++)
            p[i]=i;
        set<int>ans;
        vv<pair<ii,int>>v;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            if(k==1){
                int z;
                cin>>z;
                z--;
                if(get(z)==get(m))
                    continue;
                ans.insert(1+i);
                uni(m,z);
            }
            else{
                int y,z;
                cin>>y>>z;
                y--,z--;
                //v.pb({{min(y,z),max(y,z)},i+1});
                if(get(y)==get(z))
                    continue;
                ans.insert(i+1);
                uni(y,z);
            }
        }
        
        cout<<power(2,ans.size())<<' '<<ans.size()<<'\n';
        for(int i:ans)
            cout<<i<<' ';
    }
}