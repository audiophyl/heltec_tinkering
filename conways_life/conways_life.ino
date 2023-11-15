#include <U8g2lib.h>

#define GEN_0 0b01000000
#define GEN_1 0b10000000
#define NEIGHBORS 0b00011111
#define BOARD_WIDTH 128
#define BOARD_HEIGHT 64


// set up display for heltec_wifi_kit_32_v3
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 18, /* data=*/ 17, /* reset=*/ 21);

// set up game board
uint8_t game_board[BOARD_HEIGHT][BOARD_WIDTH];


void setup() {
  Serial.begin(115200);
  
  Serial.println("Setting up display.");
  u8g2.begin();

  Serial.println("Seeding random number generator.");
  randomSeed(analogRead(1));

  Serial.println("Randomizing board.");
  for (int i = 0; i < BOARD_HEIGHT; i++){
    for (int j = 0; j < BOARD_WIDTH; j++) {
      game_board[i][j] = random(0, 2) ? GEN_0 : 0;
    }
  }

  Serial.println("Beginning Conway's Game of Life");
}


void doLife(uint8_t board[BOARD_HEIGHT][BOARD_WIDTH], uint8_t mask){
  u8g2.clearBuffer();
  uint8_t alt_mask = (mask == GEN_0) ? GEN_1 : GEN_0;
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      // clear neighbor accounting bits and prior generation state
      board[i][j] &= ~(alt_mask | NEIGHBORS);

      // count neighbors
      int tmp_i = i + BOARD_HEIGHT;
      int tmp_j = j + BOARD_WIDTH;
      if (board[(tmp_i - 1) % BOARD_HEIGHT][(tmp_j - 1) % BOARD_WIDTH] & mask) board[i][j]++;
      if (board[(tmp_i - 1) % BOARD_HEIGHT][(tmp_j) % BOARD_WIDTH] & mask) board[i][j]++;
      if (board[(tmp_i - 1) % BOARD_HEIGHT][(tmp_j + 1) % BOARD_WIDTH] & mask) board[i][j]++;
      if (board[(tmp_i) % BOARD_HEIGHT][(tmp_j - 1) % BOARD_WIDTH] & mask) board[i][j]++;
      if (board[(tmp_i) % BOARD_HEIGHT][(tmp_j + 1) % BOARD_WIDTH] & mask) board[i][j]++;
      if (board[(tmp_i + 1) % BOARD_HEIGHT][(tmp_j - 1) % BOARD_WIDTH] & mask) board[i][j]++;
      if (board[(tmp_i + 1) % BOARD_HEIGHT][(tmp_j) % BOARD_WIDTH] & mask) board[i][j]++;
      if (board[(tmp_i + 1) % BOARD_HEIGHT][(tmp_j + 1) % BOARD_WIDTH] & mask) board[i][j]++;

      // implement the holy rules!
      // is the cell alive in this generation?
      // if yes and it has too few or too many neighbors, it dies.
      // if yes and it has the right number of neighbors, it stays alive.
      // if no and it has the right number of neighbors, it becomes alive.
      if (board[i][j] & mask) {
        if (((board[i][j] & NEIGHBORS) < 2) || ((board[i][j] & NEIGHBORS) > 3)) {
          board[i][j] &= ~alt_mask;
        } else {
          board[i][j] |= alt_mask;
          u8g2.drawPixel(j, i);
        }
      } else if ((board[i][j] & NEIGHBORS) == 3) board[i][j] |= alt_mask;
    }
  }
  u8g2.sendBuffer();
}


void loop() {
  doLife(game_board, GEN_0);
  doLife(game_board, GEN_1);
}
