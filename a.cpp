#include <cctype>
#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#include <Eigen/Dense>
using namespace Eigen;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using pii = pair<int,int>;using pll = pair<ll,ll>;using pci = pair<char,int>;
using vi = vector<int>;using vl = vector<ll>;using vs = vector<string>;using vb = vector<bool>;using vc = vector<char>;using vd = vector<double>;
using vpii = vector<pii>;using vpll = vector<pll>;using vpci = vector<pci>;
using vvi = vector<vector<int>>;using vvl = vector<vector<ll>>;using vvb = vector<vb>;
using mpii = map<int,int>;using mpll = map<ll,ll>;
using mpib = map<int,bool>;using mpil = map<int,ll>;
using mpci = map<char,int>;using mpsi = map<string,int>;
using mpivi = map<int,vector<int>>;using mpivl = map<int,vector<ll>>;
using mplvl = map<ll,vl>;
using mpisi = map<int,set<int>>;using mpisl = map<int,set<ll>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(flag) if(flag){printf("Yes\n");}else{printf("No\n");}
#define Yes cout << "Yes" << '\n'
#define No cout << "No" << '\n'
#define OUT(x) cout << x << '\n'
#define OUT_(x) cout << x << ' '
#define OUTF(x) cout << fixed << setprecision(15) << x << '\n'
#define OUTV(v) for (int i = 0; i < v.size(); i++){cout << v[i] << (i == (int)v.size() - 1 ? '\n' : ' ');}
#define all(x) (x).begin(),(x).end()
inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)
#define LL(...) long long __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline T ifloor(T x, T y){return x/y-(x%y ? (x < 0)^(y < 0) : 0);}
template<class T> inline T iceil(T x, T y){return x/y+(x%y ? (x >= 0)^(y < 0) : 0);}
int iinf = 1000000000;
ll linf = 1000000000000000000LL;

mt19937 mt;
using mint = modint998244353;

int main (){
}