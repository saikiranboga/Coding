/*
ID: saikira2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MOD 47

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    fin >> comet >> group;
    int val1 = 1;
    for(int i=0;i<comet.size();i++)
    	val1 = (val1*(comet[i]-'A'+1))%MOD;
    int val2 = 1;
    for(int i=0;i<group.size();i++)
    	val2 = (val2*(group[i]-'A'+1))%MOD;

    if(val1 == val2)
    	fout << "GO\n";
    else
    	fout << "STAY\n";

    return 0;
}