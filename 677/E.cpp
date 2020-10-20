#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 100001
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n;

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int main() {
    int t = 1; //cin>>t;
    ll fact[21];
    fact[0] = 1;
    for(ll i=1; i<21; i++) fact[i] = i * fact[i - 1];

    while(t--) {
        cin>>n;
        
        ll ans = 1;
        
        ans *= (fact[n] / fact[n >> 1]);
        //cout<<ans<<endl;
        ans /= fact[n >> 1];
        //cout<<ans<<endl;
        ans = (ans * fact[(n >> 1) - 1] * fact[(n >> 1) - 1]) >> 1;

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