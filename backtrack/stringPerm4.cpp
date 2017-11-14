#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#define fors(i,a,b) for(__typeof(b) i=a;i<b;i++)
#define iter(it, mp) for(__typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)

using namespace std;

void permuteUtil(string str,char c[],int count[],int size,vector<string> &v,int level){

  if(level==str.length()) v.push_back(str);
  else{
    for(int i=0;i<size;i++){
      if(count[i]==0) continue;
      str[level]=c[i];
      count[i]--;
      permuteUtil(str,c,count,size,v,level+1);
      count[i]++;
    }
  }
}

void permute(string str, vector<string> &v){
  map<char,int> mp;
  fors(i,0,str.length()){
    if(mp.find(str[i])==mp.end()){
      mp[str[i]]=1;
    }else{
      mp[str[i]]++;
    }
  }

  char c[mp.size()];
  int count[mp.size()];

  int i=0;
  iter(it,mp){
    c[i]=it->first;
    count[i]=it->second;
    i++;
  }

  permuteUtil(str,c,count,mp.size(),v,0);

}

int main(){
  string str="abs";
  vector<string> v;
  permute(str,v);
  iter(it,v) printf("%s\n",it->c_str());
}
