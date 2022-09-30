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
	vector<int>ar(n);
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar.begin(),ar.end());
	int c=0;
	while(next_permutation(ar.begin(),ar.end())){
		for(int i=0;i<n;i++){
			cout<<ar[i];
		}
		c++;
		cout<<endl;
	}
	cout<<c<<endl;
	return 0;
}
// for string 
/*
string s;
	cin>>s;
	while(next_permutation(s.begin(),s.end())){
		cout<<s<<endl;
	}
*/
