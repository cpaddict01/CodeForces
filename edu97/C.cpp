#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 201
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, arr[N], dp[N][2*N];

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int solve(int idx, int t) {
    if(idx == n) return 0;

    if(t == 2 * n + 1) return 1e7;

    if(dp[idx][t] != -1) return dp[idx][t];

    int ans = INT_MAX;
    ans = min(ans, solve(idx, t + 1));
    ans = min(ans, abs(t - arr[idx]) + solve(idx + 1, t + 1));

    return dp[idx][t] = ans;
}

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>n;
        readArray(arr, n);
        for(int i=0; i<n; i++) for(int j=0; j<=2*n; j++)
            dp[i][j] = -1;
        
        sort(arr, arr + n);

        cout<<solve(0, 1)<<endl;
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