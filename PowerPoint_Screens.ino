/*
This code was automatically generated from graphic elements in a PowerPoint presentation
Generated: Donnerstag, 19. Mai 2022 13:11:32
  Version: 1.0.4
Original autogenerate code written by Kris Kasprzak kris.kasprzak@yahoo.com
Use this code without warranty

Rev    Date         Author             Desc
1.0    06/06/2020   Kasprzak           Initial code
1.1    01/08/2022   Frank B            Improvements and TFT_eSPI_ext library
1.0.x  08/01/2022   Bodmer             Debugged and extended functionality
1.0.x  19/05/2022   wurstbrot0xff      Debugged and extended functionality

Requires library TFT_eSPI (can load via Arduino IDE library manager):
    https://github.com/Bodmer/TFT_eSPI
and Frank's font extension library:
    https://github.com/FrankBoesing/TFT_eSPI_ext
additional font files are available here:
    https://github.com/FrankBoesing/fonts/tree/main/ofl
*/

// You will need to include the appropriate .h files for the fonts
// This example uses the standard fonts that comes with TFT_eSPI_ext.

// Fonts in these files are available in the following sizes:
// 8, 9, 10, 11, 12, 13, 14, 16, 18, 20, 24, 28, 32, 40, 48, 60, 72 and 96
// This example uses size 32
#include <font_Arial.h>
#include <font_ArialBold.h>
#include <font_ArialItalic.h>
#include <font_ArialBoldItalic.h>

#include <SPI.h>
#include <TFT_eSPI.h>
#include <TFT_eSPI_ext.h>

TFT_eSPI     tft = TFT_eSPI();
TFT_eSprite  img = TFT_eSprite(&tft);

// TFT_eSPI_ext will inherit the TFT_eSPI class functions so the created -etft- instance
// can call both the extension font class and the -tft instance TFT_eSPI base class functions.
// So tft.fillScreen(TFT_BLUE) and etft.fillScreen(TFT_BLUE) do the same thing!
// TFT_eSPI_ext functions can only be called using the -etft- instance
TFT_eSPI_ext etft = TFT_eSPI_ext(&tft);


// Rounded rectangles will be turned into Adafruit buttons
// add code for touch screen processing

TFT_eSPI_Button Button1;
char buttonLabel1[] = "Label";
TFT_eSPI_Button Button2;
char buttonLabel2[] = "Button 2";
TFT_eSPI_Button Button3;
char buttonLabel3[] = "Button 3";
TFT_eSPI_Button Button4;
char buttonLabel4[] = "Setup";


void setup(){

  tft.begin();

  // use 1 or 3 for landscape mode
  // you will have to experiment as displays are different
  tft.setRotation(3);

  Button1.initButton(&tft,64, 56, 52, 15, 0xF800, 0x4398, 0xFFFF, buttonLabel1, 2);
  Button2.initButton(&tft,124, 56, 52, 15, 0xF800, 0x4398, 0xFFFF, buttonLabel2, 2);
  Button3.initButton(&tft,184, 56, 52, 15, 0xF800, 0x4398, 0xFFFF, buttonLabel3, 2);
  Button4.initButton(&tft,267, 36, 60, 27, 0xFFFF, 0x2A54, 0xFFFF, buttonLabel4, 2);

}

void loop(){


  // function call for Screen1
  Screen1();
  delay(5000);


  // function call for Screen2
  Screen2();
  delay(5000);


  // function call for Screen3
  Screen3();
  delay(5000);


  // function call for Screen4
  Screen4();
  delay(5000);


  // function call for Screen5
  Screen5();
  delay(5000);


  // function call for Screen6
  Screen6();
  delay(5000);

}

