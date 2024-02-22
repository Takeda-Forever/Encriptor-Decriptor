#include <iostream>
#include <vector>

std::string encrypt(std::string w);
std::string decrypt(std::string w);

void unit_test() 
{
	std::vector < std::string> w =
	{
		"Bauka","Bauka0000","Bauka1234","Bauka9876",
		"Kabuk","Kabuk0000","Kabuk1234","Kabuk9876",
		"Tupat","Tupat0000","Tupat1234","Tupat9876",
		"Shaka","Shaka0000","Shaka1234","Shaka9876",
		"0123456789", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	};
	std::vector<std::string> dec;
	std::vector<std::string> enc;

	for (std::string wd : w)
		enc.push_back(encrypt(wd));

	for (std::string wd : dec)
		dec.push_back(decrypt(wd));

	std::cout << "Words to Encrypt:\n";

	for (int i = 1; i <= w.size(); i++)
	{
		std::cout << w.at(i-1) << ',';
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "After Encrypt:\n";

	for (int i = 1; i <= dec.size(); i++)
	{
		std::cout  << dec.at(i-1) << ',';
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "After Decrypt:\n";

	for (int i = 1; i <= enc.size(); i++)
	{
		std::cout  << enc.at(i-1) << ',';
	}
	
}

int main() 
{
	unit_test();
}


std::string encrypt(std::string w)
{
	std::string result;

	for (char c : w)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) // если это буква
		{
			if (c >= 'a' && c <= 'z') // если это маленькая буква
				c = 'a' + (c - 'a' + 3) % 26;
			else // иначе это большая буква
				c = 'A' + (c - 'A' + 3) % 26;
		}
		else if (c >= '0' && c <= '9') // если это цифра
			c = '0' + (c - '0' + 3) % 10;

		result += c;
	}

	return result;
}

std::string decrypt(std::string w)
{
	std::string result;

	for (char c : w)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) // если это буква
		{
			if (c >= 'a' && c <= 'z') // если это маленькая буква
				c = 'a' + (c - 'a' + 23) % 26;
			else // иначе это большая буква
				c = 'A' + (c - 'A' + 23) % 26;
		}
		else if (c >= '0' && c <= '9') // если это цифра
			c = '0' + (c - '0' + 7) % 10;

		result += c;
	}

	return result;
}
