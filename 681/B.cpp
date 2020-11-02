#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define f first
//#define s second
#define M 1000000007
#define N 100001
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, a, b, dp[N][2];
string s;

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int solve(int idx, int blow) {
    if(idx == n) return (blow ? a: 0);

    if(dp[idx][blow] != -1) return dp[idx][blow];

    int ans;

    if(blow) {   //  11 + 1 -> 111
        if(s[idx] == '1') ans = solve(idx + 1, blow);
        else ans = min(a + solve(idx + 1, 0), b + solve(idx + 1, 1));
    }
    else {  // blow  = 0
        if(s[idx] == '1') ans = solve(idx + 1, 1);
        else ans = solve(idx + 1, 0);
    }

    return dp[idx][blow] = ans;
}

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>a>>b;
        cin>>s;
        n = s.length();

        for(int i=0; i<n; i++) dp[i][0] = dp[i][1] = -1;
        cout<<solve(0, 0)<<endl;
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