#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

int main()
{
  std::unordered_map<std::string, std::string> phoneBook;
  std::string filename = "data.csv";
  std::ifstream file(filename);

  if (!file.is_open())
  {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return 1;
  }

  std::string line, name, phone;
  while (std::getline(file, line))
  {
    std::stringstream ss(line);
    if (std::getline(ss, name, ',') && std::getline(ss, phone))
    {
      phoneBook[phone] = name;
    }
  }
  file.close();

  std::string searchPhone;
  std::cout << "Enter phone number to search: ";
  std::cin >> searchPhone;

  auto it = phoneBook.find(searchPhone);
  if (it != phoneBook.end())
  {
    std::cout << "Subscriber found: " << it->second << std::endl;
  }
  else
  {
    std::cout << "Error: Number not found." << std::endl;
  }

  return 0;
}