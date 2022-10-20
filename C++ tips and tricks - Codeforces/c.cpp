Lots of programmers write code like this one:
pair<int, int> p;
vector<int> v;
// ...
p = make_pair(3, 4);
v.push_back(4); v.push_back(5);
while you can just do this:
pair<int, int> p;
vector<int> v;
p = {3, 4};
v = {4, 5};
Assign value by a pair of {} to a container

more complex pair
pair<int, pair<char, long long> > p; 
p = {3, {'a', 8ll}};

What about vector, deque, set and other containers?
vector<int> v;
v = {1, 2, 5, 2};
for (auto i: v) 
cout << i << ' ';
cout << '\n';
// prints "1 2 5 2"
deque<vector<pair<int, int>>> d;
d = {{{3, 4}, {5, 6}}, {{1, 2}, {3, 4}}};
for (auto i: d) {
    for (auto j: i)
        cout << j.first << ' ' << j.second << '\n';
    cout << "-\n";
}
// prints "3 4
//         5 6
//         -
//	   1 2
//	   3 4
set<int> s;
s = {4, 6, 2, 7, 4};
for (auto i: s)
    cout << i << ' ';
cout << '\n';
// prints "2 4 6 7"
list<int> l;
l = {5, 6, 9, 1};
for (auto i: l)
    cout << i << ' ';
cout << '\n';
// prints "5 6 9 1"
array<int, 4> a;
a = {5, 8, 9, 2};
for (auto i: a)
    cout << i << ' ';
cout << '\n';
// prints "5 8 9 2"
tuple<int, int, char> t;
t = {3, 4, 'f'};
cout << get<2>(t) << '\n'; //output f

Note that it doesn't work for stack and queue.
Hidden function (not really hidden but not used often)
one)
__gcd(value1, value2
You don't need to code Euclidean Algorithm for a gcd function, from now on we can use. This function returns gcd of two numbers.
e.g. __gcd(18, 27) = 9.
two)
__builtin_ffs(x)
This function returns 1 + least significant 1-bit of x. If x == 0, returns 0. Here x is int, this function with suffix 'l' gets a long argument and with suffix 'll' gets a long long argument.
e.g. __builtin_ffs(10) = 2 because 10 is '...10 1 0' in base 2 and first 1-bit from right is at index 1 (0-based) and function returns 1 + index.
three)
__builtin_clz(x)
This function returns number of leading 0-bits of x which starts from most significant bit position. x is unsigned int and like previous function this function with suffix 'l gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
e.g. __builtin_clz(16) = 27 because 16 is ' ... 10000'. Number of bits in a unsigned int is 32. so function returns 32 — 5 = 27.
four)
__builtin_ctz(x)
This function returns number of trailing 0-bits of x which starts from least significant bit position. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
e.g. __builtin_ctz(16) = 4 because 16 is '...1 0000 '. Number of trailing 0-bits is 4.
five)
__builtin_popcount(x)
This function returns number of 1-bits of x. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
e.g. __builtin_popcount(14) = 3 because 14 is '... 111 0' and has three 1-bits.
Note: There are other __builtin functions too, but they are not as useful as these ones.
Note: Other functions are not unknown to bring them here but if you are interested to work with them, I suggest this website.
Here is C++0x in CF, why still C++?
Variadic functions also belong to C++11 or C++0x, In this section I want to show you some great features of C++11.
one) Range-based For-loop
Here is a piece of an old code:
set<int> s = {8, 2, 3, 1};
for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    cout << *it << ' ';
// prints "1 2 3 8"
Trust me, that's a lot of code for that, just use this:
set<int> s = {8, 2, 3, 1};
for (auto it: s)
    cout << it << ' ';
// prints "1 2 3 8"
We can also change the values just change auto with auto &:
vector<int> v = {8, 2, 3, 1};
for (auto &it: v)
    it *= 2;
for (auto it: v)
    cout << it << ' ';
// prints "16 4 6 2"
two) The Power of auto
You don't need to name the type you want to use, C++11 can infer it for you. If you need to loop over iterators of a set<pair<int, pair<int, int> > > from begin to end, you need to type set<pair<int, pair<int, int> > >::iterator for me it's so suffering! just use auto it = s.begin()
also x.begin() and x.end() now are accessible using begin(x) and end(x).
this code:

for(i = 1; i <= n; i++) {
    for(j = 1; j <= m; j++)
        cout << a[i][j] << " ";
    cout << "\n";
}
is equivalent to this:
for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++)
        cout << a[i][j] << " \n"[j == m];
