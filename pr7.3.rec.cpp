#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Input(int** a, const int n, int i, int j);
void Print(int** a, const int n, int i, int j);
void Print_in(int** a, const int n, int i, int j);
void CountLocMinCenter(int** a, const int n, int& count, int i, int j);
void CountLocMinFrameH(int** a, const int n, int& count);
void CountLocMinVert(int** a, const int n, int& count, int i);
void CountLocMinHoriz(int** a, const int n, int& count, int j);
int SumAbsDiag(int** a, const int n, int& sum, int i, int j);
void SumAbsDiag_in(int** a, const int n, int& sum, int i, int j);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -23;
	int High = 26;
	int n;
	int sum = 0;
	int i = 0, j = 0;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	//Input(a, n, i, j);
	Print(a, n, i, j);
	int count = 0;
	int suma = SumAbsDiag(a, n, sum, i, j);
	i = 1; j = 1;
	CountLocMinCenter(a, n, count, i, j);	
	CountLocMinFrameH(a, n, count);
	CountLocMinVert(a, n, count, i);
	CountLocMinHoriz(a, n, count, j);
	cout << "Sum = " << suma << endl;
	cout << "Count = " << count;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			a[i][j] = Low + rand() % (High - Low + 1);
		}
}

void Input_in(int** a, const int n, int i, int j)
{
		if (j < n)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
			Input_in(a, n, i, j + 1);
		}
}

void Input(int** a, const int n, int i, int j)
{
	if(i < n)
	{
		Input_in(a, n, i, j);
		cout << endl;
		Input(a, n, i + 1, j);
		
	}
}

void Print(int** a, const int n, int i, int j)
{
	if (i < n)
	{
		Print_in(a, n, i, j);
		cout << endl;
		Print(a, n, i + 1, j);
	}
}

void Print_in(int** a, const int n, int i, int j)
{
	if (j < n) {
		cout << setw(4) << a[i][j];
		Print_in(a, n, i, j + 1);
	}
}

void SumAbsDiag_in(int** a, const int n, int& sum, int i, int j)
{
		if (j < n) {
			sum += abs(a[i][j]);
			SumAbsDiag_in(a, n, sum, i, j + 1);
		}
}

int SumAbsDiag(int** a, const int n, int& sum, int i, int j)
{

	if(i < n - 1)
	{
		j = i + 1;
		SumAbsDiag_in(a, n, sum, i, j);
		SumAbsDiag(a, n, sum, i + 1, j);
	}
	return sum;
}

void CountLocMinFrameH(int** a, const int n, int& count)
{
	if ((a[0][0] < a[0][1]) && (a[0][0] < a[1][0]) && (a[0][0] < a[1][1]))
		count++;
	if ((a[0][n - 1] < a[0][n - 2]) && (a[0][n - 1] < a[1][n - 1]) && (a[0][n - 1] < a[1][n - 2]))
		count++;
	if ((a[n - 1][0] < a[n - 2][0]) && (a[n - 1][0] < a[n - 1][1]) && (a[n - 1][0] < a[n - 2][1]))
		count++;
	if ((a[n - 1][n - 1] < a[n - 1][n - 2]) && (a[n - 1][n - 1] < a[n - 2][n - 1]) && (a[n - 1][n - 1] < a[n - 2][n - 2]))
		count++;

}

void CountLocMinVert(int** a, const int n, int& count, int i)
{
	if(i < (n - 1)) {
		if ((a[i][0] < a[i - 1][1]) && (a[i][0] < a[i][1]) && (a[i][0] < a[i + 1][1]) && (a[i][0] < a[i - 1][0]) && (a[i][0] < a[i + 1][0]))
			count++;
		if ((a[i][n - 1] < a[i - 1][n - 2]) && (a[i][n - 1] < a[i][n - 2]) && (a[i][n - 1] < a[i + 1][n - 2]) && (a[i][n - 1] < a[i + 1][n - 1]) && (a[i][n - 1] < a[i - 1][n - 1]))
			count++;
		CountLocMinVert(a, n, count, i + 1);
	}
}

void CountLocMinHoriz(int** a, const int n, int& count, int j)
{
	if( j < n - 1) {
		if ((a[0][j] < a[1][j - 1]) && (a[0][j] < a[1][j]) && (a[0][j] < a[1][j + 1]) && (a[0][j] < a[0][j + 1]) && (a[0][j] < a[0][j - 1]))
			count++;
		if ((a[n - 1][j] < a[n - 2][j - 1]) && (a[n - 1][j] < a[n - 2][j]) && (a[n - 1][j] < a[n - 2][j + 1]) && (a[n - 1][j] < a[n - 1][j + 1]) && (a[n - 1][j] < a[n - 1][j - 1]))
			count++;
		CountLocMinHoriz(a, n, count, j + 1);
	}
}

void CountLocMinCenter(int** a, const int n, int& count, int i, int j)
{
	if(i < n - 1) {
		if(j < n - 1) {
			if (a[i][j] < a[i - 1][j] &&
				a[i][j] < a[i + 1][j] &&
				a[i][j] < a[i][j - 1] &&
				a[i][j] < a[i][j + 1] &&
				a[i][j] < a[i - 1][j - 1] &&
				a[i][j] < a[i + 1][j - 1] &&
				a[i][j] < a[i - 1][j + 1] &&
				a[i][j] < a[i + 1][j + 1])
				count++;
			CountLocMinCenter(a, n, count, i, j + 1);
		}
		CountLocMinCenter(a, n, count, i + 1, j);
	}
}
