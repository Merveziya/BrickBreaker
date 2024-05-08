#include <LiquidCrystal.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <LiquidCrystal_I2C.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3D
#define led1 13
#define led2 12
#define led3 11
#define displayA1 29
#define displayB1 30
#define displayC1 31
#define displayD1 32
#define displayE1 33
#define displayF1 34
#define displayG1 35
#define displayA2 36
#define displayB2 37
#define displayC2 38
#define displayD2 39
#define displayE2 40
#define displayF2 41
#define displayG2 42
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


//PLATFORM ÇİZİMİ
const unsigned char nplatform[] PROGMEM = {
  B11110000,
  B11110000,
  B11110000,
  B11110000,
  B11110000,
  B11110000,
  B11110000,
  B11110000
  };

// top cismi eklendi
  const unsigned char ntop[] PROGMEM = {
  B00011000,
  B00111100,
  B01111110,
  B01111110,
  B01111110,
  B01111110,
  B00111100,
  B00011000
  };

const unsigned char ncanodul[] PROGMEM = {
  B00111100,
  B01000110,
  B01010101,
  B01111101,
  B01010101,
  B01000110,
  B00111100,
  B00000000
};


boolean menuu = false;
int whilehiz = 1000;

boolean menumillesbool = false;
unsigned long menumilles = 0;
int can;
boolean gamemillesbool = false;
unsigned long gamemillesson = 0;
unsigned long gamemillesilk = 0;

unsigned long hizlanmamilles = 0;
unsigned long sayachizlanma = 1;

int platformhiz ;
unsigned long platformsure = 0;
boolean hizlanma = false;

unsigned long hareketZamani;
unsigned long lastDecrease = 0;
unsigned long decreaseDelay = 10000000; 

int selected = 0;
int entered = -1;


int x = random(8);
int y = 0;
int skor = 0;


int odulX;
int odulY;
boolean odul = false;
int odulsure = 0;

boolean beklet = false;

int xtop;
int ytop;
boolean top=false;
int tophiz=200;


int hiz = 1;

int bitis = 1;

int kirilanTuglaSayisi=0;

int sayac = 0;

const char *renk[2] = {
  " WHITE ",
  " BLACK "
};

int potPin = A1;
int pot_deger = 0;
boolean a1 = false;
boolean a2 = false;


boolean sil = false;


void menusifirlamalari(void){
 whilehiz = 1000;
 menumillesbool = false;
 menumilles = 0;
 gamemillesbool = false;
 gamemillesson = 0;
 gamemillesilk = 0;
 hizlanmamilles = 0;
 sayachizlanma = 1;
 platformhiz ;
 platformsure = 0;
 hizlanma = false;

 selected = 0;
 entered = -1;
 
 x = random(8);
 y = 0;
 skor = 0;

 odulX;
 odulY;
 odul = false;
 odulsure = 0;
 beklet = false;
 
 xtop;
 ytop;
 top=false;
 hiz = 1;
 bitis = 1;
 can = 3;
 sayac = 0;
 a1 = false;
 a2 = false;
 
 sil = false;
 menuu = false;

}
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void displaygosterim1(int secim) {
  switch (secim) {
    case 0:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, HIGH);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, LOW);
      break;
    case 1:
      digitalWrite(displayA1, LOW);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, LOW);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, LOW);
      digitalWrite(displayG1, LOW);
      break;
    case 2:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, LOW);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, HIGH);
      digitalWrite(displayF1, LOW);
      digitalWrite(displayG1, HIGH);
      break;
    case 3:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, LOW);
      digitalWrite(displayG1, HIGH);
      break;
    case 4:
      digitalWrite(displayA1, LOW);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, LOW);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, HIGH);
      break;
    case 5:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, LOW);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, HIGH);
      break;
    case 6:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, LOW);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, HIGH);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, HIGH);
      break;
    case 7:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, LOW);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, LOW);
      digitalWrite(displayG1, HIGH);
      break;
    case 8:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, HIGH);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, HIGH);
      break;
    case 9:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, HIGH);
      break;
  }
}

