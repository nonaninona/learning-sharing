#include <iostream>

using namespace std;
typedef long long ll;

ll calc(ll A, ll B, ll C)
{
	if (B == 0)
		return 1;
	ll val = calc(A, B / 2, C);
	val = val * val % C;

	//b°¡ Â¦¼ö, È¦¼öÀÎ °æ¿ì ³ª´²¼­ Ã³¸®
	if (B % 2 == 0)
		return val % C;
	else
		return (val * A) % C;
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << calc(A, B, C);
	return 0;
}