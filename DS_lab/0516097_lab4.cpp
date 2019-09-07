#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long int n , x=1 , b;
	cin>>n;
	for(int k=1; k<=n; k++){
		char A,B;
		while(cin>> A >>B >>b){
		bool is_symmetric=true;
		
		long long int a[b][b];
		
		int i,j;
		
		for(i=0; i<b; i++){
			for(j=0; j<b; j++){
				cin>>a[i][j];
			}
		}
		for( i=0; i<b; i++){
			for(j=0; j<b;j++){
				if(a[i][j]!=a[b-i-1][b-j-1] || a[i][j]<0){
					is_symmetric=false;
				}
			}
		}
		if(is_symmetric){
			cout<<"Test #"<<x<<": "<<"Symmetric."<<endl;
		}
		else if(!is_symmetric){
			cout<<"Test #"<<x<<": "<<"Non-symmetric."<<endl;
		}
		
		x++;
		break;

		
		}
	}


	
	return 0;
}
