#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*		北2
	西4	上1	  東3
		下6
		南5*/
int main(int argc, char** argv) {
	
	int a;
	while(cin>>a!=0){
		if(a==0){
			break;
		}
		int top = 1;
		int north = 2;
		int west = 3;
		while(a){
			string str1;
			cin>>str1;				
			if(str1=="north"){
				int temp = top;
				top = 7-north;
				north = temp;
				--a;				
				}
			else if(str1=="south"){
				int temp = top;
				top = north;
				north = 7 - temp;
				--a;					
			}
			else if(str1=="east"){
				int temp = top;
				top = west;
				west = 7 - temp;
				--a;					
			}
			else if(str1=="west"){
				int temp = top;
				top = 7 - west;
				west = temp;	
				--a;
			}
	}
	cout<<top<<endl;
	}

	return 0;
}
