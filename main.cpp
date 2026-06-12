// وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى وَأَنَّ سَعْيَهُ سَوْفَ يُرَى
#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define all_in(a)for (auto &i : a)cin >> i;
#define Fatomaa ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
double pi = acos(-1);
const int N = 101, M = 1e6 + 6 + 16, MOD = 1e9 + 7, INF = 2e18;

void files() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}
bool comp(string s,string t) {
    return s.size()<t.size();
}
void magic() {
    int n, m; cin >> n >> m;
    vector<string> DIC(n);
    all_in(DIC);

    // Sort by length first, then lexicographically for same length
    sort(all(DIC), [](string a, string b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    while (m--) {
        string s; cin >> s;
        int ans = -1;

        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            string t = DIC[mid];

            if (t.size() >= s.size() && t.substr(0, s.size()) == s) {
                ans = t.size() - s.size();
                hi = mid - 1;
            }
            else if (t.size() < s.size() || t < s) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        cout << ans << endl;
    }
}
signed main() {
    Fatomaa;
    files();
    int T = 1;
    // cin>>T;
    while (T--)magic();
}