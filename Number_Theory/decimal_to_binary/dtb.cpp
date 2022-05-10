/* (n>>i) tends to n/2^i
   (n<<i) tends to n*2^i
*/

#include<bits/stdc++.h>
using namespace std;
void printBinary(int n)
{
    for(int i=10;i>=0;i--)// i = 10 (max range decimal number)
    {
        cout<<((n>>i)&1);
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    printBinary(n);
    return 0;
}
