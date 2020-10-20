#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 300005
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, arr[N];

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>n;
        readArray(arr, n);

        int eq = 1, mx = arr[0];
        for(int i=1; i<n; i++) {
            if(arr[i] != arr[i - 1]) eq = 0;
            mx = max(mx, arr[i]);
        }

        if(eq) cout<<-1<<endl;
        else {
            int idx;

            for(int i=0; i<n; i++) {
                if(!i && arr[i] == mx && arr[i + 1] != mx) {
                    idx = i + 1;
                    break;
                }
                else if(i == n - 1 && arr[i] == mx && arr[i - 1] != mx) {
                    idx = i + 1;
                    break;
                }
                else if(i && i < n - 1 && arr[i] == mx && (arr[i - 1] != mx || arr[i + 1] != mx)) {
                    idx = i + 1;
                    break;
                }
            }
            cout<<idx<<endl;
        }
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