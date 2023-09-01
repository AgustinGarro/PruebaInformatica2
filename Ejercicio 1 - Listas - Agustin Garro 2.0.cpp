#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Imagenes{
	int Codigo;
	char Nombre[20];
	char Extension[20];
	int Tam;
	float Precio;
	struct Imagenes* siguiente;
}imagen;

Imagenes* primero = NULL;         //punteros a primer y ultmo nodo
Imagenes* ultimo = NULL;

void insertarNodo();        
void eliminarNodo();
void modificarNodo();
void buscarNodo();
void GuardarLista();
void leerLista();
void OrdenarLista();
void imprimirLista();

int main(int argc, char *argv[]) {
	int opcion=0;
	do{                               //menu opciones
		printf("\t1-Agregar nueva imagen\n\t2-Eliminar elemento\n\t3-Modificar\n\t4-Buscar\n\t5-Guardar y mostrar\n\t6-Salir\n");
		scanf("%d",&opcion);
		switch (opcion){
		case 1:
			insertarNodo();
			break;
		case 2:
			eliminarNodo();
			break;
		case 3:
			modificarNodo();
			break;
		case 4:
			buscarNodo();
			break;
		case 5:
			OrdenarLista();
			imprimirLista();
			GuardarLista();
			leerLista();
			break;
		}
	}while(opcion<6);	
	return 0;
}

