#include <stdio.h>
#include <iostream>

using namespace std;

void swap(int* a,int*b){
  int* temp=a;
  a=b;
  b=temp;
}

void dutchNationalFlag(int arr[],int n){
  int firstOne=0;
  int two=n-1;
  for(int i=0;i<n;i++){
    if(arr[i]==1){
    }else if(arr[i]==0){
      swap(arr[i],arr[firstOne]);
      firstOne++;
    }else if(arr[i]==2&&two>i){
      swap(arr[i],arr[two]);
      two--;
      --i;
    }
  }
}

int main(){
  int n=10;
  int arr[]={0,1,1,0,2,1,2,0,0,1};
  dutchNationalFlag(arr,n);
  for(int i=0;i<n;i++) printf("%2d",arr[i]);
  printf("\n");
}
