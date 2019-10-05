#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))  
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y)) 

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int* a;
int* b;
int* diff;
int* dp;
int result;

int sum_of_a() {
	int result = 0;
	for (int i = 0; i < N; i++)
		result += a[i];
	return result;
}

int sum_of_b() {
	int result = 0;
	for (int i = 0; i < N; i++)
		result += b[i];
	return result;
}

int main() {
	cin >> N;
	a = (int*)malloc(sizeof(int) * N);
	b = (int*)malloc(sizeof(int) * N);
	diff = (int*)malloc(sizeof(int) * N);
	dp = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		cin >> a[i] >> b[i];
	for (int i = 0; i < N; i++)
		diff[i] = a[i] - b[i];

	//	sort(diff,diff+N, greater<int>());

	int a_result = sum_of_a();
	int b_result = 0;

	for (int i = 0; i < N; i++) {
		if (a[i] > b[i]) {
			a_result -= a[i];
			b_result += b[i];
		}
		dp[i] = MAX(a_result, b_result);
	}

	for (int i = 0; i < N; i++)
		cout << dp[i] << endl;

	//	cout << *min_element(dp, dp + N) <<endl;
}