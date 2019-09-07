#include <iostream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int array[10000];
	long long int n, i=0;
	while(cin >>n ){
		array[i] = n;
		sort(array,array+i+1);
		int *ptr1 = array;
		int *ptr2 = array + i;
		for(ptr1,ptr2; ; ptr1++,ptr2--){
			if(ptr1==ptr2){
				cout<<*ptr1<<endl;
				i++;
				break;
			}
			if((ptr2-ptr1)==1){
				cout << (*ptr1 + *ptr2)/2<<endl;
				i++;
				break;
			}
		}
	}
	return 0;
}
