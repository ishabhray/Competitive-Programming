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

int p[200005],sz[200005];
map<int,int>m[200005];
int get(int x){
    return p[x]=(p[x]==x)?x:get(p[x]);
}
void uni(int x,int y){
    x=get(x);
    y=get(y);
    if(x==y)
        return;
    if(sz[x]>=sz[y]){
        sz[x]+=sz[y];
        p[y]=x;
        for(auto i:m[y])
            m[x][i.ff]+=i.ss;
    }
    else{
        sz[y]+=sz[x];
        p[x]=y;
        for(auto i:m[x])
            m[y][i.ff]+=i.ss;
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
        int n,q;
        cin>>n>>q;
        int c[n+1];
        for(int i=1;i<=n;i++)
            cin>>c[i];
        for(int i=1;i<=n;i++)
            p[i]=i,sz[i]=1,m[i][c[i]]++;
        while(q--){
            int t,x,y;
            cin>>t>>x>>y;
            if(t==1)
                uni(x,y);
            else{
                get(x);
                if(m[p[x]].find(y)!=m[p[x]].end())
                    cout<<m[p[x]][y]<<'\n';
                else
                    cout<<"0\n";
            }
        }
    }
}