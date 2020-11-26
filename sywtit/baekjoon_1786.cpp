#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main_1786()
{
	string T, P;
	getline(cin, T);
	getline(cin, P);


	//find LCS in p
	vector<int> p_lcs(P.size(),0);
	int j = 0;
	
	for (int i = 1; i < P.size(); i++)
	{
		//hardly pass out the middle process by using lcs
		while (j > 0 && P[i] != P[j])
			j = p_lcs[j - 1];
		if (P[i] == P[j])
			p_lcs[i] = ++j;
	}

	//kmp
	vector<int> kmp;
	j = 0;

	for (int i = 0; i < T.size(); i++)
	{
		while (j > 0 && T[i] != P[j])
			j = p_lcs[j - 1];
		if (T[i] == P[j])
		{
			if (j == P.size() - 1)
			{
				kmp.push_back(i - P.size() + 2);
				j = p_lcs[j];
			}
			else
			{
				j++;
			}
		}
	}

	cout << kmp.size()<<endl;

	for (int i = 0; i < kmp.size(); i++)
	{
		cout << kmp[i] << " ";
	}

	return 0;
}