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

std::vector<std::vector<std::string>> CSVParser::getHead(int n) {
  std::vector<std::vector<std::string>> head;
  head.emplace_back(getColumnNames());
  if (n == -1)
    n = 5;
  while (n-- && !mInpFS.eof()) {
    head.emplace_back(mParseNextLine());
  }
  return head;
}

void CSVParser::printHead() {
  auto head = getHead();
  for (auto &row : head) {
    if (row.size() == 0)
      return;
    std::cout << "| ";
    for (auto &cell : row) {
      std::cout << cell << " | ";
    }
    std::cout << std::endl;
  }
}

} // namespace LibAnalysisTool::Parsers
