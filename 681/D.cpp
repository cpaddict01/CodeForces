#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 30001
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, arr[N];

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>n;
        readArray(arr, n);

        int ok = 1, leave = 0, mn = arr[0];
        arr[0] = 0;
        for(int i=1; i<n-1; i++) {
            if(arr[i] <= leave) break;

            mn = min(mn, arr[i] - leave);
            arr[i] -= mn;
            leave = max(leave, arr[i]);
        }

        mn = arr[n - 1], arr[n - 1] = 0;
        for(int i=n-2; i>0; i--) {   // right to left
            if(arr[i] > mn) {
                break;
            }
            else {
                mn = arr[i];
                arr[i] = 0;
            }
        }

        for(int i=0; i<n; i++) if(arr[i]) {
                ok = 0;
                break;
        }

        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
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