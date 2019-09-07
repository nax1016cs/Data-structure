#include <iostream>
#include <iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Fib[5001][500]={0};
int main(int argc, char** argv) {
int n;
   Fib[1][0]=1;
    for (int i=2; i<=5000; i++){
        for (int j=0; j<500; j++){
            Fib[i][j] += Fib[i-1][j]+Fib[i-2][j];
            if (Fib[i][j]>=1000){
                Fib[i][j] -= 1000;
                Fib[i][j+1]++;
            }
        }
    }
	while(cin>>n  ){
		int x=500;
		if(!n){
			cout<<"The Fibonacci number for " << n << " is " <<0<<endl;
		}
		else{
			while(Fib[n][--x]==0);
			cout<< "The Fibonacci number for " << n << " is " ;
            cout<<Fib[n][x--];			
			for(; x>=0; x--){
				cout<<setfill('0')<<setw(3)<<Fib[n][x];
			}
			cout<<endl;
		}
	}
	return 0;
}
