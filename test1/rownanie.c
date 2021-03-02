#include <stdio.h>
#include <math.h>
/*Program nalezy uruchomic z komenda -lm*/

struct TrojmianKw {
  double  a;
  double  b;
  double  c;
};


typedef struct TrojmianKw  TrojmianKw;



int main() {
  TrojmianKw   TKw;
  double       Delta, Delta_2;
  double       X1, X2;
  int          Ilosc_Pierwiastkow;
  
  printf("Program wylicza rozwiazania trojmianu kwadratowego.\n");
  printf("Podaj wspolczynnik a:\n");
  scanf("%lf", &TKw.a);
  printf("Podaj wspolczynnik b:\n");
  scanf("%lf", &TKw.b);
  printf("Podaj wspolczynnik c:\n");
  scanf("%lf", &TKw.c);


  if (TKw.a == 0) {
    printf("Wprowadzone wsplczynniki a musi byc rozny od zera.\n");
    return 1;
  }


  printf(" Postac trojmianu kwadratowego: %fx^2 + %fx + %f\n",TKw.a,TKw.b,TKw.c);
  
  Delta_2  = (TKw.b*TKw.b) - (4.0*TKw.a*TKw.c);

  
  if (Delta_2 > 0) {

      Delta = sqrt( Delta_2 );
      X1 = (-TKw.b - Delta) / (2*TKw.a);
      X2 = (-TKw.b + Delta) / (2*TKw.a);
      Ilosc_Pierwiastkow = 2;      

  } else if  (Delta_2 == 0) {

      X1 = -TKw.b/(2*TKw.a);
      Ilosc_Pierwiastkow = 1;

  } else { /* czyli d <= 0 */
      Ilosc_Pierwiastkow = 0;
  }


  switch (Ilosc_Pierwiastkow) {
    case 2:
      printf("Istnieja dwa rozwiazania rzeczywiste:\n");
      printf("  x1 = %f\n", X1);
      printf("  x2 = %f\n", X2);
      break;

    case 1:
      printf("Istnieje jedno rozwiazanie: %f\n", X1);
      break;

    case 0:
      printf("Nie istnieje rozwiazanie w zbiorze liczb rzeczywistych\n");      
      break;
  }

  return 0;
}





/*Aby rozwiazac problem nalezalo w printfach zamienic %lf na %f, poniewaz iso nie wspiera fomatu %lf */

