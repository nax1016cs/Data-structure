#include <iostream> 
using namespace std; 
int main () 
{ 
	int a, b, count;
	count=1;
	while(cin>>a>>b)
	{
		if(a==0 && b==0){
			break;
		}
		if (count!=1){
			cout<<endl;
		}
		char mine[a+2][b+2];
		for (int i = 1; i <= a; ++i)
		{
			for (int j = 1; j <= b; ++j)
			{
				cin>>mine[i][j];
			}
		}
		for (int i = 1; i <= a; ++i)
		{
			for (int j = 1; j <= b; ++j)
			{
				if(mine[i][j]=='.'){
					mine[i][j]='0';
				}
			}
		}	
		for (int i = 1; i <= a; ++i)
		{
			for (int j = 1; j <= b; ++j)
			{
				if(mine[i][j]=='*'){
					if(mine[i-1][j]!='*')mine[i-1][j]++;
					if(mine[i-1][j-1]!='*')mine[i-1][j-1]++;
					if(mine[i-1][j+1]!='*')mine[i-1][j+1]++;
					if(mine[i][j-1]!='*')mine[i][j-1]++;
					if(mine[i][j+1]!='*')mine[i][j+1]++;
					if(mine[i+1][j]!='*')mine[i+1][j]++;
					if(mine[i+1][j-1]!='*')mine[i+1][j-1]++;
					if(mine[i+1][j+1]!='*')mine[i+1][j+1]++;
				}
			}
		}
		cout<<"Field #"<<count<<":"<<endl;
		for (int i = 1; i <= a; ++i)
		{
			for (int j = 1; j <= b; ++j)
			{
				cout<<mine[i][j];
			}
			cout<<endl;
		}	
		count++;			
	}
}