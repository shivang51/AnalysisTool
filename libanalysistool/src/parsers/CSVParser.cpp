#include "CSVParser.h"
#include "iostream"
#include <sstream>
#include <string>
#include <vector>

namespace LibAnalysisTool::Parsers {
CSVParser::CSVParser(std::string filepath) { this->open(filepath); }

CSVParser::~CSVParser() { this->close(); }

void CSVParser::open(std::string filepath) {
  mInpFS.open(filepath);
  if (!mInpFS.is_open()) {
    std::cerr << "[-] failed to open file " << filepath << std::endl;
    return;
  }
  std::cout << "[+] file opened " << filepath << std::endl;
  this->mFilePath = filepath;

  for (auto colName : getColumnNames())
    std::cout << colName << ", ";
  std::cout << std::endl;
}

void CSVParser::close() {
  if (mInpFS.is_open())
    mInpFS.close();
}

std::vector<std::string> CSVParser::mParseNextLine() {
  std::string line;
  std::getline(mInpFS, line);

  auto linestream = std::stringstream(line);
  std::string cell;
  std::vector<std::string> cells;
  while (std::getline(linestream, cell, ',')) {
    cells.emplace_back(cell);
  }
  return cells;
}

std::vector<std::string> CSVParser::getColumnNames() {
  mInpFS.seekg(mInpFS.beg);
  return mParseNextLine();
}

} // namespace LibAnalysisTool::Parsers
