#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a;
	int count =0;
	cin >> a;
	while(count!=a){
		int b;
		cin >> b;
		int array[b];
		for(int i=0; i<b; i++){
			cin >> array[i];
		}
		int high_jump =0;
		int low_jump = 0;
		for(int i=0; i<b-1; i++){
			if(array[i]>array[i+1]){
				low_jump++;
			}
			if(array[i]<array[i+1]){
				high_jump++;
			}
		}
		count++;
		cout<< "Case "<< count <<": "<< high_jump <<" "<<low_jump<<endl;
	}
	return 0;
}
