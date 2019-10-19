#include <array>
#include <cstdio>
#include <iostream>
#include <string>

#define N 1000

int main() {
  std::array<char, N> mem;
  for (int i = 0; i < N; i++) {
    mem.at(i) = 0;
  }
  unsigned int ptr = 0;
  std::string src;
  std::getline(std::cin, src);
  int cursor = 0;
  while (cursor < src.length()) {
    switch (src.at(cursor)) {
      case '>':
        ptr += 1;
        break;
      case '<':
        ptr -= 1;
        break;
      case '+':
        mem.at(ptr) += 1;
        break;
      case '-':
        mem.at(ptr) -= 1;
        break;
      case '.':
        std::cout << mem.at(ptr);
        break;
      case ',':
        std::scanf("%c", &mem.at(ptr));
        break;
    }
    if (src.at(cursor) == ']' && mem.at(ptr) != 0) {
      int n = 1;
      while (n != 0 || src.at(cursor) != '[') {
        cursor -= 1;
        if (src.at(cursor) == ']')
          n += 1;
        if (src.at(cursor) == '[')
          n -= 1;
      }
    } else if (src.at(cursor) == '[' && mem.at(ptr) == 0) {
      int n = 1;
      while (n != 0 || src.at(cursor) != ']') {
        cursor -= 1;
        if (src.at(cursor) == '[')
          n += 1;
        if (src.at(cursor) == ']')
          n -= 1;
      }
    } else
      cursor += 1;
  }
  std::cout << "\n";
  return 0;
}