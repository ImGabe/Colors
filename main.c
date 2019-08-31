#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>

void centralizeColors(int col) {
  char text[121];
  char color[17] = "";
  strcpy(text, "");

  for (int i = 40; i < 48; ++i) {
    sprintf(color, "\033[%dm      \033[0m  ", i);
    strcat(text, color);
  }

  int padlen = (col - 64) / 2;
  printf("\n");
  printf("%*s%s%*s\n", padlen, "", text, padlen, "");
  printf("%*s%s%*s\n", padlen, "", text, padlen, "");
  printf("\n");
}

int main() {
  struct winsize win;
  ioctl(0, TIOCGWINSZ, &win);
  centralizeColors(win.ws_col);
  return 0;
}