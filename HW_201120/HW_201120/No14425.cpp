#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count = 0;
int N, M;
vector<string> T;
vector<string> P;

vector<int> getPi(string pattern) {
	int patternSize = pattern.size();
	int j = 0;
	vector<int> pi(patternSize, 0);

	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];

		if (pattern[i] == pattern[j]) pi[i] = ++j;
	}

	return pi;
}

void KMP(string parent, string pattern) {
	vector<int> ans;

	auto pi = getPi(pattern);

	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;

	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j])
			j = pi[j - 1];

		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				::count++;
				j = pi[j];
			}
			else j++;
		}
	}
}

int main() {
	cin >> N >> M;

	T.resize(N + 1);
	P.resize(M + 1);

	for (int i = 1; i <= N; i++)
		getline(cin, T[i]);

	for (int i = 1; i <= M; i++) {
		getline(cin, P[i]);
		for (int j = 1; j <= N; j++)
			KMP(T[j], P[i]);
	}

	cout << ::count;
} // KMP ·Î Ç®¸é time out !!!!!!!!!!