#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Add(vector<int>& a, vector<int>& b)
{
	vector<int> c;
	int t = 0;
	if (a.size() < b.size()) return Add(b, a);

	for (int i = 0; i < a.size(); i++)
	{
		t += a[i];
		if (i < b.size())
			t += b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if (t)
		c.push_back(t);
	return c;
}

int main()
{
	string A, B;
	cin >> A >> B;
	vector<int> a, b;
	for (int i = A.size() - 1; i >= 0; i--) a.push_back(A[i]-'0');
	for (int i = B.size() - 1; i >= 0; i--) b.push_back(B[i]-'0');
	auto c = Add(a, b);
	for (int i = c.size() - 1; i >= 0; i--) cout << c[i];

	return 0;
}