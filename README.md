# ESP32-C3 Smart Image UI with SD Card Support

Vietnamese:
Dự án giao diện Image thông minh sử dụng chip **ESP32-C3**, màn hình tròn **TFT GC9A01**, và mô-đun **thẻ nhớ SD** để lưu trữ hình ảnh/dữ liệu. 

## 🛠️ Sơ đồ đấu nối phần cứng (Pinout)

Do ESP32-C3 được cấu hình tách biệt bộ chân để tránh xung đột SPI giữa màn hình và thẻ nhớ, sơ đồ kết nối cụ thể như sau:

### 💾 1. SD Card Module (Hardware SPI)
| Chân SD Card | Chân ESP32-C3 | Chức năng |
| :--- | :--- | :--- |
| **MOSI** | GPIO 6 | Data Out |
| **MISO** | GPIO 5 | Data In |
| **SCK** | GPIO 7 | Clock |
| **CS** | GPIO 4 | Chip Select |

### 📺 2. TFT GC9A01 Display (Software SPI)
| Chân TFT | Chân ESP32-C3 | Chức năng |
| :--- | :--- | :--- |
| **SCL** | GPIO 0 | Clock |
| **SDA** | GPIO 1 | Data |
| **DC** | GPIO 2 | Data/Command |
| **RST** | GPIO 3 | Reset |
| **CS** | GPIO 10 | Chip Select |

---

## 📚 Thư viện cần cài đặt (Dependencies)
Để biên dịch được code, bạn cần cài đặt các thư viện sau qua **Library Manager** trên Arduino IDE:
* `Adafruit_GFX`
* `Adafruit_GC9A01A`
* `SD` và `FS` (Có sẵn trong gói core ESP32)

## 🚀 Tính năng hiện tại
- Fix triệt để lỗi thiếu định nghĩa mã màu 16-bit (`BLACK`, `WHITE`, `DARKGREY`,...).
- Tách độc lập bus SPI giúp nạp thẻ SD song song với màn hình không bị treo (`Failed`).
- Thiết kế bo góc UI giao diện chính và các hiệu ứng chuyển màn hình nút bấm.

- English:
# ESP32-C3 Smart Image UI with SD Card Support

This smart image UI project uses the **ESP32-C3** chip, a **G-9A01** TFT circular display, and an **SD ​​card** module for image/data storage.

## 🛠️ Hardware Pinout Diagram

Because the ESP32-C3 has a separate pinout configuration to avoid SPI conflicts between the display and the SD card, the specific connection diagram is as follows:

### 💾 1. SD Card Module (Hardware SPI)

| SD Card Pin | ESP32-C3 Pin | Function |

| :--- | :--- | :--- |

| **MOSI** | GPIO 6 | Data Out |

| **MISO** | GPIO 5 | Data In |

| **SCK** | GPIO 7 | Clock |

| **CS** | GPIO 4 | Chip Select |

### 📺 2. TFT GC9A01 Display (Software SPI)
| TFT pins | ESP32-C3 pin | Function |
| :--- | :--- | :--- |
| **SCL** | GPIO 0 | Clock |
| **SDA** | GPIO 1 | Data |
| **DC** | GPIO 2 | Data/Command |
| **RST** | GPIO 3 | Reset |
| **CS** | GPIO 10 | Chip Select |

---

## 📚 Required Libraries (Dependencies)
To compile the code, you need to install the following libraries via the **Library Manager** on the Arduino IDE:
* `Adafruit_GFX`
* `Adafruit_GC9A01A`
* `SD` and `FS` (Available in the ESP32 core package)

## 🚀 Current Features
- Completely fixed the missing 16-bit color code definition error (`BLACK`, `WHITE`, `DARKGREY`,...).

- Separated SPI bus to allow simultaneous SD card programming with the screen without freezing (`Failed`).

- Designed rounded corners for the main UI interface and button screen transition effects.
