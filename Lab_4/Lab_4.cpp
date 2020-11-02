#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#pragma warning(disable : 4996) // чтобы freopen не ругался

bool find_dublicates_C(char* source, int lenght);
bool find_dublicates_S(std::string line, int lenght);

//std::string functionString(const std::string& source);

int main()
{
	setlocale(LC_ALL, "ru");
	//char
	{
		try {
			freopen("data.txt", "r", stdin); // это как ifstream но круче, работает как с консолью
			int lenght;
			bool result = false;
			while (std::cin >> lenght) {
				if (std::cin.fail()) {
					throw 666;
				}
				char* c_string = new char[lenght]; // динамический массив символов
				for (int i = 0; i < lenght; i++) {
					if (!(std::cin >> c_string[i])) {
						throw 666;
					}
				}
				result = find_dublicates_C(c_string, lenght);
				delete[]c_string;


				std::ofstream file_clear("answer_char.txt", std::ios_base::trunc); // чистим файл от старых записей
				file_clear.close();
				std::ofstream file("answer_char.txt", std::ios_base::app);
				if (result) {
					std::cout << "char: " << "True" << "\n";
					file << "True" << "\n";
				}
				else {
					std::cout << "char: " << "False" << "\n";
					file << "False" << "\n";
				}
				file.close(); // закрываем файл

			}
		}
		catch (...) {
			std::cerr << "\n Ошибка при чтении файла, данные некорректны! \n";
			return 666;
		}


	}
	//char

	//string
	{
		try {
			std::ifstream data("data.txt");
			int len;
			bool answer = false;
			std::string answ;
			while (data >> len) {
				std::string line;
				data >> line;
				answer = find_dublicates_S(line, len);
				line.clear();
				if (answer) {
					std::cout << "string: " << "True" << "\n";
					answ = answ + "True\n";
				}
				else {
					std::cout << "string: " << "False" << "\n";
					answ = answ + "False\n";
				}
			}

			std::ofstream data_clear("answer_string.txt", std::ios_base::trunc); // чистим файл от старых записей
			data_clear.close();
			std::ofstream data_file("answer_string.txt", std::ios_base::app);
			data_file << answ << "\n";
			data_file.close(); // закрываем файл
		}
		catch (...) {
			std::cerr << "\n Ошибка при чтении файла, данные некорректны! \n";
			return 666;
		}
	}
	//string
}
bool find_dublicates_C(char* source, int lenght) {
	bool result = false;
	for (int i = 0; i < (lenght - 1); i++) {
		for (int p = i+1; p < (lenght - 1); p++) {
			if (source[i] == source[p]) {
				result = true;
				return result;
			}
		}
	}
	return result;
}
bool find_dublicates_S(std::string line, int lenght) {
	bool result = false;
	for (int i = 0; i < (lenght - 1); i++) {
		for (int p = i + 1; p < (lenght - 1); p++) {
			if (line[i] == line[p]) {
				result = true;
				return result;
			}
		}
	}
	return result;
}

