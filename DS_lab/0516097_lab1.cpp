#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int n;
	while(cin>>n && n!=0){
		while(n/10){
			n = n/10 + n%10;
		}
		cout<<n<<endl;
	}
	return 0;
}
