#include <bits/stdc++.h>
using namespace std;

bool isInsideTriangle(pair<long long,long long> p, pair<long long,long long> a, pair<long long,long long> b, pair<long long,long long> c) {
    long long ABP = (a.first * (b.second - p.second) + b.first * (p.second - a.second) + p.first * (a.second - b.second));
    long long BCP = (b.first * (c.second - p.second) + c.first * (p.second - b.second) + p.first * (b.second - c.second));
    long long CAP = (c.first * (a.second - p.second) + a.first * (p.second - c.second) + p.first * (c.second - a.second));
    if(ABP >= 0 && BCP >= 0 && CAP >= 0)return true;
    if(ABP <= 0 && BCP <= 0 && CAP <= 0)return true;
    return false;
}