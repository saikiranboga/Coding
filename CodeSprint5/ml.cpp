#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main() {
    
    char s[100000];
    int n;
    gets(s);
    cin >> n;
    char word[10000];

    map<string, string> ans;
    ans["gujarat"] = "place";
    ans["india"] = "place";
    ans["london"] = "place";
    ans["south africa"] ="place";
    ans["british"] = "place";
    ans["africa"]= "place";
    ans["germany"]= "place";
    ans["afghanistan"]= "place";
    ans["soviet union"]= "place";
    ans["soviet"]= "place";
    ans["union"]= "place";
    ans["japan"]= "place";
    
    ans["gandhi"] = "person";
    ans["mohandas"] = "person";
    ans["kasturbai makhanji"] = "person";
    ans["kasturba"] = "person";
    ans["ba"] = "person";
    ans["karamchand"]="person";
    ans["karamchand gandhi"] = "person";
    ans["kasturbai"] = "person";
    ans["makhanji"] = "person";
    ans["mohandas"] = "person";
    ans["bose"] = "person";
    ans["akbar"] = "person";
    ans["shah"] = "person";
    ans["abad"] = "person";
    ans["talwar"] = "person";
    ans["mian"] = "person";

    map<string, string>::iterator it;
    char c;
    getchar();
    for(int i=0;i<n;i++){
        gets(word);
        for(int j = 0; word[j]; j++)
            word[j] = tolower(word[j]);
        it = ans.find(word);
        if(it != ans.end())
            cout << it->second << endl;
        else
            cout << "no match\n";
    }
    return 0;
}