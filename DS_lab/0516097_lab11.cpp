#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a,b,count=1;
	int dp[27][27][352] = {0};	   //   letter length sum 
	dp[0][0][0]=1;					
	for(int i=1; i<27; i++){
		for(int j=0; j<=i; j++){
			for(int k=0; k<352; k++){
				dp[i][j][k] = dp[i-1][j][k];
				if(j>0 && k>=i){
					dp[i][j][k] =  dp[i][j][k] + dp[i-1][j-1][k-i];
				}
			}
		}
	}
	while(cin>>a>>b){
		if(a==0 && b==0){
			break;
		}
		if(a>26 || b>352){  						//不可能出現這種值 輸出 0
			cout<<"Case "<<count<<": "<<0<<endl;
			count++;
		}
		else{
			cout<<"Case "<<count<<": "<<dp[26][a][b]<<endl;
			count++;
		}
	}
	return 0;
}


