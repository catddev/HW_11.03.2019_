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
	int k = 0;
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
	//cout << n << " " << m << endl;

	for (int i = 0; i < n; i++) // идем по более короткой строке
	{
		for (int j = k; j < m; j++) //j=k чтобы при сравнении не привлекал отсортированннеы общие элементы в начале второй строки, а бегал по тем, что еще не имеют совпадений с первой строкой
		{
			if (strncmp(str1+i, str2+j, 1) == 0) //сравнение по одному символу
			{
				swap(str2[j], str2[k]); //сортировка, перенос общего элемента на начало более длинной строки
				k++;
				break;
			}
		}
	}
	cout << "k (минимальный размер новой строки) = " << k << endl;

	char *tmp = new char[k+1];

	for (int i = 0; i < k; i++)
		tmp[i] = str2[i]; //запись в новую строку отсортированной части второй строки, т.е. только общих элементов
	tmp[k] = '\0';
	//cout << tmp << endl;
	return tmp;
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

			cout << p << endl << endl;
		}
		break;
		case 2:
		{
			char str1[100] = "terxt123";
			char str2[100] = "ttxeeet345";

			char*line = commonSym(str1, str2);
			cout << line << endl << endl;

			delete[] line;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}