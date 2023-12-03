#include "libanalysistool.h"
// #include <raylib.h>

int main() {
  LibAnalysisTool::Parsers::CSVParser parser;
  parser.open("test_files/test.csv");
  // SetConfigFlags(ConfigFlags::FLAG_WINDOW_RESIZABLE);
  // InitWindow(800, 600, "Data Analysis Tool");
  // SetTargetFPS(60);
  //
  // while (!WindowShouldClose()) {
  //   BeginDrawing();
  //   ClearBackground(BLACK);
  //   EndDrawing();
  // }
  //
  // CloseWindow();
  return 0;
}
