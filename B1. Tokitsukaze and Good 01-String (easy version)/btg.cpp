#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long ans=0;
		char a,b;
		for(int i=1;i<=n;i+=2)
        {
            cin>>a>>b;
            if(a!=b)
            {
                ans++;
            }
        }
		cout<<ans<<endl;
	}
	return 0;
}
