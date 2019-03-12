#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>

using namespace std;

// 1.	*Отсортируйте буквы в строке в порядке возрастания.
char*letterSort(char*str) {
	char tmp[2];
	char*p = tmp, *p1 = tmp + 1;

	for (int i = 0; i < strlen(str) - 1; i++)
	{
		for (int j = 0; j < strlen(str) - 1; j++)
		{
			*p = str[j];
			*p1 = str[j + 1];
			if (strcmp(p, p1) == 1)
				swap(str[j], str[j + 1]);
		}
	}
	return str;
}

// 2.	***Пользователь вводит 2 строки, программа формирует третью строку, в которую помещает общие символы двух строк.
char*commonSym(char*str1, char*str2) {
	int prove = 0, k = 0;

	int n, m;
	if (strlen(str1) < strlen(str2))
	{
		n = strlen(str1);
		m = strlen(str2);
	}
	else
	{
		n = strlen(str2);
		m = strlen(str1);
	}

	cout << n << " " << m << endl;

	char tmp[2];
	char*p = tmp, *p1 = tmp + 1;
	int* index = new int[n];
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*p = str1[i];
			*p1 = str2[j];
			if (j != index)
			{
				if (strcmp(p, p1) == 0)
				{
					k++;
					index[d++] = j;
					break;
				}
			}
		}
	}
	cout << "k (минимальный размер нового массива) = " << k << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*p = str1[j];
			*p1 = str2[j];
			if (strcmp(p, p1) == 0)
			{
				index[k--] = j;
				break;
			}
		}
	}

	char *tmp_line = new char[k];
	int h = 0;

	for (int i = 0; i < n; i++)
	{
		prove = 0;
		for (int j = 0; j < m; j++)
		{
			*p = str1[j];
			*p1 = str2[j];
			if (strcmp(p, p1) == 0)
			{
				prove++;
			}
		}
		if (prove != 0)
		{
			tmp[h++] = str1[i];

			//del_index(copy2, mm, index);
		}

	}

	for (int i = 0; i < k; i++)
		cout << tmp_line[i] << " ";
	cout << endl << endl;

	//delete[] tmp_line;

	return tmp_line;
}






int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			char str[100];
			cin.getline(str, 100);
			char*p = letterSort(str);

			cout << p << endl;
		}
		break;
		case 2:
		{
			char str1[100] = "text123";
			char str2[100] = "ttxeeet345";

			char*line = commonSym(str1, str2);
			cout << line << endl;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}