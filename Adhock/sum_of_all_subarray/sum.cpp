#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int ar[n];
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=(i*(n-i+1))*ar[i];
	}
	cout<<sum<<endl;
	return 0;
}
