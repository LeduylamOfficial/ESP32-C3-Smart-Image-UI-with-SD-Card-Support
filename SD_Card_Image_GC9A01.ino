#include <SPI.h>
#include <FS.h>
#include <SD.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>

// 1. ĐỊNH NGHĨA CÁC MÃ MÀU 16-BIT (RGB565)
#define BLACK     0x0000
#define BLUE      0x001F
#define RED       0xF800
#define GREEN     0x07E0
#define CYAN      0x07FF
#define MAGENTA   0xF81F
#define YELLOW    0xFFE0
#define WHITE     0xFFFF
#define DARKGREY  0x4A49

// 2. ĐỊNH NGHĨA CHÂN THEO ĐÚNG SƠ ĐỒ CỦA BẠN

// --- Cấu hình chân SD Card ---
#define SD_MOSI   6
#define SD_MISO   5
#define SD_SCK    7
#define SD_CS     4

// --- Cấu hình chân TFT GC9A01 ---
#define TFT_SCL   0  // Tương đương SCK của màn hình
#define TFT_SDA   1  // Tương đương MOSI của màn hình
#define TFT_DC    2
#define TFT_CS    10
#define TFT_RST   3

// Khởi tạo màn hình bằng Software SPI (truyền đầy đủ các chân Data, Clock, DC, CS, RST)
// Cách này giúp cô lập hoàn toàn màn hình khỏi bus SPI của thẻ SD, chống lỗi tuyệt đối!
Adafruit_GC9A01A tft = Adafruit_GC9A01A(TFT_CS, TFT_DC, TFT_SDA, TFT_SCL, TFT_RST);

// --- CÁC HÀM GIAO DIỆN ---

void drawInsertSD() {
  tft.fillScreen(MAGENTA);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.setCursor(40, 100);
  tft.println("INSERT SD CARD");
}

void drawMainUI() {
  tft.fillScreen(BLACK);
  tft.fillRoundRect(35, 30, 170, 110, 15, DARKGREY);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.setCursor(50, 50);
  tft.println("ESP32-C3");
  tft.setCursor(50, 80);
  tft.println("Smart Clock");

  tft.fillRoundRect(15, 160, 95, 45, 10, BLUE);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.setCursor(35, 178);
  tft.println("LEFT BUTTON");

  tft.fillRoundRect(130, 160, 95, 45, 10, GREEN);
  tft.setTextColor(BLACK);
  tft.setTextSize(1);
  tft.setCursor(145, 178);
  tft.println("RIGHT BTN");
}

void drawResetScreen() {
  tft.fillScreen(RED);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.setCursor(50, 100);
  tft.println("RESETTING...");
}

void showLeftImage() {
  tft.fillRoundRect(35, 30, 170, 110, 15, BLUE);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.setCursor(60, 70);
  tft.println("LEFT PIC");
}

void showRightImage() {
  tft.fillRoundRect(35, 30, 170, 110, 15, GREEN);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(60, 70);
  tft.println("RIGHT PIC");
}

void setup() {
  Serial.begin(115200);
  delay(1000); 

  // 3. KHỞI TẠO MÀN HÌNH TFT
  tft.begin();
  tft.setRotation(0); 
  tft.fillScreen(BLACK);

  // 4. KHỞI TẠO BUS SPI RIÊNG CHO THẺ SD
  SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

  Serial.print("Connecting SD card... ");
  if (!SD.begin(SD_CS)) {
    Serial.println("That's wrong! Check the file or format the card (FAT32)..");
    drawInsertSD(); 
  } else {
    Serial.println("Complete!");
    drawMainUI();   
  }
}

void loop() {
  // Code logic chính của bạn ở đây
}