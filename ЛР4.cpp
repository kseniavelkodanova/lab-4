#include <iostream>
using namespace std;

// Описати функцію Sign (X) цілого типу, яка повертає для дійсного числа X 
// наступні значення: -1, якщо X <0; 0, якщо X = 0; 1, якщо X> 0. За 
// допомогою цієї функції знайти значення виразу Sign (A) + Sign (B) для 
// даних дійсних чисел A і B.
void task_1(); // Завдання 1 

int Sign(double X); // Декларація функції(Proc16)

// Дано тризначне число. Перевірити істинність висловлювання: 
// «Цифри даного числа утворюють зростаючу або спадаючу послідовність» 
void task_2();// Завдання 2 

bool in_number(int& pL); // Введення з перевіркою Boolean22
bool out_number(int pr); // Виведення резудьтатів Boolean22


// Дано ціле число, більше 999. Використовуючи одну операцію ділення остачі і одну операцію взяття залишку від ділення, 
// знайти цифру, відповідну розряду тисяч в записі цього числа. 
void task_3(); // Завдання 3

bool in_L(int& pL); // Введення з перевіркою Integer18
int check_L(int pL); // Підрахунок Integer18
void out_res(int pr); // Виведення резудьтатів Integer18


int main() {
	int menu;
	cout << "Task1: 1\nTask2: 2\nTask3: 3" << endl;
	cout << "Task number:";
	cin >> menu;
	// Перемикання між завданнями
	switch (menu)
	{
	case 1: task_1(); break; // Завдання 1
	case 2: task_2(); break; // Завдання 2
	case 3: task_3(); break; // Завдання 3
	default: cout << "Wrong task! (Only 1,2,3)" << endl; // Повідомлення про помилку
	}
	system("pause");
	return 0;
}

// Визначення функцій завдання 1
void task_1() {
	double A, B; // Декларація змінної
	cout << "************* Proc16 *****************"<<endl;
	cout << "Enter A and B: ";
	cin >> A >> B; // Введення даних
	if (cin.fail()) { // Перевірка коректності даних
		cout << "Must be number!" << endl;
	}
	else {
		cout << Sign(A) + Sign(B) << endl; // Виклик обрахунку
	}
}
// Визначення функцій
int Sign(double X) {
	if (X < 0) {
		return -1;
	}
	else if (X == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

// Визначення функцій завдання 2
void task_2() {
	int L; // Декларація змінної
	cout << "************* Boolean22 *****************"<<endl;
	if (in_number(L)) // Некоректні дані
		cout << "Must be number or >=100 and <=999 " << endl;
	else {
		// Підрахунок і виведення результату
		if (out_number(L)) {
			cout << "This is an increasing or decreasing sequence"<<endl;
		}
		else {
			cout << "This is not an increasing or decreasing sequence"<<endl;
		}
	}
}
// Визначення функцій введення і перевірки вхідних даних на коректність
bool in_number(int& pL){
	cout << "L2 = ";
	cin >> pL;
	if (cin.fail() || pL < 100 || pL > 999) // Перевірка помилок консольного введення
		return true;

	else return false;
}
// Визначення функцій розрахунку на підставі коректних вхідних даних результату
bool out_number(int number) {
	int hundreds = number / 100;          // Сотні
	int tens = (number / 10) % 10;        // Десятки
	int units = number % 10;              // Одиниці

	// Перевірка зростаючої або спадаючої послідовності
	if ((hundreds < tens && tens < units) || (hundreds > tens && tens > units)) {
		return true;
	}
	else {
		return false;
	}
}

// Визначення функцій завдання 3
void task_3()
{
	int L; // Декларація змінної
	cout << "************* Integer18 *****************"<<endl;
	if (in_L(L)) // Некоректні дані
		cout << "Must be integer and >999" << endl;
	else
		// Підрахунок і виведення результату
		out_res(check_L(L));
}
// Визначення функцій введення вхідних значень з консолі з перевіркою їх на коректність
bool in_L(int& pL)
{
	cout << "L3 = ";
	cin >> pL;
	if (cin.fail() || pL <= 999) // Перевірка помилок консольного введення
		return true;

	else return false;
}
// Визначення функцій підрахунку результату
int check_L(int pL)
{
	return (pL / 1000) % 10;
}
// Визначення функцій виведення результату в консоль
void out_res(int pr)
{
	cout << "Answer: " << pr << endl;
}
