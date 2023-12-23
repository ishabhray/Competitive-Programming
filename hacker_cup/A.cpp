#include <bits/stdc++.h>
using namespace std;

#define forn(i,m,n) for(ll i=m;i<n;i++)
#define vv vector
#define vi vv<int>
#define ii pair<int,int>
#define vii vv<ii>
#define mp make_pair
#define pb push_back
#define PI 3.141592653589
#define ll long long
#define pll pair<ll,ll>
#define vl vv<ll>
#define ff first
#define ss second
#define MOD 1000000007

void solve(){
    ll n,k;
    cin>>n>>k;
    vl a(n),b(n);
    forn(i,0,n){
        cin>>a[i];
    }
    forn(i,0,n){
        cin>>b[i];
    }
    if(n==2){
        if(a[0]==b[0]){
            if(k%2) cout<<"NO\n";
            else cout<<"YES\n";
        }
        else{
            if(k%2==0) cout<<"NO\n";
            else cout<<"YES\n";
        }
        return;
    }
    if(k==0){
        forn(i,0,n){
            if(a[i]!=b[i]){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
        return;
    }
    ll p=0;
    forn(i,0,n){
        if(a[i]==b[0]){
            p=i;
            break;
        }
    }
    forn(i,0,n){
        if(a[(p+i)%n]!=b[i]){
            cout<<"NO\n";
            return;
        }
    }
    if(p==0 && k==1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif


    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}