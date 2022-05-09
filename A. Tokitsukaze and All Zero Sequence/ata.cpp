#include<bits/stdc++.h>
using namespace std;
//constants :
const int   N                               = (int) 1e6+5;
const int   M                               = (int) 1e9+5;
const int   mod                             = (int) 1000000007;
const int   max_prime                       = (int) 1e6+3;
const int   BLK                             = (int) 700;

//data_type_compressions :

#define     ll                              long long int
#define     ull                             unsigned long long int
#define     ui                              unsigned int

//STL :
#define     vi                              vector<int>
#define     vb                              vector<bool>
#define     vs                              vector<string>
#define     vl                              vector<ll>
#define     si                              set<int>
#define     sl                              set<ll>
#define     ip                              pair<int,int>
#define     lp                              pair<ll,ll>
#define     ips                             pair<string,int>
#define     lps                             pair<string,ll>
#define     ipc                             pair<char,int>
#define     lpc                             pair<char,ll>
#define     vip                             vector<ip>
#define     PQ                              priority_queue
#define     vlp                             vector<lp>
#define     hashmap                         unordered_map
#define     msi                             multiset<int>
#define     msl                             multiset<ll>
#define     pb                              push_back
#define     spb                             insert
#define     erase_duplicates(x)             x.erase(unique(all(x)),x.end());
#define     all(x)                          x.begin(),x.end()
#define     all_0(x)                        memset(x,0,sizeof(x))
#define     all_neg(x)                      memset(x,-1,sizeof(x))
#define     all_1(x)                        memset(x,1,sizeof(x))

//I/O :

#define     Faster                          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     Read(x)                         freopen(x,"r",stdin)
#define     Write(x)                        freopen (x,"w",stdout)
#define     PI                              acos(-1)
#define     take_the_array_INT(x,o,n)       for(int i=o;i<=n;i++){scanf("%d",&x[i]);}
#define     take_the_array_LL(x,o,n)        for(int i=o;i<=n;i++){scanf("%lld",&x[i]);}
#define     print_the_array_INT(x,o,n)      for(int i=o;i<=n;i++){printf("%d ",x[i]);}printf("\n");
#define     print_the_array_LL(x,o,n)       for(int i=o;i<=n;i++){printf("%lld ",x[i]);}printf("\n");
#define     cin_the_array(x,o,n)            for(int i=o;i<=n;i++){cin>>x[i];}
#define     cout_the_array(x,o,n)           for(int i=o;i<=n;i++){cout<<x[i]<<" ";}cout<<endl;
#define     int_in(x)                       scanf("%d",&x)
#define     ll_in(x)                        scanf("%lld",&x)
#define     dbl_in(x)                       scanf("%lf",&x)
#define     char_in(x)                      scanf(" %c",&x)
#define     str_in(x)                       scanf("%s",&x)
#define     int_in2(x,y)                    scanf("%d %d",&x,&y)
#define     int_in3(x,y,z)                  scanf("%d %d %d",&x,&y,&z)
#define     ll_in2(x,y)                     scanf("%lld %lld",&x,&y)
#define     ll_in3(x,y,z)                   scanf("%lld %lld %lld",&x,&y,&z)
#define     int_out(x)                      printf("%d",x)
#define     ll_out(x)                       printf("%lld",x)
#define     char_out(x)                     printf("%c",x)
#define     str_out(x)                      printf("%s",x)
#define     YES                             printf("YES\n")
#define     Yes                             printf("Yes\n")
#define     NO                              printf("NO\n")
#define     No                              printf("No\n")
#define     nl                              printf("\n")

//extras :

#define     e4                              int main()
#define     checkmate                       return 0;
#define     UNDEFINED                       0x3f
#define     INF                             LLONG_MAX
#define     in_range(i,x,y)                 for(int i=x;i<=y;i++)
#define     in_range_back(i,x,y)            for(int i=y;i>=x;i--)


e4{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int ans=0;
        int zeros=count(all(a),0);
        if(zeros==0)
        {
            sort(all(a));
            in_range(i,0,n-2)
            {
                if(a[i+1]==a[i])
                {
                    ans++;
                    zeros++;
                    break;
                }
            }
            if(zeros==0){
                ans+=2;
                zeros++;
            }
        }
        ans+=(n-zeros);
        cout<<ans<<"\n";
    }
    checkmate
}
