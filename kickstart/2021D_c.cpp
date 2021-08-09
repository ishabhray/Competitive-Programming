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
set<pll>s;
void add(ll l,ll r){
    if(l>r) return;
    s.insert({l,r});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    cin>>te;
    for(int T=1;T<=te;T++){
        ll n,m;
        cin>>n>>m;
        s.clear();
        for(ll i=0;i<n;i++){
            ll l,r;
            cin>>l>>r;
            s.insert({l,r});
        }
        vl ans;
        for(int i=0;i<m;i++){
            ll x;
            cin>>x;
            auto it=s.lower_bound({x,0});
            if(it==s.end()){
                it--;
                pll y=*it;
                s.erase(it);
                if(x<=y.ss){
                    ans.pb(x);
                    add(y.ff,x-1);
                    add(x+1,y.ss);
                }
                else{
                    ans.pb(y.ss);
                    add(y.ff,y.ss-1);
                }
            }
            else if(it->ff==x){
                pll y=*it;
                ans.pb(x);
                s.erase(it);
                add(x+1,y.ss);
            }
            else{
                pll y=*it;
                if(it==s.begin()){
                    ans.pb(y.ff);
                    s.erase(it);
                    add(y.ff+1,y.ss);
                }
                else{
                    auto it1=it;
                    it1--;
                    pll z=*it1;
                    if(z.ff<=x&&x<=z.ss){
                        ans.pb(x);
                        s.erase(it1);
                        add(z.ff,x-1);
                        add(x+1,z.ss);
                    }
                    else{
                        if(y.ff-x<x-z.ss){
                            ans.pb(y.ff);
                            s.erase(it);
                            add(y.ff+1,y.ss);
                        }
                        else{
                            ans.pb(z.ss);
                            s.erase(it1);
                            add(z.ff,z.ss-1);
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<T<<": ";
        for(ll i:ans) cout<<i<<' ';
        cout<<'\n';
    }
}