#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 200002
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, b[N];
ll ans;
vector<pair<ll,int>> a;
vector<ll> bb, suffSum;

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>n;
        a.resize(n);
        bb.resize(n);  
        suffSum.resize(n + 1, 0);

        for(int i=0; i<n; i++) {
            cin>>a[i].f;
            a[i].s = i;
        }

        sort(a.begin(), a.end());
        readArray(b, n);

        for(int i=0; i<n; i++)
            bb[i] = b[a[i].s];

        suffSum[n] = 0;
        for(int i=n-1; i>=0; i--) 
            suffSum[i] = suffSum[i + 1] + bb[i];
        
        ans = suffSum[0];

        for(int i=0; i<n; i++)
            ans = min(ans, max(a[i].f, suffSum[i + 1]));
        
        cout<<ans<<endl;
    }
    return 0;
}

int mulMod(ll a, ll b) {
    a *= b;
    a %= M;
    return (int)a;
}
int addMod(int a, int b) {
    long long c = a + b;
    if(c >= M) {
        c -= M;
    }
    return (int)c;
}
void readArray(int *nums, int n) {
    for(int i=0; i<n; i++) cin>>nums[i];
}
void printArray(int *nums, int n) {
    for(int i=0; i<n; i++) cout<<nums[i]<<" ";
    cout<<endl;
}