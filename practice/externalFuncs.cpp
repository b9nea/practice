#include "externalFuncs.h"
#include <iostream>
#include <limits>

/*	Функции, встречающиеся в большом количестве
*	улучшенных версий заданий.
*	В случае рассмотрения решений как
*	отдельных компонентов, можно
*	добавить необходимые функции в их код
*	или оставить этот файл, удалив лишнее */

// игнорирование лишних символов при вводе
void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// получение целого числа от пользователя
int getInt() {
	while (true) {
		std::cout << "Введите целое число: ";
		int num{};
		std::cin >> num;

		// проверка корректности ввода
		if (std::cin.fail()) {
			std::cin.clear();
			ignoreLine();
			std::cout << "Неправильный ввод. Попробуйте ещё раз.\n";
		}
		else {
			ignoreLine();
			return num;
		}
	}
}

// получение числа с плавающей точкой от пользователя
double getDouble() {
	while (true) {
		std::cout << "Введите число с плавающей точкой: ";
		double num{};
		std::cin >> num;

		// проверка корректности ввода
		if (std::cin.fail()) {
			std::cin.clear();
			ignoreLine();
			std::cout << "Неправильный ввод. Попробуйте ещё раз.\n";
		}
		else {
			ignoreLine();
			return num;
		}
	}
}

// получение символа

char getChar() {
	while (true) {
		std::cout << "Введите символ: ";
		char ch{};
		std::cin >> ch;
		ignoreLine();

		// проверка корректности ввода
		if (std::cin.fail()) {
			std::cin.clear();
			ignoreLine();
			std::cout << "Неправильный ввод. Попробуйте ещё раз.\n";
		}
		else {
			ignoreLine();
			return ch;
		}
	}
}

// получение оператора для функции calculate()
char getOperator() {
	while (true) {
		std::cout << "Введите оператор: + - / : ";
		char oper{};
		std::cin >> oper;
		ignoreLine();

		// проверка корректности ввода
		switch (oper) {
		case '+':
		case '-':
		case '*':
		case '/':
			return oper;
		default:
			std::cout << "Неправильный ввод. Попробуйте ещё раз.\n";
		}
	}
}

// вычисление значения (примитивный калькулятор)
void calculate(double firstVar, char operation, double secondVar) {
	if (operation == '+')
		std::cout << firstVar << " + " << secondVar << " = " << firstVar + secondVar << '\n';
	else if (operation == '-')
		std::cout << firstVar << " - " << secondVar << " = " << firstVar - secondVar << '\n';
	else if (operation == '*')
		std::cout << firstVar << " * " << secondVar << " = " << firstVar * secondVar << '\n';
	else if (operation == '/')
		std::cout << firstVar << " / " << secondVar << " = " << (firstVar / secondVar) << '\n';
}

// вывод ответа в консоль
void writeAnswer(int val) {
	std::cout << "Ответ: " << val << std::endl;
}