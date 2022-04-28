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
int r[500005],p[500005];
int get(int a){ return p[a]=(p[a]==a)?a:get(p[a]);}
void uni(int a,int b){
    a=get(a);
    b=get(b);
    if(a==b) return;
    if(a>b) swap(a,b);
    p[b]=a;
    r[a]=r[b];
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
    int next[60];
    for(char c='0';c<'9';c++) next[c]=c+1;
    next['9']='0';
    for(int T=1;T<=te;T++){
        int n;
        string s;
        cin>>n>>s;
        set<int>v[10];
        for(int i=0;i<n-1;i++){
            if(s[i+1]==next[s[i]]) v[s[i]-'0'].insert(i);
        }
        for(int i=0;i<n;i++) p[i]=r[i]=i;
        int last=9,curr=0;
        while(1){
            if(v[curr].empty()){
                if(curr==last) break;
                else {curr=(curr+1)%10; continue;}
            }
            last=curr;
            vi upd;
            for(int i:v[curr]){
                // cout<<curr<<' '<<i<<' '<<s[i]<<' '<<r[i]+1<<' '<<s[r[i]+1]<<'\n';
                int x=get(i);
                if(x) v[s[get(x-1)]-'0'].erase(get(x-1));
                if(r[x]+1<n) v[s[get(r[x]+1)]-'0'].erase(get(r[x]+1));
                uni(x,r[x]+1);
                s[x]=next[next['0'+curr]];
                upd.pb(x);
            }
            v[curr].clear();
            for(int i:upd){
                // cout<<i<<' '<<s[get(i)]<<' '<<s[get(i-1)]<<'\n';
                if(i&&s[i]==next[s[get(i-1)]]) v[s[get(i-1)]-'0'].insert(get(i-1));
                if(r[i]+1<n&&s[get(r[i]+1)]==next[s[i]]) v[s[i]-'0'].insert(i);
            }
            // cout<<curr<<' '<<s<<'\n';
            // for(int i=0;i<n;i++){
            //     if(i==p[i]) cout<<p[i]<<' '<<r[i]<<'\n';
            // }
            curr++;
            if(curr==10) curr=0;
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(i==get(i)) ans+=s[i];
        }
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}
