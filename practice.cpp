#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll,ll>
#define vii vector<pii> 
#define For(n) for(ll i = 0; i < n; i++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define for2(a) for(auto& [x,y]:a)
#define ff first 
#define ss second 
#define all(v) v.begin(), v.end()
#define sumv(a) accumulate(all(a),0ll);
#define suma(a,n) accumulate(a,a+n,0ll);
#define srta(a,n) sort(a,a+n);
#define dsrta(a,n) sort(a, a + n, greater<int>());
#define srtv(v) sort(v.begin(), v.end());
#define dsrtv(v) sort(v.begin(), v.end(), greater<>());
#define reva(a,n) reverse(a,a+n);
#define revv(v) reverse(all(v));
#define l_tr(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define u_tr(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
#define pb push_back
#define setBits(x) __builtin_popcountll(x)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define in(n) ll n; cin>>n;
#define str(s) string s; cin>>s;
#define ain(a,n) ll a[n]; rep(i,0,n) cin>>a[i];
#define vin(v,n) vi v(n); rep(i,0,n) cin>>v[i];
#define aout(a,n) rep(i,0,n) cout<<a[i]<<" "; cout<<endl;
#define Reset(a, b) memset(a, b, sizeof(a));
#define en cout<<endl;
#define out(ans) cout<<ans<<endl;
#define mi map<ll,ll> 
#define max_ele(a) *max_element(all(a));
#define min_ele(a) *min_element(all(a));
#define max_heap priority_queue<ll> //maxpq
#define min_heap priority_queue<ll, vector<ll>, greater<ll>> //minpq
#define PI 3.1415926535897932384626433832795
const ll N = 1e5+5, MOD = 1e9+7 , inf = 1e18;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
// It can be used to generate a increasing sequence of consecutive numbers.
// int numbers[11]; int st = 10;  iota(numbers, numbers + 11, st); => [10,20]

// template <typename T>
// struct Fenwick {
//     const int n;
//     std::vector<T> a;
//     Fenwick(int n) : n(n), a(n) {}
//     void add(int x, T v) {
//         for (int i = x + 1; i <= n; i += i & -i) {
//             a[i - 1] += v;
//         }
//     }
//     T sum(int x) {
//         T ans = 0;
//         for (int i = x; i > 0; i -= i & -i) {
//             ans += a[i - 1];
//         }
//         return ans;
//     }
//     T rangeSum(int l, int r) {
//         return sum(r) - sum(l);
//     }
// };

// struct bit {
//     int n;
//     vector<int> a;
//     bit(int _n) {
//         a.resize(_n + 1);
//         n = _n;
//     }
//     void add(int pos, int x) {
//         for (; pos <= n; pos += (pos & -pos)) a[pos] += x;
//     }
//     int query(int pos) {
//         int ans = 0;
//         for (; pos > 0; pos -= (pos & -pos)) ans += a[pos];
//         return ans;
//     }
//     int query(int l, int r) {
//         return query(r) - query(l - 1);
//     }
// };

ll getGCD(ll a,ll b){ return b == 0 ? a : getGCD(b,a%b);}
ll getLCM(ll a,ll b){ return (a/getGCD(a,b))*b;}

ll  SetBit (ll n, ll X){ return n | (1 << X);}
ll  ClearBit (ll n, ll X){ return n & ~(1 << X);}
ll  ToggleBit (ll n, ll X){ return n ^ (1 << X);}
bool CheckBit (ll n, ll X){ return (bool)(n & (1 << X));}

ll powerM(ll x, ll  y){  
    if(y<0ll)
    return 0;
    ll result = 1ll;     
    x = x % MOD; 
    if (x == 0ll) return 0; 
    while (y > 0ll) {  
        if (y & 1ll)  
        result = (result*x) % MOD;  
        y = y>>1ll; 
        x = (x*x) % MOD;  
    }  
    return result;  
}

