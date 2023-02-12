#include <stdio.h>
#include <stdlib.h>

int fib(int n, int dp[]) {
  
  if (dp[n] != -1) {
    return dp[n];
  }

  if (n <= 1) {
    dp[n] = n;
    return n;
  }
  
  dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
  return dp[n];
}

int fibonacci(int n) {
  
  int dp[n + 1];

  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  return fib(n, dp);
}

int main() {

  int n;

  printf("\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
  printf("Enter Fibonacci Position: ");
  scanf("%d", &n);
  printf("\nThe %dth Fibonacci number is: %d ", n, fibonacci(n));
  printf("\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");

  return 0;
}