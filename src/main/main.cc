#include <iostream>
#include "src/lib/trojanmap.h"
#include <vector>
#include <unordered_set>

int main() {
  TrojanMap x;
  x.CreateGraphFromCSVFile();
  x.PrintMenu();
  return 0;

}


