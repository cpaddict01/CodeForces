#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 200001
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, arr[N], d, idx;
queue<int> q;

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>n;
        readArray(arr, n);
        d = 0, idx = 1;

        q.push(1);
        int cnt = 1, x;
        while(!q.empty()) {
            x = 0;

            for(int i=0; i<cnt; i++) {
                int temp = q.front();
                q.pop();

                int prev = -1;
                while(idx < n) {
                    if(arr[idx] < prev) break;

                    prev = arr[idx];    q.push(arr[idx]);
                    idx++;
                    x++;
                }
            }

            cnt = x;
            if(q.size()) d++;
        }

        cout<<d<<endl;
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