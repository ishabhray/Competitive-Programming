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
ii mv[100005];
int n;
map<ii,int>m;
bool can_go(int ax,int ay,int bx,int by){
    if(ax==bx&&ay==by)
        return true;
    bool b=false;
    for(int i=0;i<n;i++){
        if(ax+mv[i].ff>n||ax+mv[i].ff<1||ay+mv[i].ss>n||ay+mv[i].ss<1)
            continue;
        ii req={bx-ax-mv[i].ff,by-ay-mv[i].ss};
        if(m[req]||req==mp(0,0)){
            b=true;
            break;
        }
    }
    return b;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ii gen_pt(){
    return {1+rng()%n,1+rng()%n};
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
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int ax,ay,bx,by;
        cin>>n>>ax>>ay>>bx>>by;
        for(int i=0;i<n;i++){
            cin>>mv[i].ff>>mv[i].ss;
            m[mv[i]]++;
        }
        
        if(can_go(ax,ay,bx,by)){
            cout<<"Alice wins\n";
            break;
        }
        if(n<=10){
            bool f=true;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(!can_go(bx,by,i,j)){
                        cout<<"tie "<<i<<' '<<j<<'\n';
                        f=false;
                        break;
                    }
                }
                if(!f)
                    break;
            }
            if(f)
                cout<<"Bob wins\n";
        }
        else{
            ii pos=gen_pt();
            while(can_go(bx,by,pos.ff,pos.ss))
                pos=gen_pt();
            cout<<"tie "<<pos.ff<<' '<<pos.ss<<'\n';
        }
    }
}