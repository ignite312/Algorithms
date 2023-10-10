#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int bigMod(ll base, ll power, const int M) {
    if(power == 0)return 1;
    int p = bigMod(base, power/2, M) % M;
    if(power % 2 == 0)return p*1LL*p % M;
    return (p*1LL*p % M) * (base % M) % M;
}
int bigPow(ll base, ll power, const int mod) {
    int ans = 1 % mod;
    base %= mod;
    if (base < 0) base += mod;
    while (power) {
        if (power & 1) ans = (ll) ans * base % mod;
        base = (ll) base * base % mod;
        power >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int base, power;
        cin >> base >> power;
        cout << bigMod(base, power, M);
    }
    return 0;
}
