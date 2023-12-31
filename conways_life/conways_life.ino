#include <U8g2lib.h>

#define GEN_0 0b01000000
#define GEN_1 0b10000000
#define NEIGHBORS 0b00011111
#define BOARD_WIDTH 128
#define BOARD_HEIGHT 64
#define DIVBITS 16  // this must be the same as the bit length for the uint##_t used for compact state representation

// set up display for heltec_wifi_kit_32_v3
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ 21, /* clock=*/ 18, /* data=*/ 17);

// set up game board
uint8_t game_board[BOARD_HEIGHT][BOARD_WIDTH];

// a reasonably compact form to represent the prior states
uint16_t state_rep_0[BOARD_HEIGHT][BOARD_WIDTH / DIVBITS];
uint16_t state_rep_1[BOARD_HEIGHT][BOARD_WIDTH / DIVBITS];


void init_board(uint8_t board[BOARD_HEIGHT][BOARD_WIDTH], uint16_t rep_0[BOARD_HEIGHT][BOARD_WIDTH / DIVBITS], uint16_t rep_1[BOARD_HEIGHT][BOARD_WIDTH / DIVBITS]) {
  Serial.println("Seeding random number generator.");
  randomSeed(analogRead(1));
  
  Serial.println("Randomizing board.");
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      game_board[i][j] = random(0, 2) ? GEN_0 : 0;
    }
  }

  Serial.println("Zeroing prior state representations.");
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH / DIVBITS; j++) {
      rep_0[i][j] = 0;
      rep_1[i][j] = 0;
    }
  }
}


bool is_different(uint16_t prior_rep[BOARD_HEIGHT][BOARD_WIDTH / DIVBITS], uint16_t curr_rep[BOARD_HEIGHT][BOARD_WIDTH / DIVBITS]) {
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH / DIVBITS; j++) {
      if (prior_rep[i][j] != curr_rep[i][j]) { return true; }
    }
  }
  return false;
}


bool doLife(uint8_t board[BOARD_HEIGHT][BOARD_WIDTH], uint8_t mask, uint16_t prior_rep[BOARD_HEIGHT][BOARD_WIDTH / DIVBITS]){
  // create a binary representation of our current
  // state for comparison with prior_rep[][]
  uint16_t curr_rep[BOARD_HEIGHT][BOARD_WIDTH / DIVBITS];

  // change masks
  uint8_t alt_mask = (mask == GEN_0) ? GEN_1 : GEN_0;

  u8g2.clearBuffer();
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

      // compact rep accounting
      curr_rep[i][j % DIVBITS] = curr_rep[i][j % DIVBITS] << 1;
      
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
          curr_rep[i][j % DIVBITS] |= 1; // compact rep accounting
        }
      } else if ((board[i][j] & NEIGHBORS) == 3) {
        board[i][j] |= alt_mask;
        u8g2.drawPixel(j, i);
        curr_rep[i][j % DIVBITS] |= 1; // compact rep accounting
      }
    }
  }
  u8g2.sendBuffer();

  if (is_different(prior_rep, curr_rep)) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
      for (int j = 0; j < BOARD_WIDTH / DIVBITS; j++) {
        prior_rep[i][j] = curr_rep[i][j];
      }
    }
    return true;
  } else {
    return false;
  }
}


void setup() {
  Serial.begin(115200);
  
  Serial.println("Setting up display.");
  u8g2.begin();

  init_board(game_board, state_rep_0, state_rep_1);

  Serial.println("Beginning Conway's Game of Life");
}


void loop() {
  if (not doLife(game_board, GEN_0, state_rep_0)) {
    Serial.println("Detected a stable state. Restarting.");
    delay(500);
    init_board(game_board, state_rep_0, state_rep_1);
  }
  if (not doLife(game_board, GEN_1, state_rep_1)) {
    Serial.println("Detected a stable state. Restarting.");
    delay(500);
    init_board(game_board, state_rep_0, state_rep_1);
  }
}
