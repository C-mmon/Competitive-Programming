// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost
int minCost(string s)
{
	int n = s.length();
	int count0 = 0;
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			count0++;
	}
	vector<int> prefixCountZero(n, 0);
	vector<int> suffixCountZero(n, 0);

	// Loop to find the prefix count of 0
	for (int i = 0; i < n; i++) {
		if (i != 0)
			prefixCountZero[i] = prefixCountZero[i - 1];
		if (s[i] == '0')
			prefixCountZero[i]++;
	}

	// Loop to find the suffix count of 0
	for (int i = n - 1; i >= 0; i--) {
		if (i != n - 1)
			suffixCountZero[i] = suffixCountZero[i + 1];
		if (s[i] == '0')
			suffixCountZero[i]++;
	}

	// Loop to find the minimum cost
	for (int i = 0; i <= count0; i++) {
		int x;
		if (i == 0) {
			x = count0 - suffixCountZero[n - count0];
		}
		else if (i == count0) {
			x = count0 - prefixCountZero[count0 - 1];
		}
		else {
			x = count0 - prefixCountZero[i - 1]
				- suffixCountZero[n - (count0 - i)];
		}
		ans = min(ans, x);
	}
	return ans;
}

// Driver code
int main()
{

	string S = "101110110";

	// Function call
	cout << minCost(S);
	return 0;
}