void Screen1(){


  tft.fillScreen(0xFFFF);

  // Isosceles Triangle 1
  tft.fillTriangle(20, 107, 110, 107, 65, 51, 0x4398);
  tft.drawTriangle(20, 107, 110, 107, 65, 51, 0x0000);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,94);
  tft.setCursor(53, 81);
  tft.print(F("TEST"));

  // Isosceles Triangle 2
  tft.fillTriangle(25, 115, 104, 115, 65, 206, 0xF800);
  // Right Triangle 3
  tft.fillTriangle(240, 55, 283, 93, 240, 93, 0xF800);
  tft.drawTriangle(240, 55, 283, 93, 240, 93, 0xF81F);
  // Right Triangle 4
  tft.fillTriangle(240, 136, 283, 98, 240, 98, 0x07E0);
  // Right Triangle 5
  tft.fillTriangle(235, 55, 235, 93, 193, 93, 0xFE00);
  tft.drawTriangle(235, 55, 235, 93, 193, 93, 0x0000);
  // Right Triangle 6
  tft.fillTriangle(235, 136, 235, 98, 193, 98, 0x001F);
  // TextBox 7
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8,94);
  tft.setCursor(23, 33);
  tft.print(F("Isosceles triangles"));

  // TextBox 8
  tft.setTextColor(0x001F);
  tft.setTTFFont(Arial_8,94);
  tft.setCursor(175, 33);
  tft.print(F("Right angle triangles"));

  // TextBox 9
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8,94);
  tft.setCursor(82, 201);
  tft.print(F("Shape outline and fill is optional"));

  tft.drawLine(167, 113, 111, 182, 0x001F);
  // TextBox 12
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8,94);
  tft.setCursor(125, 114);
  tft.print(F("Lines"));

  tft.drawLine(128, 135, 161, 170, 0x07E0);
  tft.drawLine(115, 162, 158, 150, 0xF800);
  // Oval 17
  tft.fillEllipse(237, 154, 33, 11, 0x001F);
  tft.fillEllipse(237, 154, 32, 10, 0xF81F);
  // Oval 18
  tft.drawEllipse(237, 182, 33, 11, 0xF800);
  // TextBox 19
  tft.setTextColor(0xF800);
  tft.setTTFFont(Arial_8,94);
  tft.setCursor(152, 175);
  tft.print(F("Ellipses"));

  // Rectangle 20
  tft.fillRect(111, 55, 75, 32, 0x2A91);
  tft.fillRect(112, 56, 73, 30, 0xC716);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_7,67);
  tft.setCursor(121, 67);
  tft.print(F("Rectangles"));



}

void Screen2(){


  tft.fillScreen(0xFFFF);

  // TextBox 1
  tft.fillRectHGradient(7, 28, 307, 37, 0xF800, 0xFE00);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_15,32);
  tft.setCursor(120, 38);
  tft.print(F("Text box"));

  // TextBox 8
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_6,39);
  tft.setCursor(17, 86);
  tft.print(F("Text boxes with optional fill and outline  are supported"));

  // TextBox 10
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_6,39);
  tft.setCursor(121, 103);
  tft.print(F("A gradient fill can be horizontal or vertical only"));

  // TextBox 14
  tft.drawRect(87, 164, 123, 33, 0xF800);
  tft.setTextColor(0xF800);
  tft.setTTFFont(Arial_6,39);
  tft.setCursor(97, 171);
  tft.print(F("Text wrapping like this in boxes not supported"));

  // TextBox 15
  tft.setTextColor(0xF800);
  tft.setTTFFont(Arial_6,39_Bold);
  tft.setCursor(45, 132);
  tft.print(F("Use a font face that will be available to sketch e.g. Arial"));

  // TextBox 18
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_6,39);
  tft.setCursor(84, 69);
  tft.print(F("Text can be justified left, right or centre"));



}

void Screen3(){


  tft.fillScreen(0xFFFF);

  // TextBox 8
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_7,67);
  tft.setCursor(19, 119);
  tft.print(F("Rounded rectangles create code for the library button class"));

  tft.drawLine(83, 69, 131, 116, 0x4398);
  tft.drawLine(131, 116, 176, 69, 0x4398);
  tft.drawLine(131, 115, 126, 71, 0x4398);

  tft.setTTFFont(Arial_6,39);
  Button1.drawButton();
  tft.setTTFFont(Arial_6,39);
  Button2.drawButton();
  tft.setTTFFont(Arial_6,39);
  Button3.drawButton();

}

