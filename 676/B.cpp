#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 100001
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n;
string str[202];

int mulMod(ll, ll); int addMod(int, int);
void readArray(int *, int); void printArray(int *, int);

int main() {
    int t = 1; cin>>t;

    while(t--) {
        cin>>n;
        for(int i=0; i<n; i++) cin>>str[i];
        
        int right = (str[0][1] - '0'), down = (str[1][0] - '0'), c = 0;
        int left = (str[n - 1][n - 2] - '0'), up = (str[n - 2][n - 1] - '0');
        vector<pair<int,int>> cell;

        if(right + down == 0) {          // make others 1
            if(!left) cell.push_back({n, n - 1});
            if(!up) cell.push_back({n - 1, n});
        }
        else if(right + down == 2) {        // make others 0
            if(left) cell.push_back({n, n - 1});
            if(up) cell.push_back({n - 1, n});            
        }
        else {         // right + down == 1
            if(left + up == 0) {          // make others 1
                if(!right) cell.push_back({1, 2});
                if(!down) cell.push_back({2, 1});
            }
            else if(left + up == 2) {        // make others 0
                if(right) cell.push_back({1, 2});
                if(down) cell.push_back({2, 1});            
            }
            else {
                if(right) cell.push_back({1, 2});
                if(down) cell.push_back({2, 1});  
                if(!left) cell.push_back({n, n - 1});
                if(!up) cell.push_back({n - 1, n});               
            }            
        }

        cout<<cell.size()<<endl;
        for(auto x: cell) cout<<x.first<<" "<<x.second<<endl;
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