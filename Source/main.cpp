#include "../Include/menu.h"
#include <windows.h>

#pragma execution_character_set( "utf-8" )

int main()
{
  SetConsoleOutputCP( 65001 );
  processMenu(main_menu);
  std::cin.get();

  return 0;
}