void Screen4(){


  tft.fillScreen(0xFFFF);

  // TextBox 1
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8,94);
  tft.setCursor(98, 64);
  tft.print(F("Tables can be created"));

  // Table 3
  tft.drawFastHLine(43, 81, 220, 0xFFFF);
  tft.fillRect(43, 81, 55, 20, 0x4398);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8_Bold);
  tft.setCursor(49, 89 );
  tft.print(F("Test"));

  tft.fillRect(98, 81, 55, 20, 0x4398);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8_Bold);
  tft.setCursor(104, 89 );
  tft.print(F("Test"));

  tft.fillRect(153, 81, 55, 20, 0x4398);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8_Bold);
  tft.setCursor(159, 89 );
  tft.print(F("Test"));

  tft.fillRect(208, 81, 55, 20, 0x4398);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8_Bold);
  tft.setCursor(214, 89 );
  tft.print(F("Test"));

  tft.drawFastHLine(43, 101, 220, 0xFFFF);
  tft.fillRect(43, 101, 55, 20, 0xCEBD);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(49, 109 );
  tft.print(F("123"));

  tft.fillRect(98, 101, 55, 20, 0xCEBD);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(104, 109 );
  tft.print(F("456"));

  tft.fillRect(153, 101, 55, 20, 0xCEBD);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(159, 109 );
  tft.print(F("789"));

  tft.fillRect(208, 101, 55, 20, 0xCEBD);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(214, 109 );
  tft.print(F("…"));

  tft.drawFastHLine(43, 121, 220, 0xFFFF);
  tft.fillRect(43, 121, 55, 20, 0xEF5E);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(49, 129 );
  tft.print(F("abc"));

  tft.fillRect(98, 121, 55, 20, 0xEF5E);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(104, 129 );
  tft.print(F("def"));

  tft.fillRect(153, 121, 55, 20, 0xEF5E);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(159, 129 );
  tft.print(F("ghi"));

  tft.fillRect(208, 121, 55, 20, 0xEF5E);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(214, 129 );
  tft.print(F("…"));

  tft.drawFastHLine(43, 141, 220, 0xFFFF);
  tft.fillRect(43, 141, 55, 20, 0xCEBD);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(49, 149 );
  tft.print(F("…"));

  tft.fillRect(98, 141, 55, 20, 0xCEBD);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(104, 149 );
  tft.print(F("…"));

  tft.fillRect(153, 141, 55, 20, 0xCEBD);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(159, 149 );
  tft.print(F("…"));

  tft.fillRect(208, 141, 55, 20, 0xCEBD);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(214, 149 );
  tft.print(F("…"));

  tft.drawFastHLine(43, 161, 220, 0xFFFF);
  tft.drawFastHLine(43, 81, 220, 0xFFFF);
  tft.drawFastVLine(43, 81, 81, 0xFFFF);
  tft.drawFastVLine(98, 81, 81, 0xFFFF);
  tft.drawFastVLine(153, 81, 81, 0xFFFF);
  tft.drawFastVLine(208, 81, 81, 0xFFFF);
  tft.drawFastVLine(263, 81, 81, 0xFFFF);



}

