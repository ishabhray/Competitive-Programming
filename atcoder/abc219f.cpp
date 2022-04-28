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
class pt:public ii
{
    public:
    pt(int x,int y):ii(x,y)
    {
    }
    pt operator+(const pt &other) const{
        return pt(ff+other.ff,ss+other.ss);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        string s;
        ll k;
        cin>>s>>k;
        vv<pt>v;
        v.pb({0,0});
        pt mov[]={{1,0},{-1,0},{0,1},{0,-1}};
        for(char i:s){
            if(i=='R') v.pb(v.back()+mov[0]);
            else if(i=='L') v.pb(v.back()+mov[1]);
            else if(i=='D') v.pb(v.back()+mov[2]);
            else v.pb(v.back()+mov[3]);
        }
        pt shift=v.back();

        set<pt>t;
        for(auto i:v) t.insert(i);
        if(!shift.ff&&!shift.ss){
            cout<<t.size()<<'\n';
            continue;
        }
        else if(!shift.ff){
            swap(shift.ff,shift.ss);
            for(auto &i:v) swap(i.ff,i.ss);
        }
        vv<vl>ss;
        for(auto i:v){
            ll q=i.ff/shift.ff;
            ll s=i.ff-q*shift.ff;
            ll t=i.ss-q*shift.ss;
            ss.pb({s,t,q});
        }
        sort(all(ss));
        ll ans=k;
        for(int i=0;i+1<ss.size();i++){
            if(ss[i][0]==ss[i+1][0]&&ss[i][1]==ss[i+1][1]){
                ans+=min(k,ss[i+1][2]-ss[i][2]);
            }
            else ans+=k;
        }
        cout<<ans<<'\n';
    }
}