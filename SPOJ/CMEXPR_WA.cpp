#include <iostream>
#include <map>
#include <cstring>
using namespace std;

#ifndef pb
#define pb push_back
#endif

int main(){

	map<char, int> priority;
	priority['+'] = 1;
	priority['-'] = 1;
	priority['*'] = 2;
	priority['/'] = 2;

	int t;
	cin >> t;
	while(t--){
		string ex;
		cin >> ex;

		int rmv[ex.size()];
		memset(rmv,0,sizeof(rmv));

		int cur_brkt;
		for(cur_brkt=0; cur_brkt<ex.size(); cur_brkt++){
			
			while(cur_brkt<ex.size() && ex[cur_brkt]!='(') cur_brkt++;
			if(cur_brkt>=ex.size())
				break;

			int L_prio = 0, R_prio = 0;
			int L_idx = -1, R_idx = -1;

			bool is_left_a_minus = false;
			bool is_left_a_div = false;

			L_idx = cur_brkt;

			if(cur_brkt>0){
				L_prio = priority[ex[cur_brkt-1]];
				if(ex[cur_brkt-1]=='-')
					is_left_a_minus = true;
				else if(ex[cur_brkt-1]=='/')
					is_left_a_div = true;
			}

			int left_count = 1; // left brackets count
			int idx = cur_brkt+1;
			int inner_min = 0;

			//cout << "processing...\n";
			//cout << "Left index: " << L_idx << " Left prio: " << L_prio << endl;

			while(left_count!=0){
				
				if( ex[idx]=='+' || ex[idx]=='-' || ex[idx]=='*' || ex[idx]=='/'){
					if(inner_min==0 || priority[ex[idx]]<inner_min)
						inner_min = priority[ex[idx]];
				}

				if(ex[idx]==')'){
					left_count--;
				}

				if(ex[idx]=='('){
					int prev_left_count = left_count;
					left_count++;
					idx++;
					while(prev_left_count != left_count){
						if(ex[idx]=='(')
							left_count++;
						else if(ex[idx]==')')
							left_count--;
						idx++;
					}
					idx--;
				}

				idx++;
			}

			//cout << "Inner Min Prio: " << inner_min << endl;

			R_idx = idx-1;
			if(idx!=ex.size()){
				R_prio = priority[ex[idx]];
			}

			//cout << "Right index: " << R_idx << " Right prio: " << R_prio << endl;

			bool rmv_brks = true;

			switch(inner_min){
				case 1:
					if(is_left_a_minus || L_prio==2 || R_prio==2)
						rmv_brks = false;
					break;
				case 2:
					if(is_left_a_div)
						rmv_brks = false;
					break;
				default:
					break;
			}

			if(rmv_brks==true){
				rmv[L_idx] = 1;
				rmv[R_idx] = 1;
			}
		}

		for(int i=0;i<ex.size();i++){
			if(rmv[i]==0){
				cout << ex[i];
			}
		}
		cout << endl;
	}
	return 0;
}