#ifndef __SSD1306_TEST_H__
#define __SSD1306_TEST_H__

void ssd1306_TestBorder(void);
void ssd1306_TestFonts(void);
void ssd1306_TestFPS(void);
void ssd1306_TestAll(void);
void ssd1306_TestLine(void);
void ssd1306_TestRectangle(void);
void ssd1306_TestCircle(void);
void ssd1306_TestArc(void);
void ssd1306_TestPolyline(void);

void test_circle(void);
void writeString(char *message);
void testString(int selected);
#endif // __SSD1306_TEST_H__
