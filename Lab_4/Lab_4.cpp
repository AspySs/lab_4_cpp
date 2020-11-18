#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
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
			std::ifstream c_data("data.txt");
			int lenght;
			bool result = false;
			while (c_data >> lenght) {
				char* c_string = new char[lenght]; // динамический массив символов
				c_data.clear();
				c_data.get();
				c_data.sync();
				if (!(c_data.getline(c_string, lenght + 1))) {
					throw "ошибка при чтении файла";
				}
				result = find_dublicates_C(c_string, lenght);
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
			return 6;
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
				data.clear();
				data.get();
				data.sync();
				if (!(getline(data, line))) {
					throw "ошибка при чтении файла";
				}
				;
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
			return 6;
		}
	}
	//string
}
bool find_dublicates_C(char* source, int lenght) {
	bool result = false;
	for (int i = 0; i < (lenght); i++) {
		for (int p = i+1; p < (lenght); p++) {
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
	for (int i = 0; i < (lenght); i++) {
		for (int p = i + 1; p < (lenght); p++) {
			if (line[i] == line[p]) {
				result = true;
				return result;
			}
		}
	}
	return result;
}

