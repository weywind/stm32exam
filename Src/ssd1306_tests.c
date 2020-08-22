#include <string.h>
#include <stdio.h>
#include "ssd1306.h"
#include "ssd1306_tests.h"

typedef struct
{
  /* data */
  int id;
  char title[10];
} MenuItem;

void writeString(char *message)
{
  ssd1306_Fill(Black);
  ssd1306_SetCursor(2, 0);
  ssd1306_WriteString(message, Font_11x18, White);
  ssd1306_UpdateScreen();
}

void fillBlack()
{
  ssd1306_Fill(Black);
}
void updateDateTime(char *str)
{
  ssd1306_SetCursor(0, 3);
  ssd1306_WriteString(str, Font_7x10, White);
  ssd1306_UpdateScreen();
}
