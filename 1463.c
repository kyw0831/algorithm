#include <iostream>
#include <algorithm>
using namespace std;
 
int dp[1000001]{ 0 };
int main()
{
    int N;

    scanf("%d", &N);
 
    dp[1] = 0;
    for (int n = 2; n <= N; n++) {
        dp[n] = dp[n - 1] + 1;
        if (n % 3 == 0)
            dp[n] = min(dp[n], dp[n / 3] + 1);
        else if (n % 2 == 0)
            dp[n] = min(dp[n], dp[n / 2] + 1);
    }
 
    printf("%d\n", dp[N]);
 
    return 0;
}
