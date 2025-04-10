#include <iostream>
#include <sstream>
#include <fstream>

void inputStr()
{
	int a, b, c;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	std::cout << a << ' ' << b << ' ' << c << '\n';
	const char input[] = "  10 20   	30";
	std::stringstream str(input);

// [  10 20   	30]
// 	^ - курсорът прескача whitespace-овете и въвежда числата в съответните променливи
// това важи и за std::cin

	str >> a;
	str >> b;
	str >> c;

	std::cout << a << ' ' << b << ' ' << c << '\n';
}

void outStr()
{
	std::stringstream my_stream;

	int var;
	std::istringstream test("10 20 30");
	test >> var;
	//test << var;

	my_stream << "Hellp world!";
	my_stream << " Here is a number " << 40;

	std::cout << my_stream.str();

	//fstream
	//ifstream
	//ofstream различни потоци за работа с файлове
}
void fileRead(int argc, char* argv[])
{
	if(argc != 2)
	{
		std::cout << "Usage: application.exe <path>";
		return;
	}

	std::cout << "Opening \"" << argv[1] << "\" for reading.\n";

	// вариант 1
	//std::ifstream file(argv[1]);

	// вариант 2
	std::ifstream file;
	file.open(argv[1]);

	if(! file.is_open())
	{
		std::cerr << "ERROR:"
		<< " cannot open "
		<< argv[1]
		<< " for readin\n";

		std::cout.flush(); // изплюва целия буфер на конзолата
		// std::endl - вика flush след новия ред
	}

	std::cout << "Proceed to read from file:\n";

	while (!file.eof())
	{
		int value;
		file >> value;

		if(file.eof()) break;

		if( ! file.good())
		{
			file.clear();
			std::cerr << "ERROR: bad data at position "
			<< file.tellg()
			<< std::endl;
			break;
		}
		std::cout << value << std::endl;
	}
}

void foo()
{
	const char input[] = " hello:bla vble:12";
	std::stringstream str(input);

	char word1[100];
	char word2[100];
	int number;
	str.getline(word1, 100, ':');
	str.getline(word2, 100, ':');
	str >> number;

	std::cout << word1 << '\n' << word2 << '\n' << number << '\n';
}
int main(int argc, char* argv[])
{
	foo();
	std::stringstream my_stream("Hello world!");

	int size = 100;
	char buffer[size];

	// while(true)
	// {
	// 	my_stream >> buffer;

	// 	if(my_stream) std::cout << buffer << std::endl;
	// }

	std::cin.getline(buffer, size);
	std::cout<<buffer;
	//while(std::cin >> buffer) std::cout << buffer << std::endl;
}