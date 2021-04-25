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

bool check(vv<char>&s,string &r){
    int n=s.size(),m=r.size();
    int curr=0;
    for(int i=0;i<n;i++){
        if(s[i]==r[curr])
            curr++;
        if(curr==m)
            return true;
    }
    return false;
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
    while(te--){
        string t,p;
        cin>>t>>p;
        int n=t.size();
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]--;
        }
        int l=0,r=n,ans;
        while(l<=r){
            int mid=(l+r)/2;
            vv<char>s;
            vi v;
            for(int i=0;i<mid;i++)
                v.pb(a[i]);
            sort(all(v));
            int j=0;
            for(int i=0;i<n;i++){
                if(!v.empty()&&i==v[j])
                    j++;
                else
                    s.pb(t[i]);
            }
            if(check(s,p))
                ans=mid,l=mid+1;
            else
                r=mid-1;
        }
        cout<<ans;
    }
}