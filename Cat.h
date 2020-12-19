#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

namespace MyNamespace 
{
	class cat
	{
	private:
		static int in;
		int id;
		std::string name;
		std::string diagnosis;
	public:
		cat(std::string nm, std::string dg) : name(nm), diagnosis(dg)
		{
			id = in;
			in++;
		}
		cat()
		{
			id = 0;
			in++;
			name = "-";
			diagnosis = "-";
		}
		void input()
		{
			std::cout << "\nEnter your pet's name" << std::endl;
			getline(std::cin, name);
			std::cout << "\nEnter your pet's diagnosis" << std::endl;
			getline(std::cin, diagnosis);

		}
		void output()
		{
			std::cout << "\nId - " << id << "\nName - " << name << "\nDiagnosis - " << diagnosis << std::endl;
		}
		bool operator< (cat& c2) const
		{
			return (name[0] < c2.name[0]) ? true : false;
		}
		bool operator> (cat& c2) const
		{
			return (name[0] > c2.name[0]) ? true : false;
		}
		bool operator== (cat& c2) const
		{
			return (name[0] == c2.name[0]) ? true : false;
		}
		friend std::ostream& operator<<(std::ostream& out, const cat c);
	};
	int cat::in = 1;
	std::ostream& operator<<(std::ostream& out, const cat c)
	{
		out << "\nId - " << c.id << "\nName - " << c.name << "\nDiagnosis - " << c.diagnosis << std::endl;
		return out;
	}
	class Exception
	{
	protected:
		int error;
	public:
		Exception()
		{
			error = 0;
		}
		Exception(int _error)
		{
			error = _error;
		}
		~Exception() { };
		void Print()
		{
			if (this->error == 1)
			{
				std::cout << "File isn't open!" << std::endl;
			}
			if (this->error == 2)
			{
				std::cout << "The vector is empty!" << std::endl;
			}
			if (this->error < 1 || this->error > 2)
			{
				int time = clock();
				std::cout << "Error time! " << time << std::endl;
			}
		}
	};
	class Algorithm
	{
	public:
		void algorithm1()
		{
			std::ifstream file1;
			int c=1;
			file1.open("T1.txt");
			try {
				if (!file1.is_open())
				{
					throw 1;
				}
			}
			catch (int i)
			{
				MyNamespace::Exception ex(i);
				ex.Print();
				return;
			}
			std::ofstream file2;
			file2.open("T2.txt");
			try {
				if (!file2.is_open())
				{
					throw 1;
				}
			}
			catch (int i)
			{
				MyNamespace::Exception ex(i);
				ex.Print();
				return;
			}
			while (!file1.eof()) 
			{
				char s[256];
				int count = 0;
				file1.getline(s,256);
				for (int i = 0; i < 256; i++)
				{
					if (s[i]==' '|| s[i] == '\0')
					{
						count++;
					}
					if (s[i] == '\0')
						break;
				}
				char str[]="The number of words in line ";
				file2 << str<<c<<": "<<count<<"\n";
				c++;
			}
			file1.close();
			file2.close();
		}
		void algorithm2(std::vector<MyNamespace::cat>::iterator begin, std::vector<MyNamespace::cat>::iterator end, MyNamespace::cat T)
		{
			while (begin != end) 
			{
				begin++;
				if (begin == end) break;
				if (*begin == T)
				{
					std::cout << "Algorithm 2 True, element is found" << std::endl;
					return;
				}
			}
			std::cout << "Algorithm 2 False, elemet isn't found" << std::endl;
		}
		void algorithm3(std::vector<MyNamespace::cat>& V,std::vector<MyNamespace::cat>::iterator begin, std::vector<MyNamespace::cat>::iterator end, MyNamespace::cat T)
		{
			std::vector<MyNamespace::cat>::iterator It;
			It = begin;
			int i = 0;
			while (begin != end)
			{
				begin++;
				i++;
				if (begin == end) break;
				if (*begin == T)
				{
					V.erase(It+i);
					return;
				}
			}
		}
	};
}
