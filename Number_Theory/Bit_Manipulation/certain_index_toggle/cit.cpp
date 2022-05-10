#include<bits/stdc++.h>
using namespace std;
void printBinary(int n)
{
    for(int i=10;i>=0;i--)
    {
        cout<<((n>>i)&1);
    }
    cout<<endl;
}
int main()
{
   int a=9;//00000001001
   printBinary(a);
   printBinary(a^(1<<2));// wanting 3rd(from index 0) bit toggle
    return 0;
}
/*output:00000001001
  output:00000001101
  */
