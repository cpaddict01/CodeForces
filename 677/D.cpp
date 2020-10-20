#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 5003
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, arr[N];
vector<pair<int,int>> nodes;

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>n;
        readArray(arr, n);

        int eq = 1;
        for(int i=1; i<n; i++) if(arr[i] != arr[i - 1]) {
            eq = 0;
            break;
        }

        if(eq) {
            cout<<"NO\n";
            continue;
        }

        nodes.clear();
        for(int i=0; i<n; i++) nodes.push_back({arr[i], i + 1});
        sort(nodes.begin(), nodes.end());

        //for(auto x: nodes) cout<<x.f<<" "<<x.s<<endl;

        int i = 1;
        while(nodes[i].f == nodes[i - 1].f) i++;

        cout<<"YES\n";
        for(int j=0; j<i; j++) cout<<nodes[j].s<<" "<<nodes[i].s<<endl;
        for(int j=i + 1; j<n; j++) cout<<nodes[0].s<<" "<<nodes[j].s<<endl;
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