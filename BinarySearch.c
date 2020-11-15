#include <stdio.h>
int myAlgorithm4(int n,int *val,int key)
{
int low=0,high=n-1;
while(low<=high)
{
int mid=(low+high)/2;
if(key>val[mid]) low=mid+1;
if(key<val[mid]) high=mid-1;
if(key==val[mid]) return 1;
}
return 0;
}



int main(void) {
  int arr[11] = {
    1,5,9,12,43,56,66,79,81,97,100
  };

int t = myAlgorithm4(11, arr,56);
if(t)
  printf("Found");
else
  printf("Not found");

  return 0;
}
