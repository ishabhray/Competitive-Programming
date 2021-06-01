#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    for(ll test=0;test<t;test++)
    {
        ll n;
        cin>>n;
        ll st[n],en[n];
        vector <pair<ll,ll> > times;
        for(ll i=0;i<n;i++)
        {
            cin>>st[i]>>en[i];
            times.push_back({en[i],st[i]});
        }
        sort(times.begin(),times.end());
        ll curr = -1;
        ll ans = 0;
        for(ll i=0;i<times.size();i++)
        {
            // cout<<curr<<' ';
            if(times[i].first>=curr)
            {
                curr = max(curr+1,times[i].second+1);
                ans++;
            }
            // cout<<curr<<'\n';
        }
        cout<<ans<<"\n";
    }
}