```
For example........
       array 3 2 4 1
   subarray : 
           3         2         4        1      3+2+4+1=10
           3,2       2,4       4,1             3+2+2+4+4+1=16
           3,2,4     2,4,1                     3+2+4+2+4+1=16
           3,2,4,1                             3+2+4+1=10
   here every index performs i*(n-i+1) multiply with ar[i],where n be the lenght of the array;
   sum of all subarray will be 52
```
