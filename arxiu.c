#include <stdio.h>
#include <stdlib.h>

#define N 512

float Mat[N][N], MatDD[N][N], V1[N], V2[N], V3[N], V4[N];


void InitData(){ 
	int i,j; 
	srand(334411); 
	for( i = 0; i < N; i++ ) 
		for( j = 0; j < N; j++ ){ 
		Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));  
		if ( (abs(i - j) <= 3) && (i != j)) 
			MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX)); 
		else if ( i == j ) 
			MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX))); 
		else MatDD[i][j] = 0.0; 
		} 
	for( i = 0; i < N; i++ ){ 
		V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0; 
		V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0; 
		V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))); //Els vectors tenen 256 valors (la mitad de la matriu)
	} 
}


void PrintVect( float vect[N], int from, int numel ){//EXERCICI 1
	int i;
	for( i = from; i < numel; i++ ) //Aquesta comanda s'executarà des d'un numero donat fins a altre
		printf( "%f,", vect[i] );//Imprimirà el numero a la posició del vector i una coma
}


void PrintRow( float mat[N][N], int row, int from, int numel ){
	int i,j;
	for( j = row, i = from; i < numel; i++ ) //Aquesta comanda s'executarà des d'un numero donat fins a altre
		printf( "%f,", mat[i][j] ); //Imprimirà en una fila especificada, en un rang específic

}



void  MultEscalar( float vect[N], float vectres[N], float alfa ){
	int i;
        for( i = 0; i < N; i++ )
		vectres[i] = vect[i]*alfa;


}




int main(){
	float vr[N];



	InitData();
	MultEscalar( V1, vr, 100 );
	PrintVect( vr, 0, 20 ); //(EXERCICI 1)
	//PrintRow( Mat, 45, 1, 4 ); //La funció imprimeix matrius (EXERCICI 2)

}
