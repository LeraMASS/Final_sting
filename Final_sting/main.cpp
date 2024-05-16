#include <iostream>
#include <string>

//задача 1.
std::string spases_str(std::string str) {
	for (int i = str.size() - 1; i > 0; i--)//Ставит пробел в обратном порядке (от конца)
		str.insert(i, " ");
	return str;
}
std::string spases_str1(std::string str) {
	std::string res;
	for (int i = 0; i < str.length(); i++) {
		res += str[i];
		if (i != str.length() - 1)
			res += ' ';
	}
	return str;
}
//Задача 2.
bool have_spam(std::string str) {
	//Обеспечение нерегистрозависимости функции
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	//Массив словосочетаний, обозн. спам
	const int spams_number = 4;
	static const std::string spams_messeges[spams_number]{ // С целью оптимизации. const чтоб случайно не изменить содержимое массива
		"100% free",
		"sale increase",
		"only todey",
		"blakc fridey"
	};
	//Перебор спамовых словосочетаний с целью выявления их в строке.
	for (int i = 0; i < spams_number; i++)//Перебор элементов массива
		if (str.find(spams_messeges[i]) < str.length()) // если позиция подстроки в строке, меншье длинны самой строки, то значит она присутствует в строке, тк элемента нет в строке, то функция фаинд вернет макс значение ансайнед лонг лонг
			return true;

	return false;//
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//Задача 1. Пробелы в строку 
	std::cout << "Задача 1.\n Введите строку -> ";
	std::string str1;//типо переменная
	std::getline(std::cin, str1);//функция 
	std::cout << spases_str(str1) << "\n\n";

	//Задача 2. Проверка спам
	std::cout << "Задача 2. \nВведите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);
	//bool функцию лучше проверять через if
	if (have_spam(str2)) //bool сама по себе возвращает true или false
		std::cout << "Обнаружен спам\n\n";
	else
		std::cout << "Спам не обнаружен\n\n";

	//Задача 3.







	return 0;
}