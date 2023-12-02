#include <fstream>
#define LGMAX 200
using namespace std;
int main()
{
	ifstream f("criptmat.in");
	int n;
	f >> n;
	f.get(); // citesc '\n'
	char s[LGMAX+1];
	f.get(s, LGMAX+1);
	f.close();
	int m=0;
	char a[LGMAX/2][LGMAX];
	// construiesc matricea
	for (int i = 0; s[i]; i++)
		if (i % n || i == 0)
			a[m][i % n] = s[i];
		else
			a[++m][0] = s[i];
	// inversez liniile impare
	for (int i = 1; i <= m; i += 2)
		for (int j = 0, k = n-1; j < k; j++, k--)
			swap(a[i][j], a[i][k]);
	ofstream g("criptmat.out");
	// afisez rezultatul
	for (int j = 0; j < n; j++)
		for (int i = 0; i <= m; i++)
			g << a[i][j];
	return 0;
}

