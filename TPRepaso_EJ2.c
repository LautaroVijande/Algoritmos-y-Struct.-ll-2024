#include <stdio.h>                    //Libreria


int Num();                        //funcion         

int main(void) 
{                          
  printf ("ingresar 10 numeros\n");   //imprimo en pantalla  
  Num();                              //ingreso la funcion al main

  return 0;
}

int Num()                            //inicializacion de la funcion
{
  int num,mayor,cont=1;              //variables de la funcion
  scanf("%i",&num);                  //input de teclado
  mayor=num;                         //igualo mayor a num


  for (int i=0;i<9;i++)              //ciclo repetitivo  
  {
    scanf("%i",&num);                //input de teclado

    if (num>mayor)                   //comparo                   
    {
      mayor=num;                     //actualizo el valor
      cont=0;                        //contado lo defino como 0
    }
    if (num==mayor)                  //comparo la igualdad de num y mayor
    {
      cont++;                        //sumo en contador
    }


  }
  printf("el numero mayor es %i y fue ingresado %i veces",mayor,cont); //imprimo en pantalla 
  return 0;
}