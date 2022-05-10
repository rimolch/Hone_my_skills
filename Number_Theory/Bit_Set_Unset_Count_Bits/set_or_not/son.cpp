#include<bits/stdc++.h>
using namespace std;
/*void printBinary(int n)
{
    for(int i=10;i>=0;i--)
    {
        cout<<((n>>i)&1);
    }
    cout<<endl;
}*/
int main()
{
    int a = 9;//1 0 0 1
    int is_ith_set_or_not = 0;//first bit from left to right which is 1
    if((a&(1<<is_ith_set_or_not))!=0)//9&1==1
    {
        cout<<"SET BIT"<<endl;//ok
    }
    else
    {
        cout<<"NOT SET BIT"<<endl;
    }
    return 0;
}
