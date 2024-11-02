#include <iostream>
#include <tuple>

using namespace std;
// tie(g, s, t) = extended_gcd(x, y) <- x * s + y * t = g
tuple<long long, long long, long long> extended_gcd(long long x, long long y) {
    if (y == 0) {
        return make_tuple(x, 1, 0);
    }
    long long g, s, t;
    tie(g, s, t) = extended_gcd(y, x % y);
    return make_tuple(g, t, s - (x / y) * t);
}