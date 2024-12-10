#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "invalid input" << std::endl;
		return (1);
	}

	std::string	target(argv[2]);
	std::string	replace(argv[3]);
	std::string buf("");

	std::ifstream file(argv[1]);
	char	c;
	while (file.good())
	{
		c = file.get();
		if (c >= 0)
			buf += c;
		else
			break;
	}
	file.close();

	if (target == "")
	{
		std::string	replaceFile(argv[1]);
		replaceFile.append(".replace");
	
		std::ofstream	newFile;
		newFile.open(replaceFile);
		newFile << buf;
		newFile.close();
		return (0);
	}

	size_t	targetPos = 0;
	size_t	startPos = 0;
	while (1)
	{
		targetPos = buf.find(target, startPos);
		if (targetPos == std::string::npos)
			break;
		buf.erase(targetPos, target.length());
		buf.insert(targetPos, replace);
		startPos = targetPos + replace.length();
	}

	std::string	replaceFile(argv[1]);
	replaceFile.append(".replace");

	std::ofstream	newFile;
	newFile.open(replaceFile);
	newFile << buf;
	newFile.close();
	return (0);
}
