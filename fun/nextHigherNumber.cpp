#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(string &s, int a, int b){
  char temp=s[a];
  s[a]=s[b];
  s[b]=temp;
}

string nextHigherNumber(string s){
  bool ascend=true;
  int d=0;
  for(int i=s.length()-1;i>0;i--){
    if(s[i]>s[i-1]){
      ascend=false;
      d=i;
    }
  }
  if(ascend) return s.append(" is already MAX");
  else{
    int minDif=1234567890;
    int minIndex=-1;
    for(int i=d+1;i<s.length();i++) if((s[i]>s[d])&&(s[i]-s[d])<minDif) {minDif=s[i]-s[d]; minIndex=i;}
    swap(s,d,minIndex);
    sort(s.begin()+d+1,s.end());
    // for(int i=d+1;i<((s.length()-d)/2)+1;i++) swap(s,i,s.length()-i-1);
  }
  return s;
}

int main(){

  string str="34283";
  printf("%s\n",nextHigherNumber(str).c_str());

}
