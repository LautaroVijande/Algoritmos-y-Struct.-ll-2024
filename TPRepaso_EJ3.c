#include <stdio.h>                                                           //incluyo las librerias necesarias
#include <string.h>
#include <stdlib.h>

typedef struct Producto                                                      //struc de productos
{
  int id;
  char articulo[20];
  int cantidad;
  float precio;
  float precioFinal;

} Producto;

typedef struct Nodo                                                                //defino el nodo
{
  struct Producto datos;                                                         //vinculo el nodo con la estructura
  struct Nodo* follow;                                                          //vinculo el nodo con el siguiente

}Nodo;

int menu();                                                                  //prototipado de funciones 
float TipoFactura();
Nodo* agregar(Nodo*, Producto);
Nodo* nuevoNodo();
void mostrarLista(Nodo*);
void Mayor(Nodo*);
void Prom(Nodo*, int);

int main(void) {
  int opcion,contID=1,cantProd;                                              //defino variables
  float iva=0.21,subtotal;
  Nodo *pri;                                                                //define el nodo 
  pri = NULL;
  Producto prod;                                                             //defino el producto
  
  do                                                                         //ciclo Do
  {    
    switch (opcion)                                                          //seleccion de menu
    {    
      case 1:
        iva=TipoFactura();                                                   //llamo a la funcion que elige el tipo de factura
        break;
      
      case 2:                                             //ingreso de datos
        printf("\n¿Cantidad de productos ingresados a la facturacion?: ");        
        scanf("%i",&cantProd);                                               
                                                      
       
        for (int i=0; i<cantProd; i++)                          //ciclo repetitivo             
        {
          prod.id = contID++;                                                
          printf("\nNombre del Articulo: ");                          
          fgets(prod.articulo ,sizeof(prod.articulo),stdin);                
                         

          printf("\nValor: ");                                   
          scanf("%f",&prod.precio);                                          
                                                     

          printf("\nCantidad: ");                                    
          scanf("%i",&prod.cantidad);                                        
                                                     

          subtotal=prod.precio*prod.cantidad;                                //calculo subtotal
          prod.precioFinal = subtotal + (subtotal*iva);                      //calculo de iva 
          pri=agregar(pri, prod);                                          //agrego a la lista       
        }                        
        break;
      
      case 3:      //busco promedio  
        Prom(pri, contID);                                            
        break;
        
      
      case 4:  //busco mayor
        Mayor(pri);                                                  
        break;
    }    
    opcion=menu();                                                           
  }while (opcion !=0);                                                       
  return 0;
}
int menu()
{
  int opcion;                                                                
  system ("clear");           //menu
  printf("1) FACTURA: \n");
  printf("2) PRODUCTOS: \n");
  printf("3) PROMEDIO: \n");
  printf("4) MAYOR: \n\n");
  printf("0) Salir\n");
  printf ("\nElija una opción del menu principal: ");
  scanf ("%i",&opcion); 
  return opcion;
}

Nodo* nuevoNodo()                                                             //funcion que crea un nodo
{
  Nodo* UNO;                                                                   
  UNO=(Nodo*)malloc(sizeof(Nodo));                                              
  UNO->follow=NULL;                                                                
  return UNO;                                                                   
}

Nodo* agregar(Nodo *pri,Producto prod)        //nodo para agregar                               
{
  Nodo* UNO=pri;                                                              
  
  if (UNO==NULL)           //condiciones                                                     
  {
  UNO=nuevoNodo();                                                            
    UNO->datos=prod;                                                            
    return UNO;                                                                 
  }
  
  while (UNO->follow!=NULL)                                                        
  {
    UNO=UNO->follow;                                                                
  }
 
  Nodo* nuevo=nuevoNodo();                                                    
  UNO->follow=nuevo;                                                               
  nuevo->datos=prod;                                                          
  return pri;                                                              
}

void Prom(Nodo* lista, int contID)                                       //funcion de promedio
{
  Nodo* DOS;                                                                     
  DOS=lista;                                                                     

  float suma=0,prom=0;                                                       

  while (DOS!=NULL)      //condicion                                                       
  {
    suma+=DOS->datos.precioFinal;                                               
    DOS=DOS-> follow;                                                                    
  }  
  contID--;                                                                    
  prom=suma/contID;                                                            
  printf("\nPROMEDIO %i PRODUCTOS ES: $%.2f ",contID,prom);  
}

void Mayor(Nodo* lista)                                                 //funcion mayor  
{
  Nodo* TRES;                                                                    
  TRES=lista;                                                                    

  int IdMayor,CantidadMayor;                                                  
  char ArticuloMayor[20];
  float PrecioMayor;
  float PrecioFinalMayor;

  float mayor;                                                                 
  mayor=TRES->datos.precioFinal;                                                  
  IdMayor=TRES->datos.id;
  strcpy(ArticuloMayor,TRES->datos.articulo);
  CantidadMayor=TRES->datos.cantidad;
  PrecioMayor=TRES->datos.precio;
  PrecioFinalMayor=TRES->datos.precioFinal;

  while (TRES!=NULL)                                                         //condicion     
  {
    if (TRES->datos.precioFinal>mayor)                                            
    { 
      mayor=TRES->datos.precioFinal;                                             
      IdMayor=TRES->datos.id;
      strcpy(ArticuloMayor,TRES->datos.articulo);
      CantidadMayor=TRES->datos.cantidad;
      PrecioMayor=TRES->datos.precio;
      PrecioFinalMayor=TRES->datos.precioFinal;
    }
    TRES=TRES->follow;                                                                  
  }    
  printf("\n\nEL EL MAYOR ES: \n");                             
  printf("\nID: %i ARTICULO: %s PRECIO: %.2f: CANTIDAD: %i: FINAL $%.2f: ",IdMayor, ArticuloMayor,PrecioMayor,CantidadMayor,PrecioFinalMayor);
  
}

float TipoFactura()                                                          
{
  int opcion;                                                               
  float iva;                                                                  
  printf("1) Responsable Inscripto: \n");
  printf("2) Consumidor Final: \n");
  printf("3) EXCENTO: \n");
  printf("\nTIpo Factura: ");
  scanf("%i",&opcion);                                                       
  
  switch (opcion)        //seleccion                                                      
  {
    case 1:                                                                   
      printf("Resposable Inscripto - 10,5%% aplicado");          
      iva=0.105;                                                              
      break;
    
    case 2:
      printf("COnsumidor Final -  21%% aplicado");                  
      iva=0.21;                                                               
      break;
    
    case 3:
      printf("Bienes y Servicios - 27%% aplicable");                
      iva=0.27;                                                               
      break;
  }
  return iva;                                                                 
}





