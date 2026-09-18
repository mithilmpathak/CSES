#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 200005;
const int LOGK = 30;

// up[j][i] : planet you reached starting from planet i after moving 2^j steps.
// Moving 2^j steps is equivalent to taking two consecutive jumps of 2{j-1} steps:
ll up[LOGK][MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    // vector<ll>a(n+1);
    // for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++){
        cin>>up[0][i];
    }

    for(ll j=1;j<LOGK;j++){
        for(ll i=1;i<=n;i++){
            up[j][i] = up[j-1][up[j-1][i]];
        }
    }

    while(q--){
        ll x, k;
        cin>>x>>k;
        for(ll j=0;j<LOGK;j++){
            if((k >> j) & 1){
                x = up[j][x];
            }
        }
        cout<<x<<"\n";
    }
    return 0;
}