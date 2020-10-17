#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 100001
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int a, b, c, d;

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>a>>b>>c>>d;

        int ans = 0;

        if(abs(a - c) == 0)
            ans = abs(b - d);
        else if(abs(b - d) == 0) 
            ans = abs(a - c);
        else if(abs(a - c) && abs(b - d)){
            ans = abs(b - d) + 2 + abs(a - c);
        }
        
        cout<<ans<<endl;
    }
    return 0;
}

int mulMod(ll a, ll b) {
    a *= b;
    a %= M;
    return a;
}
int addMod(int a, int b) {
    long long c = a + b;
    if(c >= M) {
        c -= M;
    }
    return c;
}
void readArray(int *nums, int n) {
    for(int i=0; i<n; i++) cin>>nums[i];
}
void printArray(int *nums, int n) {
    for(int i=0; i<n; i++) cout<<nums[i]<<" ";
    cout<<endl;
}