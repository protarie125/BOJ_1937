#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;

ll n;
vvl M;
vvl dp;

vl dx{-1, 1, 0, 0};
vl dy{0, 0, -1, 1};

ll solve(ll y, ll x) {
  if (dp[y][x] < 0) {
    dp[y][x] = 1;
    for (auto d = 0; d < 4; ++d) {
      const auto& nx = x + dx[d];
      const auto& ny = y + dy[d];

      if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
      if (M[ny][nx] <= M[y][x]) continue;

      dp[y][x] = max(dp[y][x], solve(ny, nx) + 1);
    }
  }

  return dp[y][x];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  M = vvl(n, vl(n));
  for (auto&& r : M) {
    for (auto&& m : r) {
      cin >> m;
    }
  }

  dp = vvl(n, vl(n, -1));
  ll ans = 0;
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < n; ++j) {
      const auto& val = solve(i, j);
      ans = max(ans, val);
    }
  }

  cout << ans;

  return 0;
}