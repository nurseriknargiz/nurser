#include<iostream>
#include<time.h>


using namespace std;


void fellArray(int *mas, int n);
void printArray(int *mas, int n);
int sumArray(int *mas, int n);
void second(int *mas, int n);
void sort(int *mas, int n);
void masvmas(int *mas1, int *mas2, int n);
void fitfth(int* mas, int n);
void sixth(int *mas, int n, int*pol, int *otr, int *nul);
int seventh(int *mas, int *mas1, int *M, int N);
int seventh2(int *mas, int *mas1, int *mas3, int *M, int N);

void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	rand();
	int x;
	do
	{
		cout << " Введите номер задания: " << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			int mas[5];
			int n = 5;
			fellArray(mas, n);
			printArray(mas, n);
			cout << endl << sumArray(mas, n) << endl;
		}
		break;
		case 2:
		{
			int mas[5];
			int n = 5;
			fellArray(mas, n);
			printArray(mas, n);
			second(mas, n);
		}
		break;

		case 3:
		{
			int mas[10];
			int n = 10;
			fellArray(mas, n);
			printArray(mas, n);
			cout << endl;
			sort(mas, n);
			printArray(mas, n);

		}break;
		case 4:
		{
			int mas1[10];
			int mas2[10];
			int n = 10;
			fellArray(mas1, n);
			masvmas(mas1, mas2, n);
			printArray(mas1, n);
			cout << endl;
			printArray(mas2, n);
		}
		break;
		case 5:
		{
			int mas[10];
			int n = 10;
			fellArray(mas, n);
			printArray(mas, n);
			cout << endl;
			fitfth(mas, n);
		} break;

		case 6:
		{
			int mas[10];
			int n = 10;
			fellArray(mas, n);
			printArray(mas, n);
			int pol = 0;
			int otr = 0;
			int nul = 0;
			sixth(mas, n, &pol, &otr, &nul);
			cout << endl << "Отрицательный= "
				<< otr << "Положительный = "
				<< pol << "нулевой = " << nul << endl;
		}
		break;
		case 7:
		{
			int M, N, A = 0;
			cin >> M >> N;
			int *mas = new int[M];
			int *mas1 = new int[N];
			A = seventh(mas, mas1, &M, N);
			int *mas3 = new int[A];
			seventh(mas, mas1, mas3, M, N);

			fellArray (mas, M);

			feelArray (mas1, N);
			
			cout << endl;
			printArray(mas, N);
			cout << endl;
			printArray(mas1, M);
			cout << endl;
			printArray(mas3, A);







		}break;
		}

	} while (x > 0);

}

void fellArray(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(mas + i) = -10 + rand() % 10;
	}
}
void printArray(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(mas + i) << "\t";
	}
}
int sumArray(int *mas, int n)
{
	int sum = 0;
		for (int i = 0;i < n;i++)
		{
			sum += *(mas + i);
		}
		return sum;
}
void second(int *mas, int n)
{
	for (int i = n-1; i>=1; i--)
	{
		cout << *(mas + i) << "\t";
	}
}
int ifotr(int *mas, int n)
{
	for (int i = 0; i <n;  i++)
	{
		if (*(mas + i) < 0)
		
			return 1;
	}
	return 0;
}
void sort(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ifotr(mas, n) == 1)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = n - 1;j > i;j++)
				{
					if (*(mas + j) < *(mas + j - 1))
					{
						int x = * (mas + j);
						*(mas + j) = *(mas + j - 1);
						*(mas + j-1) = x;
					}
				}
			}
		}
		else
		{
			if (ifotr(mas, n) == 1)
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = n - 1;j > i;j++)
					{
						if (*(mas + j) > *(mas + j - 1))
						{
							int x = *(mas + j);
							*(mas + j) = *(mas + j - 1);
							*(mas + j) = x;
						}
					}
				}
			}
		}
	}
}
void masvmas(int *mas1, int *mas2, int n)
{
	for (int i = 0;i < n;i++)
	{
		*(mas2 + i) = *(mas1 + i);
	}
}
void fitfth(int* mas, int n)
{

	for (int i = n - 1; i >= 1; i--)
	{
		cout << *(mas + i) << "\t";
	}
}
void sixth(int *mas, int n, int*pol, int *otr, int *nul)
{
	for (int i = 0; i < n; i++)
	{
		if (*(mas + i) < 0)
			*pol +=1;
		else if (*(mas + i) > 0)
			*otr += 1;
		else	if (*(mas + i) > 0)
			*nul += 1;
	}
}
int seventh(int *mas, int *mas1,int *M, int N)
{
	int a = 0;
	for (int i = 0; i < M ; i++)
	{
		int x = *(mas + i);
		for (int j = 0; j < N;j++)
		{
			if (*(mas + i) == *(mas + j))
				a++;
		}
	}
	return a;
}
int seventh2(int *mas, int *mas1,int *mas3, int *M, int N)
{
	int k = 0;
	for (int i = 0; i < M; i++)
	{
		int x = *(mas + i);
		for (int j = 0; j < N;j++)
		{
			if (*(mas + i) == *(mas + j))
				*(mas3 + k) = *(mas + i);
			k++;
		}
	}
}