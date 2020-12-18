// lab9.cpp : 
//

#include"Cat.h"

int main()
{
	MyNamespace::Algorithm A;
	A.algorithm1();
	std::ifstream file;
	file.open("T2.txt");
	try {
		if (!file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		MyNamespace::Exception ex(i);
		ex.Print();
		return 0;
	}
	char str[256];           
	while (!file.getline(str, sizeof(str)).eof())
		std::cout << str << std::endl;
	file.close();
	std::vector<MyNamespace::cat> V;
	MyNamespace::cat T1;
	std::fstream file1;
	file1.open("T3.txt");
	std::string str1;
	std::string str2;
	char c;
	while (!file1.eof()) 
	{
		do {
			file1.get(c);
			str1 += c;
		} while (c != ' ' && c != '\n');
		do {
			file1.get(c);
			str2 += c;
		} while (c != '\n' && c != ' ');
		if (file1.eof()) break;
		MyNamespace::cat T(str1,str2);
		T1 = T;
		str1.clear();
		str2.clear();
		V.push_back(T);
	}
	try {
		if (V.size() <= 0)
		{
			throw 2;
		}
	}
	catch (int i)
	{
		MyNamespace::Exception ex(i);
		ex.Print();
		return 0;
	}
	std::vector<MyNamespace::cat>::iterator It;
	It = V.begin();
	while (It != V.end())
	{
		std::cout << *It;
		It++;
	}
	std::cout << "\nThe desired element: " << std::endl;
	std::cout << T1;
	A.algorithm2(It = V.begin(), It = V.end(),T1);
	file1.close();
	std::cout << "\n-----------------------------------------------------------------\n";
	A.algorithm3(V,It = V.begin(), It = V.end(),T1);
	It = V.begin();
	while (It != V.end())
	{
		std::cout << *It;
		It++;
	}
}
