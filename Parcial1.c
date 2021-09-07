

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **LeerCSV(char* Nombre_archivo){
    FILE *pa=fopen(Nombre_archivo,"r");
    if(pa==NULL){
        printf("Problema a l abrir el archivo %s. Termina el programa.\n",Nombre_archivo);
        exit(-1);
    }
    int filas=0;
    int n=0;
    char c=fgetc(pa);     
    while(!feof(pa)){
        if(c=='\n'){ 
        filas++;      
        }
        if(c==','){ 
        n++;      
        }
       c=fgetc(pa);
    }
    int columnas =n/filas;
    fclose(pa);
     FILE *peliculas;
    peliculas=fopen (Nombre_archivo,"rb");
    if(peliculas==NULL){
        printf("Problema a l abrir el archivo %s. Termina el programa.\n",Nombre_archivo);
        exit(-1);
    }
   

    fseek(peliculas,0,SEEK_END);
    int num_elementos=ftell(peliculas);
    rewind(peliculas);
    char* cadena=(char*)calloc(sizeof(char),num_elementos);
    if(cadena==NULL){
        perror("Error en la reserva de memoria");
        return 2;
    }
    int num_elementos_leidos=fread(cadena,sizeof(char),num_elementos,peliculas);
    if(num_elementos_leidos!=num_elementos){
        perror("Error leyendo el archivo");
        return 3;
    }
    
    char *matriz[60][7];
    char *token = strtok(cadena, ",");
                     matriz[0][0]=token;
                for(int i=0;i<filas;i++){
                 for(int j=1;j<columnas;j++){
                 
                 token = strtok(NULL, ",");
                 if(token!='\n'){                     
                 matriz[i][j]=token;
                 }
            }
            }
                     free (cadena);
    
                    
                     return matriz;
}

int** MatrizEnteros(char *fileName) {
        int **matriz_enteros,i,j,nfilas,ncols;
        nfilas=59;
        ncols=6;
        matriz_enteros=(int**)calloc(nfilas,sizeof(int *));
        for(i=0;i<nfilas;i++){
            matriz_enteros[i]=(int *)calloc(ncols,sizeof(int));
        }
    
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}
	char linea[8000];
	fgets(linea, 7999, fp); 
	int valor=5;
	for (int i = 0; i < nfilas; i++) {
		
		fgets(linea,7999, fp);
		char *token = strtok(linea, ",");
                valor=atoi(token);
                if(valor==1||valor==0){
                matriz_enteros[i][0] = valor;
                }
		
		for (int j = 0; j < ncols; j++) {
			token = strtok(NULL, ",");
			 valor=atoi(token);
                if(valor==1||valor==0){
                matriz_enteros[i][j] = valor;
                }
		}
	}
	fclose(fp);
	return matriz_enteros;
}

int ** Matriz_Transpuesta(int**Matriz_Enteros){
    int **matrizTranspuesta,i,j,nfilas,ncols;
        nfilas=59;
        ncols=6;
        matrizTranspuesta=(int**)calloc(nfilas,sizeof(int *));
        for(i=0;i<nfilas;i++){
            matrizTranspuesta[i]=(int *)calloc(ncols,sizeof(int));
        }
         
    for (int i = 0; i < 59; i++) {
        for (int j = 0; j < 6; j++) {
            int numero=Matriz_Enteros[i][j];
            matrizTranspuesta[j][i]=numero;
        }
    }
    
         return matrizTranspuesta;
          }

int ** Multiplicar_Matriz(int **matrizTranspuesta,int**matriz_enteros){
        
        int **matrizMultiplicada,i,j,nfilas,ncols;
        nfilas=59;
        ncols=59;
        matrizMultiplicada=(int**)calloc(nfilas,sizeof(int *));
        for(i=0;i<nfilas;i++){
            matrizMultiplicada[i]=(int *)calloc(ncols,sizeof(int));
        }
    for (int i = 0; i < 59; i++) {
        for (int j = 0; j < 59; j++) {
            matrizMultiplicada[i][j]=0;
            for(int a=0; a<6; a++){
            matrizMultiplicada[i][j]+=matriz_enteros[i][a]*matrizTranspuesta[a][j];
            }
        }
    }
        return matrizMultiplicada;
}
const char* integrantes(){
    return "PM20072,CF20014";
}








