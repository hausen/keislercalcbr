#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(int argc, char *argv[]) {
  double n = 0.0;
  int linenum = 1;

  while (n < 10.01) {
    int i = 0;
    printf("  %2.0f ", n);
    for (i = 0; i < 10; ++i) {
      double ln = log(n);
      if (fabs(n-1.0) < 0.09) {
        printf("& 0.000 ", ln);
      } else if (n > 0) {
        printf("& %0.3f ", ln);
      } else {
        printf("&        ", ln);
      }
      n += .1;
    }
    puts("\\\\");
  }

}
