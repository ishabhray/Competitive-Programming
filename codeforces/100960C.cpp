#include <bits/stdc++.h>
using namespace std;

// #define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll, ll>
#define vv vector
#define all(v) (v).begin(), (v).end()
#define MAXN 300005
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert)
{
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert)
    {
        for (cd &x : a)
            x /= n;
    }
}
vi mult(vv<cd> &A, vv<cd> &B)
{
    int n = A.size();
    vv<cd> C(n);
    for (int i = 0; i < n; i++)
        C[i] = A[i] * B[i];
    fft(C, true);
    vi ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = round(C[i].real());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    reverse(all(b));
    int n = a.size();
    int sz = 1;
    while (sz < 2 *2 * n)
        sz <<= 1;
    vv<vv<cd>> A(5, vv<cd>(sz, 0)), B(5, vv<cd>(sz, 0));
    for(int i=0;i<5;i++){
        for(int j=0;j<n;j++){
            if(a[j]=='A'+i)
                A[i][j]=A[i][n+j]=1;
            if(b[j]=='a'+i)
                B[i][j]=1;
        }
        fft(A[i],false);
        fft(B[i],false);
    }
    int ans = 0;
    vi cnt[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cnt[i][j] = mult(A[i], B[j]);
        }
    }
    vi p = {0, 1, 2, 3, 4};
    do
    {
        for (int j = n - 1; j < n - 1 + n; j++)
        {
            int curr = 0;
            for (int i = 0; i < 5; i++)
            {
                curr += cnt[i][p[i]][j];
            }
            ans = max(ans, curr);
        }
    } while (next_permutation(all(p)));
    cout << n - ans << '\n';
}