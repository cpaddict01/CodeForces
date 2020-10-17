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
stack<char> stk;

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>s;
        while(!stk.empty()) stk.pop();

        for(int i=0; i<s.length(); i++) {
            if(stk.empty()) stk.push(s[i]);
            else if(s[i] == 'B') stk.pop();
            else stk.push(s[i]);
        }

        cout<<stk.size()<<endl;
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