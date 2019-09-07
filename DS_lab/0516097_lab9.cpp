#include <algorithm> 
#include <stdio.h>
using namespace std;  
const int maxn = 301;    
  
char s[20];  
long long dp[maxn][maxn];  
  
int main()  
{  
    int n, L1, L2;  
    dp[0][0] = 1;  
    for (int i = 0; i < maxn; ++i)  
    {  
        for (int j = 1; j < maxn; ++j)  
        {  
            if (j <= i) dp[i][j] = dp[i - j][j] + dp[i][j - 1];  
            else dp[i][j] = dp[i][j - 1];  
        }  
    }  
    while (gets(s))  
    {  
        L1 = L2 = -1;  
        sscanf(s, "%d%d%d", &n, &L1, &L2);  
        L1 = min(L1, 300), L2 = min(L2, 300);  
        if (L1 == -1) printf("%lld\n", dp[n][n]);  
        else if (L2 == -1) printf("%lld\n", dp[n][L1]);  
        else  
        {  
            if (L1 < 2) printf("%lld\n", dp[n][L2]);  
            else printf("%lld\n", dp[n][L2] - dp[n][L1 - 1]);  
        }  
    }  
    return 0;  
}  
