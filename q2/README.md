## Fibonacci number

We can use three approach, which are iterative, recursive and dynamic programming.

1. Iterative Approach
```c
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
```

**Advantages**:

* Efficient and fast execution for large values of n.
* Uses constant space as it doesn't require additional function calls.

**Disadvantages**:
* The code may hard to understand due to variables and calculations.

2. Recursive Approach
```c
int fibonacci_recursion(int n)
{
    if (n <= 1)
        return n;
    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}
```
**Advantages**:

* Simple and straightforward implementation.
* Reflects the mathematical definition of the Fibonacci series.

**Disadvantages**:
* Exponential time complexity, slow execution for larger values of n.
* Recalculates the same Fibonacci values multiple times, redundant computations.


3. Dynamic Programming Approach
```c
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
```
**Advantages**:
* Efficient computation of Fibonacci values.
* Avoids redundant calculations by storing previously computed values.


**Disadvantages**:
* Requires additional space to store the Fibonacci array.


### Comparison Table

| Aspect                  | Iterative                                                | Recursive                                               | Dynamic Programming                                             |
|-------------------------|----------------------------------------------------------|---------------------------------------------------------|-----------------------------------------------------------------|
| Coding Logic            | Uses a loop and variables to calculate Fibonacci values iteratively | Calls itself recursively to calculate Fibonacci values | Uses an array to store previously calculated Fibonacci values and computes the current value based on stored values |
| Store Intermediate Results | No                                                       | No                                                      | Yes                                                             |
| Procedure Plot          | Sequential                                               | Tree-like                                               | Sequential                                                      |
| Time Complexity         | O(n)                                                     | O(2^n)                                                  | O(n)                                                            |
| Space Complexity        | O(1)                                                     | O(n)                                                    | O(n)                                                            |
| Advantages              | - Efficient for large values of n                        | - Reflects mathematical definition of Fibonacci series<br>- Simple implementation | - Efficient computation<br>- Avoids redundant calculations through stored values |
| Disadvantages           | - Code complexity due to multiple variables and calculations | - Exponential time complexity for larger values of n<br>- Redundant computations for the same Fibonacci values | - Additional space required to store intermediate results |                                                                 |

## Development Environment:

    Compiler: GCC (GNU Compiler Collection)
    Operating System: Windows 10

### Steps to Compile and Run the Source Code:
1. Compile the code using the GCC compiler with the following command:
```bash
gcc -o q2 q2.c
```
This command will generate an executable file named "q2.exe" in the same directory.

2. Run the program by executing the following command:

```bash
./q2
```
The program will prompt you to enter the value of n.
Enter a non-negative integer value for n and press Enter.
The program will calculate and display the Fibonacci value for the given input.

*Note: Make sure you have GCC installed on your system and added to the system's PATH environment variable to successfully compile and run the C code.*
