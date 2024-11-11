#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Spec { KN, INF, MATEC,FIZNF,TRUD };
string specStr[] =
{ "����'����� �����",
"�����������",
"���������� �� ��������",
"Գ���� �� �����������",
"������� ��������"};
struct Studik
{
	string prizv;
	unsigned kurs;
	unsigned fiz;
	unsigned mat;
	Spec spec;
	union
	{
		int prog;
		int chiselmethod;
		int pedagog;
	};
};
void Create(Studik* p, const int N);
void Print(Studik* p, const int N);
double LineSearch(Studik* p, const int N, int& k);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k = 0;
	int N;
	cout << "������ N: "; cin >> N;

	Studik* p = new Studik[N];
	Create(p, N);
	Print(p, N);
	cout << LineSearch(p, N, k) << endl;
	cout << "ʳ������ ����� � ������ � '3','4','5' ������:" << k << endl;

	return 0;
}
void Create(Studik* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ������������: (0 - ����'����� �����,1 - �����������, 2 - ���������� �� �������� , 3 - Գ���� �� ����������� , 4 - ������� ��������): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������ � ������: "; cin >> p[i].fiz;
		cout << " ������ � ����������: "; cin >> p[i].mat;
		switch (p[i].spec)
		{
		case KN:
			cout << " ������������� : "; cin >> p[i].prog;
			break;
		case INF:
			cout << " ��������� ����� : "; cin >> p[i].chiselmethod;
			break;
		default:
			cout << " ��������� : "; cin >> p[i].pedagog;
		}
	}
}
void Print(Studik* p, const int N)
{
	cout << "================================================================================================================================" << endl;
	cout << "| �   | �������       | ���� | ������������            | Գ���� | ���������� | ������������� | ��������� ����� |  ��������� |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(15) << left << p[i].prizv // ������� 
			<< "| " << setw(4) << right << p[i].kurs << " "// ����
			<< "| " << setw(25) << left << specStr[p[i].spec] // ������������ 
			<< "| " << setw(6) << right << p[i].fiz << " "    // Գ���� 
			<< "| " << setw(10) << right << p[i].mat << " ";   // ����������
		switch (p[i].spec)
		{
		case KN:
			cout << "| " << setw(13) << setprecision(2) << fixed << right << p[i].prog << " |" << setw(17) << " " << "|" << setw(13) << " " << "|" << endl;
			break;
		case INF:
			cout << "| " << setw(14) << " " << "| " << setw(15) << setprecision(2) << fixed << right << p[i].chiselmethod << " |" <<setw(13) << " " << "|" << endl;
			break;
		default:
			cout << "| " << setw(14) << " " << "| " << setw(16) << " " << "| " << setw(11) << setprecision(2) << fixed << right << p[i].pedagog << " |" << endl;
			break;
		}

	}
	cout << "================================================================================================================================"<< endl;
}
double LineSearch(Studik* p, const int N, int& k)
{
	cout << "ʳ������ ��������, �� �������� � � ������, � ���������� '4','5':";
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].fiz == 4 || p[i].fiz == 5 || p[i].fiz == 3)
		{
			k++;
		}
		if ((p[i].fiz == 4 || p[i].fiz == 5) && (p[i].mat == 4 || p[i].mat == 5))
		{
			n++;
		}
	}
	return n;
}
