#include <stdio.h>

int fibonacci_iteration(int n)
{
    int prev = 0, curr = 1, temp, i;
    if (n == 0)
        return prev;
    for (i = 2; i <= n; i++)
    {
        temp = prev + curr;
        prev = curr;
        curr = temp;
    }
    return curr;
}

int fibonacci_recursion(int n)
{
    if (n <= 1)
        return n;
    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}

int fibonacci_dp(int n)
{
    int dp[n + 2]; 
    int i;
 
    dp[0] = 0;
    dp[1] = 1;
    for (i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
 
    return dp[n];
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result_iteration = fibonacci_iteration(n);
    int result_recursion = fibonacci_recursion(n);
    int result_dp = fibonacci_dp(n);

    printf("fibbonaci_iteration(%d) = %d\n", n, result_iteration);
    printf("fibbonaci_recursion(%d) = %d\n", n, result_recursion);
    printf("fibbonaci_dp(%d) = %d\n", n, result_dp);

    return 0;
}
