#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;	
	while(T--){
		string s;
		cin >> s;
		if( s.find("101") != std::string::npos )
			cout << "Good\n";
		else if ( s.find("010") != std::string::npos )
			cout << "Good\n";
		else
			cout << "Bad\n";
	}
	return 0;
}