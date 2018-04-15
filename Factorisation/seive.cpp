#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+7;
int spf[N];

void seive()
{
	for(int i = 1; i < N; i+=2)
		spf[i] = i;
	for(int i = 2; i < N; i+=2)
		spf[i] = 2;
	for(int i = 1; i*i < N; i++)
	{
		if(spf[i] == i)
		for(int j = i * i; j < N; j += i)
			if(spf[j] == j)
				spf[j] = i;
	}
}

vector<int> calc(int no)
{
	vector<int> ans;
	while(no != 1)
	{
		ans.push_back(spf[no]);
		no = no / spf[no];
	}
	return ans;
}

int main()
{
	seive();
	vector <int> temp;
	temp = calc(10);
	for(vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		cout << *it <<' ';
	}
	cout <<'\n';
	temp = calc(20);
	for(vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		cout << *it <<' ';
	}
	cout <<'\n';
}