void Screen5(){


  tft.fillScreen(0xFFFF);

  // Table 1
  tft.drawFastHLine(41, 51, 222, 0x0000);
  tft.fillRect(41, 51, 71, 26, 0xEBE6);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8_Bold);
  tft.setCursor(51, 61 );
  tft.print(F("  integer"));

  tft.fillRect(112, 51, 75, 26, 0xEBE6);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8_Bold);
  tft.setCursor(122, 61 );
  tft.print(F("    float"));

  tft.fillRect(187, 51, 76, 26, 0xEBE6);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8_Bold);
  tft.setCursor(197, 61 );
  tft.print(F("     char"));

  tft.drawFastHLine(41, 77, 222, 0x0000);
  tft.fillRect(41, 77, 71, 26, 0xFF7D);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(51, 87 );
  static int tab11 = 0;
  tft.print(tab11);

  tft.fillRect(112, 77, 75, 26, 0xFF7D);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(122, 87 );
  static float tab21 = 0.00;
  tft.print(tab21);

  tft.fillRect(187, 77, 76, 26, 0xFF7D);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(197, 87 );
  const char tab31[] = "Text";
  tft.print(tab31);

  tft.drawFastHLine(41, 103, 222, 0x0000);
  tft.fillRect(41, 103, 71, 26, 0xFFFF);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(51, 113 );
  static int tab12 = 0;
  tft.print(tab12);

  tft.fillRect(112, 103, 75, 26, 0xFFFF);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(122, 113 );
  static float tab22 = 0.00;
  tft.print(tab22);

  tft.fillRect(187, 103, 76, 26, 0xFFFF);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(197, 113 );
  const char tab32[] = "Text";
  tft.print(tab32);

  tft.drawFastHLine(41, 129, 222, 0x0000);
  tft.fillRect(41, 129, 71, 26, 0xFF7D);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(51, 139 );
  static int tab13 = 0;
  tft.print(tab13);

  tft.fillRect(112, 129, 75, 26, 0xFF7D);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(122, 139 );
  static float tab23 = 0.00;
  tft.print(tab23);

  tft.fillRect(187, 129, 76, 26, 0xFF7D);
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_8);
  tft.setCursor(197, 139 );
  const char tab33[] = "Text";
  tft.print(tab33);

  tft.drawFastHLine(41, 155, 222, 0x0000);
  tft.drawFastHLine(41, 51, 222, 0x0000);
  tft.drawFastVLine(41, 51, 106, 0x0000);
  tft.drawFastVLine(112, 51, 106, 0x0000);
  tft.drawFastVLine(187, 51, 106, 0x0000);
  tft.drawFastVLine(263, 51, 106, 0x0000);

  // TextBox 2
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_12,77);
  tft.setCursor(38, 30);
  tft.print(F("Tables can contain variables"));

  // TextBox 3
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_6,39);
  tft.setCursor(19, 164);
  tft.print(F("The =xxx means create an integer variable with name xxx in sketch"));

  // TextBox 12
  tft.setTextColor(0x0000);
  tft.setTTFFont(Arial_6,39);
  tft.setCursor(23, 178);
  tft.print(F("Add optional . for float and $ for a char array variable"));

  // TextBox 13
  tft.setTextColor(0xF800);
  tft.setTTFFont(Arial_6,39);
  tft.setCursor(101, 204);
  tft.print(F("See example on next sheet"));



}

