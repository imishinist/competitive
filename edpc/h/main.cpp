#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cstdint>

template <std::uint_fast64_t Modulus>
class modint {
    using u64 = std::uint_fast64_t;

public:
    u64 a;
    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64& value() noexcept { return a; }
    constexpr const u64& value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint& operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint& operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint& operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint& operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

using mint = modint<1000000007>;

#define eps 1e-14

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> fields(h);
    for (int i = 0; i < h; i++) {
        cin >> fields[i];
    }

    vector<vector<mint>> dp(h, vector<mint>(w));
    dp[0][0] = 1;
    for (int i = 1; i < h; i++) {
        if (fields[i][0] == '#') dp[i][0] = 0;
        else dp[i][0] = dp[i-1][0];
    }
    for (int i = 1; i < w; i++) {
        if (fields[0][i] == '#') dp[0][i] = 0;
        else dp[0][i] = dp[0][i-1];
    }

    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (fields[i][j] == '#') continue;
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    }
    cout << dp[h-1][w-1].value() << endl;

    return 0;
}
