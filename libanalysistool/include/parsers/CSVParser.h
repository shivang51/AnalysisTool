#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace LibAnalysisTool::Parsers {
class CSVParser {
public:
  CSVParser() = default;
  CSVParser(std::string filepath);
  ~CSVParser();

public:
  void open(std::string filepath);
  void close();
  std::vector<std::string> getColumnNames();
  std::vector<std::vector<std::string>> getHead(int n = -1);
  void printHead();

private:
  std::string mFilePath;
  std::ifstream mInpFS;
  int mCurrLine;
  std::unordered_map<std::string, std::vector<std::string>> data;

private:
  std::vector<std::string> mParseLine(int line);
  std::vector<std::string> mParseNextLine();
};
} // namespace LibAnalysisTool::Parsers
