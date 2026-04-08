#include <iostream>

#include "sll.hpp"

#define N_CHARS 26

int main(void)
{

      AyED::sll<char> L1;

      for (int i = 0; i < N_CHARS; i++)
      {
            L1.insert_head(new AyED::sll_node<char>('a' + i));
      }

      L1.write(std::cout);
      std::cout << std::endl;

      AyED::sll<char> L2;

      for (int i = 0; i < N_CHARS; i++)
      {
             L2.insert_tail(new AyED::sll_node<char>('a' + i));
      }

      L2.write(std::cout);
      std::cout << std::endl;

      return 0;
}