ll addM(ll x, ll y){
    x%=MOD;
    y%=MOD;
    return (x+y)%MOD;
}
 
ll mulM(ll x, ll y){
    return ((x%MOD) * 1ll * (y%MOD)) % MOD;
}

ll modeExp(ll x, ll y){
    if(y==0) return 1ll;
    ll ans = 1ll;
    x%=MOD;
    while(y){
        if(y & 1) ans = mulM(ans, x);
        x = mulM(x, x);
        y >>= 1ll;
    }
    return ans;
}
 
ll inviM(ll x){
    return modeExp(x, MOD - 2);
}
 
ll divideM(ll x, ll y){
    return mulM(x, inviM(y));
}

ll fact[N];
void fillfct (){
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < N; i++)
    fact[i] = (fact[i - 1] * i)%MOD;
    return;
}

ll nCr(ll n, ll k){
    if(n<k) return 0;
    if(k<0) return 0;
    if(n==0) return 1;
    return divideM(fact[n], mulM(fact[k], fact[n - k]));
    //return (fact[n]/(fact[n-k]))/fact[k];
}

ll nPr(ll n,ll r,ll m=MOD){
    return divideM(fact[n],fact[n-r]);
}

ll subM(ll A,ll B){
    return (A-B+MOD)%MOD;
}

bool sortbysecond(const pair<ll,ll>&a,const pair<ll,ll>&b){return (a.second < b.second);}
bool sortbysecdesc(const pair<int,int> &a,const pair<int,int> &b){return a.second>b.second;}
bool sortbyCond(const pair<int, int>& a,const pair<int, int>& b){
    if (a.first != b.first) return (a.first < b.first);
    else return (a.second > b.second);
    // Sorting Vector of Pairs by 1st element in ascending and 2nd element in descending
}

// // for (int i=0; i<n; i++)     // sum of all subarrays
// // result += (arr[i] * (i+1) * (n-i));
// // sum+= [((i + 1) * (n – i) + 1) / 2]*arr[i]   == for all odd length subarrays

vector<ll> printPrimeFactors(ll n) {
   vector<ll> ans;
   while (n%2 == 0){
      ans.pb(2);
      n = n/2;
   }
   for (int i = 3; i <= sqrtl(n); i = i+2){
      while (n%i == 0){
         ans.pb(i);
         n = n/i;
      }
   }
   if (n > 2)
   ans.pb(n);
   return ans;
}

ll countBits(ll n){return (ll)log2(n)+1;}

int countDivisors(int n){
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) cnt++;
            else cnt = cnt + 2;
        }
    }
    return cnt;
}

bool PowerOfTwoH(ll n){if(n==0) return false; return (ceil(log2(n)) == floor(log2(n)));}

vector<bool> isPrime(1e5+6, true);
void sieve(int n){
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2; i*i<=n; ++i){
      if(isPrime[i]){
         for(int j=i*i; j<=n; j += i)
            isPrime[j]=false;
        }
    }
}

vector<int> bfs(int nodes,vector<int> adj[]){
    int vis[nodes]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return ans;
}

void f(int node,vector<int> adj[],int vis[],vector<int> &ans){
    vis[node]=1;
    ans.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            f(it,adj,vis,ans);
        }
    }
}

vector<int> DFS(int nodes,vector<int> adj[]){
    int vis[nodes]={0};
    int start=0;
    vector<int>ans;
    f(start,adj,vis,ans);
    return ans;
}

// vector<ll>p(n,a[0]);
// vector<ll>s(n,a[n-1]);
// rep(1,n)
// p[i]=p[i-1]+a[i];
// for(ll i=n-2;i>=0;i--)
// s[i]=s[i+1]+a[i];
// vector<int>temp=primeFactors(n); in int main()

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
	fillfct();
    sieve(100005);
	ll copy_nhi_kiya_mene=1;
    cin >> copy_nhi_kiya_mene;
	while (copy_nhi_kiya_mene--){
    in(n) in(m) vin(a,m) 
    }
}