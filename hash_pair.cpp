#include <atcoder/all>
using namespace atcoder;

struct hash_pair
{
    modint998244353 h1;
    modint1000000007 h2;

    hash_pair operator+(const hash_pair &other) const
    {
        return {h1 + other.h1, h2 + other.h2};
    }

    hash_pair operator-(const hash_pair &other) const
    {
        return {h1 - other.h1, h2 - other.h2};
    }

    hash_pair operator*(const hash_pair &other) const
    {
        return {h1 * other.h1, h2 * other.h2};
    }

    hash_pair operator/(const hash_pair &other) const
    {
        return {h1 / other.h1, h2 / other.h2};
    }

    bool operator==(const hash_pair &other) const
    {
        return h1 == other.h1 && h2 == other.h2;
    }

    hash_pair &operator*=(const hash_pair &other)
    {
        h1 *= other.h1;
        h2 *= other.h2;
        return *this;
    }

    hash_pair &operator+=(const hash_pair &other)
    {
        h1 += other.h1;
        h2 += other.h2;
        return *this;
    }

    hash_pair &operator-=(const hash_pair &other)
    {
        h1 -= other.h1;
        h2 -= other.h2;
        return *this;
    }

    hash_pair &operator/=(const hash_pair &other)
    {
        h1 /= other.h1;
        h2 /= other.h2;
        return *this;
    }
};