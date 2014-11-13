#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std; 
#define MOD 1000000009
// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(string str, string sub)
{
  if (sub.length() == 0) return 0;
  int count = 0;
  //here int can also be used in place of size_t but size_t gives the location of substring in bytes
  //we can also compare offset against -1 because string::npos is nothing but a size_t static const with value -1
  //str.find has 2nd arguement as start of index in string from which to start searc
  for (size_t offset = str.find(sub); offset != string::npos; offset = str.find(sub, offset + sub.length()))
    {
      ++count;
    }
  while(count>=MOD)
    count-=MOD;
  return count;
}
 
int main()
{
  int w,n,i;
  vector<string> words;
  string word,song;
  scanf("%d",&w);
  while(w--)
    {
      //scanf("%s",word);
      cin >> word;
      words.push_back(word);
    } 
  //  scanf("%d",&n);
  cin >> n;
  n++;
  while(n--)
    {
      getline(cin,word);
      song+=word;
    }            
  for(i=0;i<words.size();i++)
    printf("%d\n",countSubstring(song,words[i]));

  return 0;
}
