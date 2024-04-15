#include <stdio.h>                           //libreria


int Mayor(int*);                            //funcion

int main(void) //main
{
  int Numeros[10];                           //defino el vector
  printf ("ingresar 10 numeros\n");          //imprimir en pantalla
  
  for (int i=0;i<10;i++)                     //ciclo repetitivo 
  {
    scanf ("%i",&Numeros[i]);                //input de datos de teclado
  }
  Mayor(Numeros);                         //guardo los datos en mi vector declarado

    return 0;
}

int Mayor(int* vec)                   //busqueda del numero en el vector
{
  int mayor=vec[0],cont=0;               //defino las variables (mayor y contador)
  
  for (int i=0;i<10;i++)                 //ciclo repetitivo
  {
    if (vec[i]>mayor)                    //comparacio de vec con mayor
    {
      mayor=vec[i];                      //modifico la variable si es necesario
    }
  }
  for (int i=0;i<10;i++)                 //ciclo repetitivo
  {
    if (mayor==vec[i])                   //condicion
    {
      cont++;                            //aumento
    }
  }
  printf("el numero mayor es %i y fue ingresado %i veces",mayor,cont); //imprimo el resultado en pantalla
  return 0;
}