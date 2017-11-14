#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

#define fors(i,a,b) for(__typeof(b) i=a;i<b;i++)
#define trav(it,mp) for(__typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)

using namespace std;

void permuteUtil(string str, char c[], int count[], int size, vector<string> &v,int level){
  if(level==str.length()) v.push_back(str);
  else{
    fors(i,0,size){
      if(count[i]==0) continue;
      str[level]=c[i];
      count[i]--;
      permuteUtil(str,c,count,size,v,level+1);
      count[i]++;
    }
  }
}

void permute(string str,vector<string> &v){
  map<char,int> mp;
  fors(i,0,str.length()){
    if(mp.find(str[i])==mp.end()) mp[str[i]]=1;
    else mp[str[i]]++;
  }

  char c[mp.size()];
  int count[mp.size()];

  int i=0;
  trav(it,mp){
    c[i]=it->first;
    count[i]=it->second;
    i++;
  }

  permuteUtil(str,c,count,mp.size(),v,0);
}

int main(){
  string str="aaa";
  vector<string> ans;
  permute(str,ans);
  trav(it,ans) printf("%s\n",it->c_str());
}
