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

int f(string s){
    int n;
    cout<<s<<endl;
    cin>>n;
    if(n<=0)
        exit(0);
    return n;
}
int main()
{
    int te=1;
    while(te--){
        int a=f(string(300,'a'));
        int b=f(string(300,'b'));
        int l=600-a-b;
        string s=string(l,'a');
        int pre=300-b,cntb=0;
        for(int i=0;i<l-1;i++){
            s[i]='b';
            int x=f(s);
            if(x<pre){
                pre=x;
                cntb++;
            }
            else
                s[i]='a';
        }
        if(cntb<300-b)
            s[l-1]='b';
        f(s);
    }
}