#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans1=0,ans2=0;
        string s;
        char ch='*';//we can take any character here
        cin>>n>>s;
        for(int i=0;i<n;i+=2)
        {
            if(s[i]!=s[i+1])
            {
                ans1++;
            }
            else if(ch!=s[i])
            {
                 ch=s[i];
                 ans2++;
            }
        }
        cout<<ans1<<" "<<max(1,ans2)<<"\n";
    }
    return 0;
}
