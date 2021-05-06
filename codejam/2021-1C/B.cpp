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
int len(ll x){
    int c=0;
    while(x)
        c++,x/=10;
    return c;
}
string solve(string s){
    int n=s.size();
    string ans;
    int x=n+1;
    string aa[]={"","","","910","9899","12345","100101","1234567","10001001","100101102","1000010001","12345678910","100000100001","1234567891011","10000001000001","100001000110002","1000000010000001","12345678910111213","100000000100000001","1234567891011121314"};
    string z[]={"","","12","123","1011","12345","100101","1234567","10001001","100101102","1000010001","12345678910","100000100001","1234567891011","10000001000001","100001000110002","1000000010000001","12345678910111213","100000000100000001","1234567891011121314"};
    ans=z[x];
    //cout<<s<<' '<<ans<<'\n';
    for(int i=1;i<=n/2;i++){
        string r=s.substr(0,i);
        ll pre=stoll(r,nullptr,10);
        bool b=true;
        int c=0;
        if(len(pre)<len(pre+1))
            c++;
        int j=0;
        for(j=i;j+i+c-1<n;j+=i+c){
            r=s.substr(j,i+c);
            ll curr=stoll(r,nullptr,10);
            if(curr<pre+1)
                break;
            else if(curr==pre+1)
                pre=curr;
            else{
                b=false;
                break;
            }
            if(len(pre)<len(pre+1))
                c++;
        }
        if(b){
            //cout<<"$"<<i<<' '<<j<<' '<<c<<'\n';
            r=s.substr(0,i);
            pre=stoll(r,nullptr,10);
            while(r.size()<=s.size()){
                pre++;
                if(r.size()==s.size()){
                    bool f=true;
                    for(int k=0;k<n;k++){
                        if(r[k]>s[k])
                            break;
                        if(r[k]<s[k]){
                            f=false;
                            break;
                        }
                    }
                    if(!f)
                        r=r+to_string(pre);
                    else break;
                }
                else
                    r=r+to_string(pre);
            }
        }
        else{
            //cout<<i<<' '<<j<<' '<<c<<'\n';
            r=s.substr(0,i);
            pre=stoll(r,nullptr,10)+1;
            r=to_string(pre);
            while(r.size()<=s.size()){
                pre++;
                if(r.size()==s.size()){
                    bool f=true;
                    for(int k=0;k<n;k++){
                        if(r[k]>s[k])
                            break;
                        if(r[k]<s[k]){
                            f=false;
                            break;
                        }
                    }
                    if(!f)
                        r=r+to_string(pre);
                    else break;
                }
                else
                    r=r+to_string(pre);
            }
            string t="";
            for(int k=0;k<i;k++)
                t+='9';
            pre=stoll(t,nullptr,10);
            t=to_string(pre);
            while(t.size()<=s.size()){
                pre++;
                if(t.size()==s.size()){
                    bool f=true;
                    for(int k=0;k<n;k++){
                        if(t[k]>s[k])
                            break;
                        if(t[k]<s[k]){
                            f=false;
                            break;
                        }
                    }
                    if(!f)
                        t=t+to_string(pre);
                    else break;
                }
                else
                    t=t+to_string(pre);
            }
            //cout<<t<<'\n';
            if(t.size()<r.size())
                r=t;
        }
        //cout<<r<<'\n';
        if(ans.size()>r.size())
            ans=r;
        else{
            if(ans.size()==r.size()){
                bool f=false;
                for(int k=0;k<r.size();k++){
                    if(r[k]>ans[k])
                        break;
                    if(r[k]<ans[k]){
                        f=true;
                        break;
                    }
                }
                if(f)
                    ans=r;
            }
        }
        //cout<<ans<<'\n';
    }
    return ans;
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        string s;
        cin>>s;
        string ans=solve(s);
        if(ans==s)
            ans=solve(to_string(stoll(s,nullptr,10)+1));
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}