four) body: contains function bodies, and returns return value.
e.g.
auto f = [] (int a, int b) -> int { return a + b; };
cout << f(1, 2); // prints "3"
You can use lambdas in for_each, sort and many more STL functions:
vector<int> v = {3, 1, 2, 1, 8};
sort(begin(v), end(v), [] (int a, int b) { return a > b; });
for (auto i: v) cout << i << ' ';
Output:
8 3 2 1 
Usage of move:
When you work with STL containers like vector, you can use move function to just move container, not to copy it all.
vector<int> v = {1, 2, 3, 4};
vector<int> w = move(v);
cout << "v: ";
for (auto i: v)
    cout << i << ' ';

cout << "\nw: ";
for (auto i: w)
    cout << i << ' ';
Output:
v: 
w: 1 2 3 4 
As you can see v moved to w and not copied.
all(x)
This may be an exception to the rule of non-popularity -- this is quite widely used, but some next items will depend on all(x), so I define it here. So, I talk about
#define all(x) (x).begin(), (x).end()
Now sorting a vector looks like sort(all(vec)) instead of sort(vec.begin(), vec.end()).
std::unique
This is also well known, but not as well as I want, so I leave it here. std::unique(begin, end) goes from begin to end, removes consecutive duplicates and returns the end of the resulting iterator range. So, for example, if vec = {1, 1, 2, 2, 3, 2, 1}, then unique(all(vec)) makes it equal {1, 2, 3, 2, 1, ?, ?} (where ? is not known, but probably the last two symbols are 2 and 1) and returns vec.begin() + 5. Usually, to make a vector containing only its unique elements, one writes
sort(all(vec));
vec.resize(unique(all(vec)) - vec.begin());

std::fill and std::iota
Many of you know that if one wants to fill a piece of memory with a specific byte, they can use memset. It's quite fast and can be used to fill some (usually 1-dimensional) C-arrays by zeroes and minus ones. What if you want to fill a container by ones? The answer is as easy as pie:
fill(all(vec), 1);
And if you need to fill it by consecutive numbers, you can use std::iota. Now the constructor of a Dsu class with two optimizations may look as follows:
int n;
vector<int> parent, rank;

Dsu(int _n): n(_n), parent(_n), rank(_n) {
    iota(all(parent), 0);
}
Here 0 denotes the value of *parent.begin(), and each next value is obtained from the previous one by the pre-increment.

std::rotate
Assume you write a profile dp. Or a 3-layer bfs. Or something else, where you need sometimes to cyclically shift a vector by kk. If k=1k=1 then one can write a loop of swaps:
for (int i = 0; i < (int)vec.size() - 1; ++i) {
    swap(vec[i], vec[i + 1]);
}
But if k>1k>1 then the easiest way to do this manually is probably to create another vector, fill it accordingly and then set the initial vector to this. However a simple
rotate(vec.begin(), vec.begin() + k, vec.end());
can do the trick. This function works in such a way that after rotate(begin, middle, end) the element *middle becomes the first from begin to end.
Print a binary representation of a number
If you want to print, say, last 20 bits of a number, it's not necessary to write smth like
void show_binary(int n) {
    for (int i = 0; i < 20; ++i) {
        cout << !!(n & (1 << i));
    }
    cout << "\n";
}
Instead, one can simply write
cout << bitset<20>(n) << "\n";
However, you need to fix the number of bits to show (which is usually not a problem because in most of the cases you need it for debug purposes) and get used to the order where the lowest bit is the rightmost (which is actually a natural order for a binary representation of a number, but not so natural if you consider a mask as a sort of a boolean vector).
Also, if you want to print an octal or a hexadecimal representation of a number, you can simply write cout << oct << n << "\n" and cout << hex << n << "\n", respectively. To return back to normal decimal, use cout << dec
Algorithm Library | C++ Magicians STL Algorithm
For all those who aspire to excel in competitive programming, only having a knowledge about containers of STL is of less use till one is not aware what all STL has to offer. 
STL has an ocean of algorithms, for all < algorithm > library functions : Refer here.
Some of the most used algorithms on vectors and most useful one’s in Competitive Programming are mentioned as follows :

Non-Manipulating Algorithms

