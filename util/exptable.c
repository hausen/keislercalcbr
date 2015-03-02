#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(int argc, char *argv[]) {
  double x = 0.0;
  int linenum = 1;

  puts("\\begin{tabular}{|r@{.}l|r@{.}l r@{.}l|}");
  puts("  \\hline");
  puts("  $x$ & $\\e^x$ & $\\e^{-x}$ \\\\");
  puts("\\hline");
  while (x < 6.05) {
    char buf[256];
    int idx;
    double ex = exp(x);
    double emx = exp(-x);
    char fmt[256];
    strcpy(fmt, "  %01.01f & ");
    if (ex >= 100.0) {
      ex = round(ex);
      strcat(fmt, "%3.0f & ");
    } else if (ex >= 10.0) {
      ex = round(ex*10)/10;
      strcat(fmt, "%3.1f & ");
    } else {
      strcat(fmt, "%3.2f & ");
    }
    if (emx >= 1.0) {
      strcat(fmt, "%1.2f");
    } else if (emx >= 0.01) {
      strcat(fmt, "%1.3f");
    } else {
      strcat(fmt, "%1.4f");
    }
    
    snprintf(buf, sizeof(buf), fmt, x , ex, emx);
    buf[sizeof(buf)-1] = '\0';
    printf("%s", buf);
    if (linenum % 5 == 0) {
      puts("\\\\[1ex]");
    } else {
      puts("\\\\");
    }
    x += 0.1;
    ++linenum;
  }
  puts("  \\hline");
  puts("\\end{tabular}");

}
