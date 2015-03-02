#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(int argc, char *argv[]) {
  double n = 1.0;
  int linenum = 1;

  while (n < 50.01) {
    printf("  %3.0f & \\fnum{%5.0f} & %2.3f & \\fnum{%7.0f} & %1.3f & "
           "  %3.0f & \\fnum{%5.0f} & %2.3f & \\fnum{%7.0f} & %1.3f \\\\\n",
              n,      n*n,            sqrt(n), n*n*n, pow(n, 1.0/3.0), 
              n+50.,   (n+50.)*(n+50.),  sqrt(n+50.), (n+50.)*(n+50.)*(n+50.),
              pow(n+50., 1.0/3.0) );
    n += 1;
  }

}