sort(first_iterator, last_iterator) – To sort the given vector.
sort(first_iterator, last_iterator, greater<int>()) – To sort the given container/vector in descending order
reverse(first_iterator, last_iterator) – To reverse a vector. ( if ascending -> descending  OR  if descending -> ascending)
*max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
*min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements
// A C++ program to demonstrate working of sort(),
// reverse()
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> //For accumulate operation
using namespace std;
int main()
{
    // Initializing vector with array values
    int arr[] = {10, 20, 5, 23 ,42 , 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);
    cout << "Vector is: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";
    // Sorting the Vector in Ascending order
    sort(vect.begin(), vect.end());
    cout << "\nVector after sorting is: ";
    for (int i=0; i<n; i++)
  cout << vect[i] << " ";
      // Sorting the Vector in Descending order
      sort(vect.begin(),vect.end(), greater<int>());
    cout << "\nVector after sorting in Descending order is: ";
    for (int i=0; i<n; i++)
       cout << vect[i] << " ";
    // Reversing the Vector (descending to ascending , ascending to descending)
    reverse(vect.begin(), vect.end());
    cout << "\nVector after reversing is: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";
    cout << "\nMaximum element of vector is: ";
    cout << *max_element(vect.begin(), vect.end());
    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end());
  // Starting the summation from 0
    cout << "\nThe summation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0);
    return 0;
}




Vector is: 10 20 5 23 42 15 
Vector after sorting is: 5 10 15 20 23 42 
Vector after sorting in Descending order is: 42 23 20 15 10 5 
Vector after reversing is: 5 10 15 20 23 42 
Maximum element of vector is: 42
Minimum element of vector is: 5
The summation of vector elements is: 115

6.count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
7. find(first_iterator, last_iterator, x) – Returns an iterator to the first occurrence of x in vector and points to last address of vector ((name_of_vector).end()) if element is not present in vector.
// C++ program to demonstrate working of count()
// and find()
#include <algorithm>		
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Initializing vector with array values
    int arr[] = {10, 20, 5, 23 ,42, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);
    cout << "Occurrences of 20 in vector : ";
    // Counts the occurrences of 20 from 1st to
    // last element
    cout << count(vect.begin(), vect.end(), 20);
    // find() returns iterator to last address if
    // element not present
    find(vect.begin(), vect.end(),5) != vect.end()?
                         cout << "\nElement found":
                     cout << "\nElement not found";
    return 0;
}
Output
Occurrences of 20 in vector : 2
Element found
       8. binary_search(first_iterator, last_iterator, x) – Tests whether x exists in sorted vector or not.
       9. lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which         has a value not less than ‘x’.
       10. upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last)                  which has a value greater than ‘x’. 
// C++ program to demonstrate working of lower_bound()
// and upper_bound().
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
 

int main()
{

    // Initializing vector with array values

    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};

    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> vect(arr, arr+n);
 

    // Sort the array to make sure that lower_bound()

    // and upper_bound() work.

    sort(vect.begin(), vect.end());
    // Returns the first occurrence of 20
    auto q = lower_bound(vect.begin(), vect.end(), 20);
    // Returns the last occurrence of 20
    auto p = upper_bound(vect.begin(), vect.end(), 20);
    cout << "The lower bound is at position: ";
    cout << q-vect.begin() << endl;
    cout << "The upper bound is at position: ";
    cout << p-vect.begin() << endl;
    return 0;
}
Output
The lower bound is at position: 3
The upper bound is at position: 5
Some Manipulating Algorithms
arr.erase(position to be deleted) – This erases selected element in vector and shifts and resizes the vector elements accordingly.
arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line.
Output

Vector is :  5 10 15 20 20 23 42 45
Vector after erasing the element: 5 15 20 20 23 42 45
Vector before removing duplicate  occurrences: 5 15 20 20 23 42 45
Vector after deleting duplicates: 5 15 20 23 42 45

  3. next_permutation(first_iterator, last_iterator) – This modified the vector to its next permutation.
   4. prev_permutation(first_iterator, last_iterator) – This modified the vector to its previous permutation. 
// C++ program to demonstrate working 
// of next_permutation()
// and prev_permutation()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Initializing vector with array values
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);
 
    cout << "Given Vector is:\n";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";
    // modifies vector to its next permutation order
    next_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing 
                   next permutation:\n";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";
    prev_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing prev 
                               permutation:\n";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";
    return 0;
}
5. distance(first_iterator,desired_position) – It returns the distance of desired position from the first iterator.This function               is very useful while finding the index. 
// C++ program to demonstrate working of distance()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Initializing vector with array values
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);
    // Return distance of first to maximum element
    cout << "Distance between first to max element: "; 
    cout << distance(vect.begin(),
                     max_element(vect.begin(), vect.end()));
    return 0;
}
Output
Distance between first to max element: 7
Swapping of 2 numbers using XOR: This method is fast and doesn’t require the use of 3rd variable. 
CP Swapping of 2 numbers using XOR: This method is fast and doesn’t require the use of 3rd variable. 

// A quick way to swap a and b
a ^= b;
b ^= a;
a ^= b;P
// A quick way to swap a and b
a ^= b;
b ^= a;
a ^= b;

