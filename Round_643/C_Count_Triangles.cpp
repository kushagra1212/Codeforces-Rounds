// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;

ll calcProgression(ll a, ll d, ll n) {
    return (2 * a + d * (n - 1)) * n / 2;
}

void run() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    ll ans = 0;
    for (int z = c; z <= d; ++z) {
        int minX = std::max(a, z - c + 1);
        if (minX > b) {
            continue;
        }

        int mid = z - b + 1;
        int start = c - std::max(b, z - minX + 1) + 1;

        if (mid <= minX) {
            ans += 1ll * (c - b + 1) * (b - minX + 1);
        } else if (mid > b) {
            // ans += 1ll * (b - minX + 1) * (b - minX + 2) / 2;
            ans += calcProgression(start, 1, b - minX + 1);
        } else {
            ans += calcProgression(start, 1, mid - minX + 1);
            ans += 1ll * (b - mid) * (c - b + 1);
            // ans += 1ll * (mid - minX + 1) * (mid - minX + 2) / 2 + 1ll * (b - mid) * (c - b + 1);
        }
    }    

    printf("%lld\n", ans);
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}