void insertarNodo(){
	Imagenes* nuevo = (struct Imagenes*) malloc(sizeof (Imagenes));     //reseva memoria para el nuevo nodo
	printf("ingrese el Codigo: ");                 //carga los datos
	scanf("%d",&nuevo->Codigo);
	printf("ingrese el Nombre: ");
	fflush(stdin);
	gets(nuevo->Nombre);
	printf("ingrese la Extendion: ");
	fflush(stdin);
	gets(nuevo->Extension);
	printf("ingrese el Tamanho: ");
	scanf("%d",&nuevo->Tam);
	printf("ingrese el Precio: ");
	scanf("%f",&nuevo->Precio);
	
	if(primero==NULL){                  // si la lista esta vacia el nuevo nodo lo coloca en el primer lugar
		primero=nuevo;
		primero->siguiente=NULL;
		ultimo=nuevo;
	}else{                              // sino lo coloca al ultimo
		ultimo->siguiente=nuevo;
		nuevo->siguiente=NULL;
		ultimo=nuevo;
	}
	printf("\nImagen ingresada con exito\n");
}
void eliminarNodo(){
	Imagenes* actual = (struct Imagenes*) malloc(sizeof (Imagenes));       //reseva memoria para un nodo
	actual=primero;
	Imagenes* anterior = (struct Imagenes*) malloc(sizeof (Imagenes));     //reserva memoria para un nodo anterior
	anterior=NULL;
	int nodobuscado=0, nodoencontrado=0;
	printf("\nIngrese el codigo de la imagen a eliminar: ");
	scanf("%d",&nodobuscado);
	if(primero!=NULL && nodoencontrado!=1){
		while(actual!=NULL){
			if(actual->Codigo==nodobuscado){              //si el codigo buscado coincide con el codigo de algun nodo se ejecuta
				if(actual==primero){                      //si el encontrado esta en el primero, el puntero al primero lo traslada al segundo, dejando el primero afuera
					primero=primero->siguiente;
				}else if(actual==ultimo){                 //si es el ultimo, el puntero a NULL lo traslada a su anterior dejandolo afuera
					anterior->siguiente=NULL;
				}else{
					anterior->siguiente=actual->siguiente;    //si es un nodo intermedio, el puntero del anterio lo hace apuntar a su siguiente para "puentearlo"
				}
				printf("\nEl nodo fue eliminado con exito\n");
				nodoencontrado=1;
			}
			anterior=actual;
			actual=actual->siguiente;
		}
		if(nodoencontrado==0){
			printf("el nodo no se encontro");
		}else{
			free(anterior);
		}
	}else{
		printf("La lista esta vacia");
	}
}
void modificarNodo(){
	Imagenes* actual = (struct Imagenes*) malloc(sizeof (Imagenes));
	actual=primero;
	int nodobuscado=0, nodoencontrado=0;
	printf("\ningrese el codigo de la imagen a modificar: ");
	scanf("%d",&nodobuscado);
	if(primero!=NULL && nodoencontrado!=1){
		while(actual!=NULL){
			if(actual->Codigo==nodobuscado){            //al encontrar el nodo redefino cada una de los datos
				printf("\nel nodo fue encontado");
				printf("\ningrese el nuevo codigo: ");
				scanf("%d",&actual->Codigo);
				printf("ingrese el nuevo Nombre: ");
				fflush(stdin);
				gets(actual->Nombre);
				printf("ingrese la nueva Extension: ");
				fflush(stdin);
				gets(actual->Extension);
				printf("ingrese el nuevo Tamanho: ");
				scanf("%d",&actual->Tam);
				printf("ingrese el nuevo Precio: ");
				scanf("%f",&actual->Precio);
				
				nodoencontrado=1;
			}
			actual=actual->siguiente;
		}
		if(nodoencontrado==0){
			printf("el nodo no se encontro");
		}
	}else{
		printf("La lista esta vacia");
	}
}
void buscarNodo(){
	Imagenes* actual = (struct Imagenes*) malloc(sizeof (Imagenes));
	actual=primero;
	int nodobuscado=0, buscartam=0, nodoencontrado=0;
	int opcion2=0;
	char nombrebuscado[100],extbuscado[100];
	float buscarprecio=0;
	
	printf("\t\t1-Por codigo\n\t\t2-Por nombre\n\t\t3-Por extension\n\t\t4-Por tamaño\n\t\t5-Por precio\n");
	scanf("%d",&opcion2);
	switch(opcion2){
	case 1:
		printf("\nIngrese el Codigo de la imagen a buscar: ");
		scanf("%d",&nodobuscado);
		
		while(actual!=NULL){
			if(actual->Codigo==nodobuscado){
				printf("\nLa imagen fue encontada\n");
				printf("\n%d",actual->Codigo);
				printf("\n%s",actual->Nombre);
				printf("\n%s",actual->Extension);
				printf("\n%d",actual->Tam);
				printf("\n%.2f\n",actual->Precio);
				nodoencontrado++;
			}
			actual=actual->siguiente;
		}
		if(nodoencontrado==0){
			printf("\nLa imagen no se encontró\n");
		}
		break;
	case 2:
		printf("\nIngrese el nombre de la imagen a buscar: ");
		fflush(stdin);
		gets(nombrebuscado);
		
		while(actual!=NULL){
			if(strcmp(actual->Nombre,nombrebuscado)==0){
				printf("\nLa imagen fue encontada\n");
				printf("\n%d",actual->Codigo);
				printf("\n%s",actual->Nombre);
				printf("\n%s",actual->Extension);
				printf("\n%d",actual->Tam);
				printf("\n%.2f\n",actual->Precio);
				nodoencontrado++;
			}
			actual=actual->siguiente;
		}
		if(nodoencontrado==0){
			printf("\nLa imagen no se encontró\n");
		}
		break;
	case 3: 
		printf("\nIngrese la extensio de la imagen a buscar: ");
		fflush(stdin);
		gets(extbuscado);
		
		while(actual!=NULL){
			if(strcmp(actual->Extension,extbuscado)==0){
				printf("\nLa imagen fue encontada\n");
				printf("\n%d",actual->Codigo);
				printf("\n%s",actual->Nombre);
				printf("\n%s",actual->Extension);
				printf("\n%d",actual->Tam);
				printf("\n%.2f\n",actual->Precio);
				nodoencontrado++;
			}
			actual=actual->siguiente;
		}
		if(nodoencontrado==0){
			printf("\nLa imagen no se encontró\n");
		}
		break;
	case 4:
		printf("\nIngrese el tamaño de la imagen a buscar: ");
		scanf("%d",&buscartam);
		
		while(actual!=NULL){
			if(actual->Tam==buscartam){
				printf("\nLa imagen fue encontada\n");
				printf("\n%d",actual->Codigo);
				printf("\n%s",actual->Nombre);
				printf("\n%s",actual->Extension);
				printf("\n%d",actual->Tam);
				printf("\n%.2f\n",actual->Precio);
				nodoencontrado++;
			}
			actual=actual->siguiente;
		}
		if(nodoencontrado==0){
			printf("\nLa imagen no se encontró\n");
		}
		break;
	case 5:
		printf("\nIngrese el precio de la imagen a buscar: ");
		scanf("%f",&buscarprecio);
		
		while(actual!=NULL){
			if(actual->Precio==buscarprecio){
				printf("\nLa imagen fue encontada\n");
				printf("\n%d",actual->Codigo);
				printf("\n%s",actual->Nombre);
				printf("\n%s",actual->Extension);
				printf("\n%d",actual->Tam);
				printf("\n%.2f\n",actual->Precio);
				nodoencontrado++;
			}
			actual=actual->siguiente;
		}
		if(nodoencontrado==0){
			printf("\nLa imagen no se encontró\n");
		}
		break;
	}
}
void GuardarLista(){
	Imagenes* actual = (struct Imagenes*) malloc(sizeof (Imagenes));
	actual=primero;
	FILE *fp;
	int guardado;
	
	fp=fopen("ArchivoNUEVO.bin", "wb");
	if (fp != NULL) {
		printf("Apertura exitosa\n");
		if(primero!=NULL){
			while(actual!=NULL){
				guardado=fwrite(actual,sizeof(struct Imagenes),1,fp);
				if(guardado!=EOF){
					printf("\nElemento guarado\n");
				}
				printf("\n%d",actual->Codigo);
				printf("\n%s",actual->Nombre);
				printf("\n%s",actual->Extension);
				printf("\n%d",actual->Tam);
				printf("\n%.2f\n",actual->Precio);
				
				actual=actual->siguiente;
			}
		}else{
			printf("La lista esta vacia");
		}
	}
	fclose(fp);
}
void leerLista(){
	Imagenes* actual = (struct Imagenes*) malloc(sizeof (Imagenes));
	actual=primero;
	FILE *fp;
	
	printf("\nLeido desde el archivo: \n");
	fp=fopen("ArchivoNUEVO.bin", "rb");                                  //lectura en binario y mostrar
	if (fp != NULL) {
		printf("Apertura exitosa\n");
		if(primero!=NULL){
			while(actual!=NULL){
				fread(actual,sizeof(struct Imagenes),1,fp);
				printf("\n%d",actual->Codigo);
				printf("\n%s",actual->Nombre);
				printf("\n%s",actual->Extension);
				printf("\n%d",actual->Tam);
				printf("\n%.2f\n",actual->Precio);
				
				actual=actual->siguiente;
			}
		}else{
			printf("La lista esta vacia");
		}
	}
	fclose(fp);
}
void OrdenarLista(){
	Imagenes* actuali = (struct Imagenes*) malloc(sizeof (Imagenes));
	Imagenes* actualj = (struct Imagenes*) malloc(sizeof (Imagenes));
	Imagenes* aux = (struct Imagenes*) malloc(sizeof (Imagenes));
	
	if(primero!=NULL){
		actuali=primero;
		while(actuali!=NULL){
			actualj=actuali->siguiente;
			while(actualj!=NULL){
				if(strcmp(actuali->Nombre,actualj->Nombre)>0){
					aux->Codigo=actuali->Codigo;
					strcpy(aux->Nombre,actuali->Nombre);
					strcpy(aux->Extension,actuali->Extension);
					aux->Tam=actuali->Tam;
					aux->Precio=actuali->Precio;
					
					actuali->Codigo=actualj->Codigo;
					strcpy(actuali->Nombre,actualj->Nombre);
					strcpy(actuali->Extension,actualj->Extension);
					actuali->Tam=actualj->Tam;
					actuali->Precio=actualj->Precio;
					
					actualj->Codigo=aux->Codigo;
					strcpy(actualj->Nombre,aux->Nombre);
					strcpy(actualj->Extension,aux->Extension);
					actualj->Tam=aux->Tam;
					actualj->Precio=aux->Precio;
				}
				actualj=actualj->siguiente;
			}
			actuali=actuali->siguiente;
		}
	}else{
		printf("La lista esta vacia");
	}
}
void imprimirLista(){
	Imagenes* actual = (struct Imagenes*) malloc(sizeof (Imagenes));
	actual=primero;
	
	if(primero!=NULL){
		while(actual!=NULL){
			printf("\n%d",actual->Codigo);
			printf("\n%s",actual->Nombre);
			printf("\n%s",actual->Extension);
			printf("\n%d",actual->Tam);
			printf("\n%.2f\n",actual->Precio);
			
			actual=actual->siguiente;
		}
	}else{
		printf("La lista esta vacia");
	}
}
