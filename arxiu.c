#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void PrintRow( float mat[N][N], int row, int from, int numel ) {
    	int i;
    	for (i = from; i < numel; i++) //Es diu des d'on fins on
        	printf("%f,", mat[row][i]); //Imprimeix els resultats de la fila des de from fins numel
}


void  MultEscalar( float vect[N], float vectres[N], float alfa ){
	int i;
        for( i = 0; i < N; i++ )
		vectres[i] = vect[i]*alfa;
		

}


float Scalar(float vect1[N], float vect2[N]) {
    	float res = 0;
    	for (int i = 0; i < N; i++) {
        	res += vect1[i] * vect2[i]; //S'afegeix al resultat la multiplicació entre les posicions dels vectors
	}
	printf("%f", res);
}


float Magnitude( float vect[N] ){
	float res = 0;
	for (int i = 0; i < N; i++){
		res += vect[i]*vect[i]; //Es fa el sumatori de quadrats de totes les posicions
	}
	res = sqrt(res); //Es fa l'arrel quadrada del total
	printf("%f", res);
}



int main(){
	float vr[N];
	InitData();
//A
/*
	PrintVect(V1, 0, 10);
	printf("\n");
        PrintVect(V1, 256, 266);
        printf("\n");
        PrintVect(V2, 0, 10);
        printf("\n");
        PrintVect(V2, 256, 266);
        printf("\n");
        PrintVect(V3, 0, 10);
        printf("\n");
        PrintVect(V3, 256, 266);
        printf("\n");
*/
//B
/*
	PrintRow(Mat, 0, 0, 10);
        printf("\n");
        PrintRow(Mat, 100, 0, 10);
*/
//C
/*      PrintRow(MatDD, 0, 0, 10);
        printf("\n");
        PrintRow(MatDD, 100, 90, 100);
        printf("\n");
*/




//E
/*
	Scalar(V1, V2);
	printf("\n");
        Scalar(V1, V3);
        printf("\n");
        Scalar(V2, V3);
        printf("\n");
*/
//F
	Magnitude(V1);
        printf("\n");
        Magnitude(V2);
        printf("\n");
        Magnitude(V3);
        printf("\n");

}


