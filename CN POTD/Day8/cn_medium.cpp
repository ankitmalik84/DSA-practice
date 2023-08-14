#include <bits/stdc++.h> 
vector<string> divideString(string &word, int n) {
  int len=word.length();
  vector<string> ans;

  if(len<n || len%n!=0) return ans;
  string temp;
  // size of parts
  int j=len/n;

  for(int i=0;i<len;i++){
    temp+=word[i];
    
    if(temp.length()==j){
      ans.push_back(temp);
      temp="";
    }
  }
  return ans;
}