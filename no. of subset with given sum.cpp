#include<iostream>
#include<cstring>
using namespace std;

// int dp[1000][10000];

// int CountRecursively(int arr[] , int n , int sum) {
// 	if (sum == 0) {
// 		return 1;
// 	}
// 	if (n == 0)
// 		return 0;

// 	if (dp[n][sum] != -1)
// 		return dp[n][sum];

// 	if (arr[n - 1] <= sum) {
// 		return dp[n][sum] = CountRecursively(arr , n - 1 , sum - arr[n - 1] ) +
// 		                    CountRecursively(arr , n - 1 , sum);
// 	}
// 	else
// 		return dp[n][sum] = CountRecursively(arr , n - 1 , sum);
// }


int CountIteratively(int arr[] , int n , int sum) {
	int dp[n + 1][sum + 1];

	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j <= sum ; j++) {
			if (i == 0)
				dp[i][j] = 0;
			if (j == 0)
				dp[i][j] = 1;
		}
	}

	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= sum ; j++) {
			if (arr[i - 1] <= sum) {
				dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][sum];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	//memset(dp , -1 , sizeof(dp));

	int n , sum;
	cin >> n >> sum;

	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i] ;
	}

	// cout << "Number of Subsets with Given Sum -> " << CountRecursively(arr , n , sum) ;

	cout << "Number of Subsets with Given Sum -> " << CountIteratively(arr , n , sum);



	return 0;
}
