#include<bits/stdc++.h>

using namespace std;
#define ll                   long long int
#define endl  	             "\n"
#define pb                   push_back
#define arsort(ar,n)         sort(ar,a+n)
#define dsort(ar,n)          sort(ar,ar+n,greater<>())
#define varsort(v)           sort(v.begin(), v.end());
#define vdsort(v)            sort(v.begin(), v.end(),greater<>())
#define YES                  cout<<"YES\n"
#define NO                   cout<<"NO\n"
#define fast                 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tc                   int t; cin >> t; while(t--)
#define all(x)               (x.begin(),x.end())
#define MAXFACT              500
const int   N                               = (int) 1e6+5;
const int   M                               = (int) 1e9+5;
const ll mod = 1e9 + 7;
int main(){
    fast
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //cout<<bitset<16>(2047)<<endl;//deci_to_binary
    //cout<<oct<<n<<endl;//deci_to_oct
    //cout<<hex<<n<<endl;//deci_to_hexa
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a=0,b=2047;
        while(n--){
            int x;
            cin>>x;
             a|=x;
             b&=x;
        }
        cout<<a-b<<endl;
    }
    return 0;
}
