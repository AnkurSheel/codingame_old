#include "MimeType.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;
string GetExtension(const string& fileName)
{
  int index = fileName.find_last_of('.');
  if (index != string::npos)
  {
    return fileName.substr(index + 1, fileName.length() - index - 1);
  }
  return "";
}

void MimeType::main()
{
  int numberOfElements;
  cin >> numberOfElements;
  cin.ignore();
  int numberOfFileNames;
  cin >> numberOfFileNames;
  cin.ignore();
  map<string, string> typeMap;
  string output;

  for (int i = 0; i < numberOfElements; i++)
  {
    string fileExtension;
    string mimeType;
    cin >> fileExtension >> mimeType;
    cin.ignore();
    std::transform(fileExtension.begin(), fileExtension.end(), fileExtension.begin(), ::tolower);

    typeMap.insert(std::pair<string, string>(fileExtension, mimeType));
  }
  for (int i = 0; i < numberOfFileNames; i++)
  {
    string fileName;  // One file name per line.
    getline(cin, fileName);
    string extension = GetExtension(fileName);
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    auto it = typeMap.find(extension);
    if (it != typeMap.end())
    {
      output += it->second;
    }
    else
    {
      output += "UNKNOWN";
    }

    output += "\n";
  }

  cout << output;
}
