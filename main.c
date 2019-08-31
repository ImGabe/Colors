#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>

void centralizeColors(int col, int number) {
  char text[121];
  char color[17] = "";
  strcpy(text, "");

  for (int i = 40; i < (40 + number); ++i) {
    sprintf(color, "\033[%dm      \033[0m  ", i);
    strcat(text, color);
  }

  int padlen = (col - (8 * number)) / 2;
  printf("\n");
  printf("%*s%s%*s\n", padlen, "", text, padlen, "");
  printf("%*s%s%*s\n", padlen, "", text, padlen, "");
  printf("\n");
}

int main(int argc, char const *argv[]) {
  struct winsize win;
  ioctl(0, TIOCGWINSZ, &win);

  if (argc > 1) {
    int number = atoi(argv[1]);
    (8 > number && number > 0) ? centralizeColors(win.ws_col, number)
                               : centralizeColors(win.ws_col, 8);
  } else {
    pcentralizeColors(win.ws_col, 8);
  }

  return 0;
}
