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
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        set<ii>p;
        int a[n+1]={0},b[m+1]={0};
        priority_queue<pair<int,ii>>q;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            p.insert({x,i+1});
        }
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            q.push({-x,{0,i+1}});
        }
        while(q.size()&&p.size()){
            auto z=q.top();
            q.pop();
            int pow=-z.ff,soc=-z.ss.ff,idx=z.ss.ss;
            //cout<<pow<<' '<<soc<<' '<<idx<<'\n';
            auto it=p.lower_bound({pow,0});
            if(it==p.end()||it!=p.begin()&&it->ff!=pow){
                pow=(pow+1)/2;
                soc++;
                q.push({-pow,{-soc,idx}});
            }
            else if(it->ff==pow){
                a[it->ss]=idx;
                b[idx]=soc;
                p.erase(it);
            }
        }
        ll c=0,u=0;
        for(int i=1;i<=n;i++)
            if(a[i])
                c++;
        for(int i=1;i<=m;i++)
            u+=b[i];
        cout<<c<<' '<<u<<'\n';
        for(int i=1;i<=m;i++)
            cout<<b[i]<<' ';
        cout<<'\n';
        for(int i=1;i<=n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
    }
}