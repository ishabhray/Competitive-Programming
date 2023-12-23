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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    while(te--){
        int n;
        cin>>n;
        ll a[n];
        for(ll &i:a) cin>>i;
        ll s=0,pre=a[0];
        for(ll i:a) s+=i;
        vl ans(n,0);
        ll mn=a[0];
        ans[0]=s;
        for(int i=1;i<n;i++){
            ans[i]=max(mn,(s+i)/(i+1));
            pre+=a[i];
            mn=max(mn,(pre+i)/(i+1));
        }
        int q;
        cin>>q;
        reverse(all(ans));
        for(int i=0;i<q;i++){
            int t;
            cin>>t;
            if(t<ans[0]){
                cout<<"-1\n";
                continue;
            }
            auto it=upper_bound(all(ans),t);
            it--;
            int x=it-ans.begin();
            x=n-x;
            cout<<x<<'\n';
        }
    }
}