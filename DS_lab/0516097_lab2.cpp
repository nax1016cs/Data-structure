#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#include <math.h>
int main(int argc, char** argv) {
	int a, b;
	while(cin>> a!=0 && cin >> b!=0){
		if(a==0 &&b==0){
			break;
		}
		int c,d,e;
		c = int(sqrt(b)) - int(sqrt(a));
		d = int(sqrt(a))-sqrt(a);
		e = int(sqrt(b))-sqrt(b);
		if(d==0){
			c++;
		}		
		if(e==0){
			c++;
		}
		if(d==0 && e==0){
			c--;
		}
		cout<< c <<endl;
	}
	return 0;
}
