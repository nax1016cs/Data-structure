#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,count=0;
	cin>>n;
	while(count!=n){
		string str;
		cin>>str;
		stringstream ss;
		ss<<str;
		int len = str.size();
		long long int max=1,min=0;
		long long int num[100]={0};
		char ch[100]={' '};
		for(int i =0; i<len; i++){
			ss>>num[i];
			ss>>ch[i];
		}
		for(int i=0; i<len; i++){
			if(ch[i]=='+'){
				num[i+1] = num[i+1] +num[i];
				num[i]=0;
			}
		}
		for(int i=0; i<len; i++){
			if(num[i]>=1 ){
				max*=num[i];
			}
		}
		stringstream aa;
		aa<<str;
		for(int i =0; i<len; i++){
			aa>>num[i];
			aa>>ch[i];
		}
		for(int i=0; i<len; i++){
			if(ch[i]=='*'){
				num[i+1] = num[i+1] *num[i];
				num[i]=0;
			}
		}
		for(int i=0; i<len; i++){
			if(num[i]>=1){
				min+=num[i];
			}
		}
		count++;
		cout<<"The maximum and minimum are "<<max<<" and "<<min<<"."<<endl;
		}

	return 0;
}
