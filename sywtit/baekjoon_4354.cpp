#include<iostream>
#include<string>
#include<vector>
using namespace std;

int kmp(string target)
{
	int j = 0;
	
	vector<int> fail(target.size(), 0);

	for (int i = 1; i < target.size(); i++)
	{
		while (j > 0 && target[i] != target[j])
			j = fail[j-1];

		if (target[i] == target[j])
			fail[i] = ++j;
	}

	return fail[target.size()-1];
	
}

int main()
{
	//문제의 요지 : 반복되는 문자열의 최대 길이
	//lcs
	string p = "";

	for (int i = 0; i < 10; i++)
	{
		p = "";
		getline(cin, p);

		if (p==".") return 0;
		cout << kmp(p);
	}

	return 0;
}