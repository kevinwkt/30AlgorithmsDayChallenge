#include <iostream>
#include <stdio.h>

using namespace std;

int max(int a, int b){
  return a>b?a:b;
}

int FindMaxSum(int arr[],int n){
  int exclusive=0;
  int inclusive=arr[0];
  int newex=0;
  for(int i=1;i<n;i++){
    newex=inclusive;
    inclusive=max(inclusive,exclusive+arr[i]);
    exclusive=newex;
  }
  return inclusive;
}

int main(){
  int arr[] = {5, 5, 10, 100, 10, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("%d\n", FindMaxSum(arr, n));
  return 0;
}
