#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define f first
//#define s second
#define M 1000000007
#define N 100001
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n;
string s;
unordered_set<int> S;

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>n;
        cin>>s;    
        
        int ans = 0;
        bool cycle = true;
        for(int i=0; i<n; i++) if(s[i] == '>') {
            cycle = false;
            break;
        } 
        if(cycle) {
            cout<<n<<endl;
            continue;
        }

        cycle = true;
        for(int i=0; i<n; i++) if(s[i] == '<') {
            cycle = false;
            break;
        } 
        if(cycle) {
            cout<<n<<endl;
            continue;
        }

        S.clear();
        for(int i=0; i<n; i++) if(s[i] == '-') {
            S.insert(i);
            S.insert((i + 1) % n);
        }

        cout<<S.size()<<endl;
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