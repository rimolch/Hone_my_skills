#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll>ar(n);
	vector<ll>prefix(n);
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	prefix[0]=ar[0];
	for(int i=1;i<n;i++){
		prefix[i]=prefix[i-1]+ar[i];
	}
	ll q;
	cin>>q;
	while(q--){
		ll l,r;
		cin>>l>>r;
		if(l==0)cout<<prefix[r]<<endl;
		else cout<<prefix[r]-prefix[l-1]<<endl;
	}
	return 0;
}
