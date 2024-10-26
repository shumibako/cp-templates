#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct Zobrist_Hash
{
private:
    string _type;
    int _max_element;
    int _size;
    mt19937 _mt;
    long long _mod;
    vector<long long> _rnd_table;
    vector<long long> _hash_table;

public:
    Zobrist_Hash(int max_element, int size, string type = "XOR", int seed = 0, long long mod = (1LL << 61) - 1)
    {
        assert(0 < max_element && max_element < 1e8);
        assert(0 < size && size < 1e8);
        assert(type == "XOR" || type == "ADD" || type == "MUL");

        _rnd_table.resize(max_element);
        _hash_table.resize(size + 1);
        _type = type;
        _size = size;
        _max_element = max_element;
        _mt.seed(seed);
        for (int i = 0; i < max_element; i++)
            _rnd_table[i] = _mt() % _mod;
    }

    long long F(long long x, long long y)
    {
        if (_type == "XOR")
            return (x ^ _rnd_table[y]) % _mod;
        if (_type == "ADD")
            return (x + _rnd_table[y]) % _mod;
        if (_type == "MUL")
            return (x * _rnd_table[y]) % _mod;
        return 0;
    }

    void set_vector(vector<long long> V)
    {
        assert(V.size() == _size);
        _hash_table[0] = 0;
        for (int i = 0; i < V.size(); i++)
        {
            assert(0 <= V[i] && V[i] < _max_element);
            _hash_table[i + 1] = F(_hash_table[i], V[i]);
        }
    }

    long long get_hash(int l, int r)
    {
        assert(0 <= l && l < r && r <= _hash_table.size());
        return (_hash_table[r] - _hash_table[l] + _mod) % _mod;
    }
};