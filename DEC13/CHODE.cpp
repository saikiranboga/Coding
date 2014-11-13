#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

typedef struct Node{
  int chr;
  int freq;
}Node;

int compare(const void *a, const void *b){

  int diff = (*(Node*)(a)).freq - (*(Node*)(b)).freq;
  if(diff == 0)
    return (*(Node*)(a)).chr - (*(Node*)(b)).chr;
  else
    return diff;

}

int main(){
  int t;
  cin >> t;
  while(t--){
    int freq[26];
    char c;
    for(int i=0;i<26;i++){
      cin >> c;
      freq[i] = (int)(c-'a');
    }
    getchar();
    char s[150000];
    gets(s);
    //    puts(s);

    Node cipher_freq[26];
    for(int i=0;i<26;i++){
      cipher_freq[i].freq = 0;
      cipher_freq[i].chr = i;
    }
    //    for(int i=0;i<s.length();i++){
    int ii = 0;
    while(s[ii] != '\0'){
      int id = s[ii]-'a';
      if(id >=0 && id < 26){
	cipher_freq[id].freq++;
      }
      else if(id >= -32 && id<=-7){
	cipher_freq[id+32].freq++;
      }
      ii++;
    }
    /*
    for(int i=0;i<26;i++){
      cout << char('a'+cipher_freq[i].chr) << " " << cipher_freq[i].freq << "\t";
    }
    
    */
    //    quickSort(cipher_freq, 0, 25);
    qsort(cipher_freq, 26, sizeof(cipher_freq[0]), compare);

    int replace[26];

    for(int i=25; i>=0; i--){
      replace[cipher_freq[i].chr] = freq[i];
    }

    /*    
    cout << endl;
    for(int i=0;i<26;i++){
      cout << char('a'+cipher_freq[i].chr) << " " << cipher_freq[i].freq << "\t";
    }

    cout << endl;
    for(int i=0;i<26;i++){
      cout << char('a'+i) << ":" << char(replace[i]+'a') << "\t";
    }
    */    

    //    for(int i=0;i<s.length();i++){
    int ij = 0;
    while(s[ij] != '\0'){
      int id = s[ij]-'a';
      if(id>=0 && id<26){
	cout << char('a'+replace[id]);
      }
      else if(id >= -32 && id<=-7){
	cout << char(replace[id+32]-32+'a');
      }
      else
	cout << s[ij];
      ij++;
    }
    cout << endl;


  }
  return 0;
}
