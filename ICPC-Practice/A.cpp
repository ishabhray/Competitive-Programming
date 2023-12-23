#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll te;
	cin>>te;
	while(te--){
	    ll n,m;
	    cin>>n>>m;
	    vector<ll> a={n-2,m-2,n-2,m-2};
        set<int>ans;
	    for(int mask=0;mask<16;mask++){
	        vector<ll>b=a;
	        for(int i=0;i<4;i++){
	            if(mask&(1<<i)){
	                b[i]++;
	            }
	            else{
	                b[(i+1)%4]++;
	            }
	        }
	        ll curr=0;
	        for(int i=0;i<4;i++) curr=gcd(curr,b[i]);//,cout<<b[i]<<' ';
	        // cout<<'\n';
	        ans.insert(curr);
	    }
	    cout<<ans.size()<<' ';
        for(int i:ans) cout<<i<<' ';
        cout<<'\n';
	}
	return 0;
}