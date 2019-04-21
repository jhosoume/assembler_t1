#include "helper.hpp"

void helpMessage() {
  std::cout <<  "Usage: tradutor FILE..." << std::endl;
  std::cout <<  "Assembles FILE into a pre-processed text file (.pre) with the same \
    name as the original file and an object text file (.obj). All files will be \
    saved in the current directory." << std::endl;
}

void noFileMessage() {
  std::cout << "[ERR] FILE was not specified. Must be path plus filename and its extension." << std::endl;
}
void invalidArgumentMessage() {
  std::cout << "[ERR] FILE was not correctly specified." << std::endl;
}

File::File(char *file) {
  // Separates filename from its extension
  bool ext_bool = false;
  for (unsigned int indx = 0; indx < strlen(file); ++indx) {
    if (file[indx] == '.') {
      ext_bool = true;
      continue;
    }
    ext_bool ? ext.push_back(file[indx]) :
               filename.push_back(file[indx]);
  }
}

string File::fullname() {
  return (ext.empty() ? filename : (filename + '.' + ext));
}

string File::extension() {
  return ext;
}

string File::name() {
  return filename;
}

// Returns a File type that has the filename and its extension
File getFileNameFromArg(int argc, char **argv) {
  // Check if number of inputs is correct, should have one argument
  if (argc < 2) {
    noFileMessage();
    helpMessage();
    exit(1);
  } else if (argc > 2) {
    invalidArgumentMessage();
    helpMessage();
    exit(1);
  }
  File file = File(argv[1]);
  return file;
}

// Split string into tokens according to delimiters
vector<string> split(const string& str, const string& delim) {
  vector<string> parts;
  size_t start, end = 0;
  while (end < str.size()) {
    start = end;
    while (start < str.size() && (delim.find(str[start]) != string::npos)) {
      ++start;  // skip initial whitespace
    }
    end = start;
    while (end < str.size() && (delim.find(str[end]) == string::npos)) {
      ++end; // skip to end of word
    }
    if (end - start != 0) {  // just ignore zero-length strings.
      parts.push_back(string(str, start, end - start));
    }
  }
  return parts;
}

// Verify if the string is a valid hex (positive or negative)
bool is_hex_notation(const string &s) {
  return ((s.size() > 2 &&
          s.compare(0, 2, "0x") == 0 &&
          s.find_first_not_of("0123456789abcdefABCDEF", 2) == string::npos)
      ||(s.size() > 3 &&
        s.compare(0, 3, "-0x") == 0 &&
        s.find_first_not_of("0123456789abcdefABCDEF", 3) == string::npos));
}