void displaygosterim2(int secim) {
  switch (secim) {
    case 0:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, HIGH);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, LOW);
      break;
    case 1:
      digitalWrite(displayA2, LOW);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, LOW);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, LOW);
      digitalWrite(displayG2, LOW);
      break;
    case 2:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, LOW);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, HIGH);
      digitalWrite(displayF2, LOW);
      digitalWrite(displayG2, HIGH);
      break;
    case 3:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, LOW);
      digitalWrite(displayG2, HIGH);
      break;
    case 4:
      digitalWrite(displayA2, LOW);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, LOW);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, HIGH);
      break;
    case 5:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, LOW);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, HIGH);
      break;
    case 6:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, LOW);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, HIGH);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, HIGH);
      break;
    case 7:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, LOW);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, LOW);
      digitalWrite(displayG2, HIGH);
      break;
    case 8:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, HIGH);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, HIGH);
      break;
    case 9:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, HIGH);
      break;
  }
}



void Game(void) {
  unsigned long whilemillis = 1000;  
  gamemillesilk = millis();
  int asss;
  asss = analogRead(A0);
  if (asss >= 425) {  // karanlık{
    renk[0] = "BLACK";
    a1 = true;
    a2 = false;
  }
  if (asss < 425) {  // karanlık{
    renk[1] = "WHITE";
    a2 = true;
    a1 = false;
  }
  display.clearDisplay();
  if (a1 == true) {
    display.fillScreen(BLACK);
  } else if (a2 == true) {
    display.fillScreen(WHITE);
  }
  pot_deger = analogRead(potPin);
  if (can == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  


//Tuğla İşlemleri
if (a1 == true) {
topHareketi();
}

if (a2 == true) {
   display.fillRect(120, 0, 12, 14, 0);
    display.drawRect(120, 0, 12, 14, 1);
    display.fillRect(120, 12, 12, 14, 0);
    display.drawRect(120, 12, 12, 14, 1);
    display.fillRect(120, 24, 12, 14, 0);
    display.drawRect(120, 24, 12, 14, 1);
    display.fillRect(120, 36, 12, 14, 0);
    display.drawRect(120, 36, 12, 14, 1);
    display.fillRect(120, 48, 12, 14, 0);
    display.drawRect(120, 48, 12, 14, 1);
    display.fillRect(110, 0, 12, 14, 0);
    display.drawRect(110, 0, 12, 14, 1);
    display.fillRect(110, 12, 12, 14, 0);
    display.drawRect(110, 12, 12, 14, 1);
    display.fillRect(110, 24, 12, 14, 0);
    display.drawRect(110, 24, 12, 14, 1);
    display.fillRect(110, 36, 12, 14, 0);
    display.drawRect(110, 36, 12, 14, 1);
    display.fillRect(110, 48, 12, 14, 0);
    display.drawRect(110, 48, 12, 14, 1);
    display.fillRect(100, 0, 12, 14, 0);
    display.drawRect(100, 0, 12, 14, 1);
    display.fillRect(100, 12, 12, 14, 0);
    display.drawRect(100, 12, 12, 14, 1);
    display.fillRect(100, 24, 12, 14, 0);
    display.drawRect(100, 24, 12, 14, 1);
    display.fillRect(100, 36, 12, 14, 0);
    display.drawRect(100, 36, 12, 14, 1);
    display.fillRect(100, 48, 12, 14, 0);
    display.drawRect(100, 48, 12, 14, 1);
    display.fillRect(90, 0, 12, 14, 0);
    display.drawRect(90, 0, 12, 14, 1);
    display.fillRect(90, 12, 12, 14, 0);
    display.drawRect(90, 12, 12, 14, 1);
    display.fillRect(90, 24, 12, 14, 0);
    display.drawRect(90, 24, 12, 14, 1);
    display.fillRect(90, 36, 12, 14, 0);
    display.drawRect(90, 36, 12, 14, 1);
    display.fillRect(90, 48, 12, 14, 0);
    display.drawRect(90, 48, 12, 14, 1);
}
  
  if (pot_deger < 256) {
  //platformun saga sola gitmesi 
     
      delay(50);
    if (x > 0) {
      
      x--;
     
      delay(50);
    }
  }
  if (pot_deger >= 256 && pot_deger < 512) {
    
    if (x < 7) {

      x++;

      delay(50);
    }
    
  }
  
  if (a1 == true) {
    
    display.drawBitmap(y * 8, x * 8, nplatform, 8, 8, WHITE);
  }
  if (a2 == true) {
    display.drawBitmap(y * 8, x * 8, nplatform, 8, 8, BLACK);
  }


  if (bitis == 0) {
    menuu = true;
  }
  
  odulsure++;
  display.display();
  gamemillesson = millis();

  platformsure = gamemillesson - menumilles;
  if (hizlanma == true && platformsure >= 10000 * sayachizlanma) {
    sayachizlanma++;
    whilehiz = whilehiz-(whilehiz * 0.2);
  }
  while(whilemillis==0){
    gamemillesson = millis();
    gamemillesson = gamemillesson - (gamemillesilk);    
    if(gamemillesson>=whilehiz){
      whilemillis = 1;
    }
  }
}


void anaMenu(void) {
  int down = digitalRead(17);
  int up = digitalRead(18);
  int enter = digitalRead(16);
  int back = digitalRead(15);
  
 // Menüde aşağı hareket
 if (down == 0) {
    selected--;
    if (selected < 0) {
      selected = 2; 
    }
    delay(200); 
  }
  
  // Menüde yukarı hareket
  if (up == 0) {
    selected++;
    if (selected > 2) {
      selected = 0;
    }
    delay(200); 
  }

  // Menü seçimi
  if (enter == 0) {
    entered = selected;
    delay(200);
  }

  // Geri dönme
  if (back == 0) {
    entered = -1;
    delay(200);
  }

  const char *options[2] = {
    " BASLA ",
   // " SEVIYE ",
    " CIKIS"
  };
  if (entered == -1) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.setRotation(1);
    display.println(F("<<<Menu>>>"));
    display.println("");
    for (int i = 0; i < 2; i++) {
      if (i == selected) {
        display.setTextColor(BLACK, WHITE);
        display.println(options[i]);
      } else if (i != selected) {
        display.setTextColor(WHITE);
        display.println(options[i]);
      }
    }
  } else if (entered == 0) {
    display.setRotation(4);
    if (menumillesbool == false) {
      menumilles = millis();
      menumillesbool = true;
    }
    Game();
  } 
  else if(entered == 1){
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.println("Oyunumuza gosterdiginiz ilgi icin tesekkurler !");
  }
  display.display();
}
void setup() {
  Serial.begin(9600);
  pinMode(18, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(displayA1, OUTPUT);
  pinMode(displayB1, OUTPUT);
  pinMode(displayC1, OUTPUT);
  pinMode(displayD1, OUTPUT);
  pinMode(displayE1, OUTPUT);
  pinMode(displayF1, OUTPUT);
  pinMode(displayG1, OUTPUT);
  pinMode(displayA2, OUTPUT);
  pinMode(displayB2, OUTPUT);
  pinMode(displayC2, OUTPUT);
  pinMode(displayD2, OUTPUT);
  pinMode(displayE2, OUTPUT);
  pinMode(displayF2, OUTPUT);
  pinMode(displayG2, OUTPUT);
  //displaygosterim(0);
  displaygosterim1(0);
  displaygosterim2(0);
  can = 3;
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  
}


const int ekranGenisligi = 128;  // Ekranın genişliğini piksel cinsinden girin.
const int nPlatformGenisligi = 16;
const int nPlatformX = ekranGenisligi / 2 - nPlatformGenisligi / 2;
int odulX2 = -1; // Ödülün X koordinatı
int odulY2 = -1; // Ödülün Y koordinatı
bool odulVar = false;
// Ödülün hareket hızı
int odulHizi = 1;
static int topX = -1; 
static int topY = -1; 
const int TUGLA_SAYISI_X = 5;  
const int TUGLA_SAYISI_Y = 5;

const int ledPins[] = {led1, led2, led3}; 

//CAN İÇİN LEDLERİN SÖNDÜRÜLMESİ İŞLEMLERİ
void ledGuncelle() {
   
    digitalWrite(led1, can >= 1 ? HIGH : LOW);
    digitalWrite(led2, can >= 2 ? HIGH : LOW);
    digitalWrite(led3, can >= 3 ? HIGH : LOW);
}


bool tuglaMatrisi[TUGLA_SAYISI_Y][TUGLA_SAYISI_X] = { 
  { true, true, true, true, true },
  { true, true, true, true, true },
  { true, true, true, true, true },
  { true, true, true, true, true },
  { true, true, true, true, true }
};


const int tuglaSayisi = 25;
int tuglaKoordinatlari[TUGLA_SAYISI_Y * TUGLA_SAYISI_X][2];

//SEVEN SEGMENTTE CANIN ARTIRILARAK GÖSTERİMİ
void sevenSegmentGosterim() {
  kirilanTuglaSayisi++;
  sevenSegmentIslemleri(kirilanTuglaSayisi);
}

//SEGMENT İŞLEMLERİ
void sevenSegmentIslemleri(int skor) {
  int ikinci = (skor / 10) % 10;
  int ilk = skor % 10;

  displaygosterim1(ikinci);
  displaygosterim2(ilk);
}


//CANLAR BİTTİKTEN SONRA OYUNU BAŞA SARMA
void oyunuSifirla() {
  can = 3;
  ledGuncelle();

  // Tuğla matrisini yenile
  for (int i = 0; i < TUGLA_SAYISI_Y; i++) {
    for (int j = 0; j < TUGLA_SAYISI_X; j++) {
      tuglaMatrisi[i][j] = true;
    }
  }

  //LEDLERİ SIFIRLA
  //displaygosterim(0);
  displaygosterim1(0);
  displaygosterim2(0);

  //TOPUN KONUMUNU SIFIRLA
  topX = 0;
  topY = 0;

}

void topHareketi() {
    const int baslangicX = 0; 
    const int baslangicY = 48; 

    static bool hareketYonuYukari = true;
    static bool hareketYonuSaga = true; 
    const int topYuksekligi = 8;  
    const int ekranYuksekligi = 64;  
    const int topCapi = 8; 

    // Tuğla koordinatları
   for (int i = 0; i < TUGLA_SAYISI_Y; i++) {
        for (int j = 0; j < TUGLA_SAYISI_X; j++) {
            int tuglaX = j * 8 + 90; 
            int tuglaY = i * 12;  

            if (tuglaMatrisi[i][j]) {
                // Tuğlayı çiz
                display.fillRect(tuglaX, tuglaY, 8, 12, WHITE);
                display.drawRect(tuglaX, tuglaY, 8, 12, BLACK);
            } else {
                // Tuğla yok, arka planı siyah yap
                display.fillRect(tuglaX, tuglaY, 8, 12, BLACK);
            }
        }
    }

    // Rastgele konum belirleme
    if (topX == -1 && topY == -1) {
        topX = baslangicX; 
        topY = baslangicY;
    }

    // Topun ekrandaki önceki konumunu silme
    display.fillRect(topX, topY, 8, 8, BLACK);
    
if (hareketYonuYukari) {
        topY--;
        // Eğer top tavana çarptıysa, yön değiştir
        if (topY <= 0) {
            hareketYonuYukari = false;
        }
    } else {
        topY++;
        // Eğer top ekranın altına gelirse ve nPlatform'in üstünde değilse, yön değiştir
        if (topY >= ekranYuksekligi - topCapi && !(topX + topCapi > nPlatformX && topX < nPlatformX + nPlatformGenisligi)) {
            hareketYonuYukari = true;
        }
    }

    // Topun Y ekseni hareketi
    if (hareketYonuSaga) {
        topX++;
        // Eğer top sağ kenara çarptıysa, yön değiştir
        if (topX >= ekranGenisligi - topCapi) {
            hareketYonuSaga = false;
        }
    } else {
        topX--;
        // Eğer top zemine çarptıysa, yön değiştir
        if (topX <= 0) {
            hareketYonuSaga = true;
            can--; // Can sayısını azalt
            ledGuncelle(); // LED'leri güncelle
            // Can bitmemişse oyunun ortasından başlat
            if (can > 0) {
                topX = ekranGenisligi / 2 - topCapi / 2; 
                topY = ekranYuksekligi / 2 - topCapi / 2; 
                hareketYonuYukari = false; // Topun yönünü değiştir
            } else {
                // Can bittiyse oyun başa dönüyor
                menuu = true;
                oyunuSifirla();
            }


        }
    }

 int topMatrisX = (topX - 90) / 8;
int topMatrisY = topY / 12;
if (topMatrisX >= 0 && topMatrisX < TUGLA_SAYISI_X && topMatrisY >= 0 && topMatrisY < TUGLA_SAYISI_Y) {
    if (tuglaMatrisi[topMatrisY][topMatrisX]) {
        // Tuğlayı kaldır ve hareket yönünü değiştir
        tuglaMatrisi[topMatrisY][topMatrisX] = false;
        
        hareketYonuYukari = !hareketYonuYukari;  // Yön değişikliği
        hareketYonuSaga = !hareketYonuSaga;      // Yön değişikliği
        sevenSegmentGosterim();
           
           if (random(100) < 10) {
                odulX2 = topX;
                odulY2 = topY;
                odulVar = true;
            }        
    }
}

 // Ödül hareketi
 odulHareketi();
      // Topun tuğlaları geçmediğini kontrol etme
    for (int i = 0; i < tuglaSayisi; i++) {
        if (topX >= tuglaKoordinatlari[i][0] && topX < tuglaKoordinatlari[i][0] + 20 &&
            topY >= tuglaKoordinatlari[i][1] && topY < tuglaKoordinatlari[i][1] + 14) {
            // Eğer top, bir tuğlada ise, hareket yönünü tersine çevir
            if (hareketYonuYukari)
                hareketYonuYukari = false;
            else
                hareketYonuYukari= true;
           tuglaKoordinatlari[i][0] = -1;
            tuglaKoordinatlari[i][1] = -1;
            break;
        }
    }

    // Topun yeni konumunu çizme
    display.drawBitmap(topX, topY, ntop, 8, 8, WHITE);
        

        //platform odulu yakalama
     if (odulX2 == nPlatformX && odulY2 == ekranYuksekligi - 10) {
    can++; // Can artırma
    ledGuncelle(); // LED'leri güncelleme
    odulVar = false; // Ödülü kaldırma
}


    
}


void odulHareketi() {
    // Eğer ödül varsa ve hala ekranın içindeyse, hareket ettir
   if (odulVar && odulY2 < display.height() - 8) {
        // Ödülü ekrandan temizle
        display.fillRect(odulX2, odulY2, 8, 8, BLACK);
        // Yeni konumunu hesapla
        odulX2 -= odulHizi;
        // Yeni konumu çiz
        display.drawBitmap(odulX2, odulY2, ncanodul, 8, 8, WHITE);
    } else {
        // Eğer ödül ekrandan taştıysa veya yoksa, etkisiz hale getir
        odulVar = false;
    }
}

void loop() {
  
  topHareketi();
  odulHareketi();
  lcd.clear();
  lcd.setCursor(xtop, ytop);
  if(menuu == true){
    menusifirlamalari();
  }
  
  anaMenu();
}