void Screen6(){


  tft.fillScreen(0xFFFF);

  // TextBox 2
  tft.fillRect(7, 18, 307, 39, 0x39C7);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_12,77_Bold);
  tft.setCursor(10, 30);
  tft.print(F("HOME AUTOMATION"));

  // Rectangle 5
  tft.fillRectHGradient(15, 68, 142, 147, 0x0861, 0x4A69);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99_Bold);
  tft.setCursor(15, 71);
  tft.print(F("TIME"));

  // Rectangle 11
  tft.fillRectHGradient(163, 68, 71, 148, 0x0861, 0x4A69);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99_Bold);
  tft.setCursor(163, 71);
  tft.print(F("TEMP"));

  // Rectangle 12
  tft.fillRectHGradient(237, 68, 71, 148, 0x0861, 0x4A69);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99_Bold);
  tft.setCursor(237, 71);
  tft.print(F("%RH"));

  // TextBox 19
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99);
  tft.setCursor(16, 85);
  const char timeNow[] = "Text";
  tft.print(timeNow);

  // TextBox 27
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99);
  tft.setCursor(167, 122);
  static float tmax = 0.00;
  tft.print(tmax);

  // TextBox 29
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99);
  tft.setCursor(168, 199);
  static float tnow = 0.00;
  tft.print(tnow);

  // TextBox 30
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99);
  tft.setCursor(241, 199);
  static int rhnow = 0;
  tft.print(rhnow);

  // Table 8
  tft.drawFastHLine(14, 105, 142, 0xFFFF);
  tft.fillRect(14, 105, 71, 27, 0x010C);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_9_Bold);
  tft.setCursor(21, 113 );
  tft.print(F("Door"));

  tft.fillRect(85, 105, 69, 27, 0x010C);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_9_Bold);
  tft.setCursor(92, 113 );
  tft.print(F("Status"));

  tft.drawFastHLine(14, 132, 142, 0xFFFF);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_9);
  tft.setCursor(18, 137 );
  tft.print(F("Front"));

  tft.setTextColor(0xF800);
  tft.setTTFFont(Arial_9);
  tft.setCursor(89, 137 );
  const char frontStat[] = "Text";
  tft.print(frontStat);

  tft.drawFastHLine(14, 148, 142, 0xFFFF);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_9);
  tft.setCursor(18, 153 );
  tft.print(F("Back"));

  tft.setTextColor(0x058A);
  tft.setTTFFont(Arial_9);
  tft.setCursor(89, 153 );
  const char backStat[] = "Text";
  tft.print(backStat);

  tft.drawFastHLine(14, 164, 142, 0xFFFF);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_9);
  tft.setCursor(18, 169 );
  tft.print(F("Garage"));

  tft.setTextColor(0xF800);
  tft.setTTFFont(Arial_9);
  tft.setCursor(89, 169 );
  const char gargStat[] = "Text";
  tft.print(gargStat);

  tft.drawFastHLine(14, 180, 142, 0xFFFF);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_9);
  tft.setCursor(18, 185 );
  tft.print(F("Side"));

  tft.setTextColor(0x058A);
  tft.setTTFFont(Arial_9);
  tft.setCursor(89, 185 );
  const char sideStat[] = "Text";
  tft.print(sideStat);

  tft.drawFastHLine(14, 196, 142, 0xFFFF);
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_9);
  tft.setCursor(18, 201 );
  tft.print(F("Porch"));

  tft.setTextColor(0xF800);
  tft.setTTFFont(Arial_9);
  tft.setCursor(89, 201 );
  const char porchStat[] = "Text";
  tft.print(porchStat);

  tft.drawFastHLine(14, 227, 142, 0xFFFF);
  tft.drawFastHLine(14, 105, 142, 0xFFFF);
  tft.drawFastVLine(14, 105, 125, 0xFFFF);
  tft.drawFastVLine(85, 105, 125, 0xFFFF);
  tft.drawFastVLine(154, 105, 125, 0xFFFF);

  // TextBox 32
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99);
  tft.setCursor(241, 122);
  static int rhmax = 0;
  tft.print(rhmax);

  // TextBox 33
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99);
  tft.setCursor(167, 160);
  static float tmin = 0.00;
  tft.print(tmin);

  // TextBox 34
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99);
  tft.setCursor(241, 160);
  static int rhmin = 0;
  tft.print(rhmin);

  // TextBox 23
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99_Bold);
  tft.setCursor(241, 184);
  tft.print(F("NOW"));

  // TextBox 24
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99_Bold);
  tft.setCursor(241, 107);
  tft.print(F("MAX"));

  // TextBox 25
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99_Bold);
  tft.setCursor(241, 146);
  tft.print(F("MIN"));

  // TextBox 26
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99_Bold);
  tft.setCursor(165, 184);
  tft.print(F("NOW"));

  // TextBox 28
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99_Bold);
  tft.setCursor(165, 107);
  tft.print(F("MAX"));

  // TextBox 31
  tft.setTextColor(0xFFFF);
  tft.setTTFFont(Arial_8,99_Bold);
  tft.setCursor(165, 146);
  tft.print(F("MIN"));


  tft.setTTFFont(Arial_12,77);
  Button4.drawButton();

}
/*
End of the auto-generated sketch!
*/
