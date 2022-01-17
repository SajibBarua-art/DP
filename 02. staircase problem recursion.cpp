// problem link: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbk1xZ3lkUUQtVkJZV1NVcU52eURNaE5nMlRvQXxBQ3Jtc0tuYldqUzRxcDk3THl3TS1XTFhZOXZKZF9QT2pMVnNjUThmRzdTRjk5Y0lULXBOMWtyNzBfR3JjUjhiTWVGX29Sa3pUX1RRbHdITFJfZFQ2cDBfcV9GRnIzMGROWmM1LU9WVEViYXBtT2JsY3hXeDB4cw&q=https%3A%2F%2Fwww.codechef.com%2Fproblems%2FJAM11

// recursive solution
#include<bits/stdc++.h>
using namespace std;
 
#define fl(st, en, i) for(int i = st; i < en; i++)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)   __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)   __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)   __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define Case(c) "Case " << c << ": "
#define endl "\n"
#define all(s) s.begin(),s.end()
#define EPS 1e-9
const int MOD = 1e9+7;
const double PI = acos(-1);

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define fix(a) fixed<<setprecision(a)
 
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
 
ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return a*(b/__gcd(a,b)); }
 
/// Modular arithmetic
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
 
/// Policy Based Data Structure 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree< ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update > ordered_set; 
*/
/// os.find_by_order(x) find the number in  index x [ 0 based] and return an iterator at that index
/// os.order_of_key(y) count the numbers that are strictly less than y

/// less_equal => multiset
/// equal => set
/// greater => set but in descending order
/// greater_equal => multiset but in descending order

/**************************************************************start**************************************************************/


const int maxN = 100005;
ll dp[100005];

ll DP(int n = maxN){

    if(n == 0 || n == 1) return 1;
    if(n == 2) return 2;

    if(dp[n]) return dp[n];
    

    return dp[n] = (DP(n-1)%MOD + DP(n-2)%MOD+ DP(n-3)%MOD) % MOD;
}
 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 
int main() {
 
    optimize();
 
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//        freopen("Error.txt", "w", stderr);
//    #endif
 
    int testcase;
    cin>>testcase;

    DP();
    for(int i=1; i<=testcase; i++)
    {
        int n; cin >> n;
        cout << dp[n] << endl;
    }
 
    return 0;
}
