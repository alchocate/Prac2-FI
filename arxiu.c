//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
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
		V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))); 
	} 
} 


void PrintVect( float vect[N], int from, int numel ){//EXERCICI 1
	int i;
	for( i = from; i < numel; i++ ) //Aquesta comanda s'executarà des d'un numero donat fins a altre
		printf( "%f  ", vect[i] );//Imprimirà el numero a la posició del vector i una coma
	printf( "\n" );
}

void PrintRow( float mat[N][N], int row, int from, int numel ) { //EXERCICI 2
    	int i;
    	for (i = from; i < numel; i++) //Es diu des d'on fins on
        	printf("%f,", mat[row][i]); //Imprimeix els resultats de la fila des de from fins numel
	printf( "\n" );
}


void  MultEscalar( float vect[N], float vectres[N], float alfa ){ //EXERCICI 3
	int i;
        for( i = 0; i < N; i++ )
		vectres[i] = vect[i]*alfa; //Multiplica cada posició del vector pel mateix nombre

}


float Scalar(float vect1[N], float vect2[N]) { //EXERCICI 4
    	float res = 0;
    	for (int i = 0; i < N; i++) {
        	res += vect1[i] * vect2[i]; //S'afegeix al resultat la multiplicació entre les posicions dels vectors
	}
	return res;
}


float Magnitude( float vect[N] ){ //EXERCICI 5
	float res = 0;
	for (int i = 0; i < N; i++){
		res += vect[i]*vect[i]; //Es fa el sumatori de quadrats de totes les posicions
	}
	res = sqrt(res); //Es fa l'arrel quadrada del total
	return res;
}


int Ortogonal( float vect1[N], float vect2[N] ){ //EXERCICI 6
	int res, ortogonal;
	res = Scalar(vect1, vect2); 
	if (res == 0){
		ortogonal = 1;
	printf("%d, els vectors son ortogonals\n", ortogonal); 
	}else{
		ortogonal = 0;
		printf("%d\n", ortogonal);
	}
	
}


void  Projection( float vect1[N], float vect2[N], float vectres[N] ){ //EXERCICI 7
	float escalar, magnitud;
	escalar = Scalar(vect1, vect2);
	magnitud = Magnitude (vect2);
	if (magnitud != 0){
		float x = escalar / magnitud;
		for (int i = 0; i < N; i++)
			vectres[i] = x * vect2[i];
	}
	else{
		for (int i = 0; i < N; i++)
			vectres[i] = 0;

	}
}



float Infininorm( float M[N][N] ){ //EXERCICI 8
	int i, j;
	float max = 0; //La  variable max anirà guardant el resultat més gran
        for (j = 0; j < N; j++){
		float num = 0;
		for (i = 0; i < N; i++){
			num +=  fabs( M[j][i] ); //La funció fabs permet fer el valor absolut de cada nombre
		}
		if (num > max){ //Si el sumatori d'una fila es major que el màxim
			max = num; //El màxim passa a ser aquest sumatori
		}
	}
	printf( "%f\n", max);
}


float Onenorm( float M[N][N] ){ //EXERCICI 9

        int i, j;
        float max = 0; //La  variable max anirà guardant el resultat més gran

        for (i = 0; i < N; i++){
                float num = 0;
                for (j = 0; j < N; j++){
                        num += fabs( M[j][i] ); //La funció fabs permet fer el valor absolut de cada nombre
		}
                if (num > max){ //Si el sumatori d'una columna es major que el màxim
                	max = num; //El màxim passa a ser aquest sumatori
		}
	}
        printf( "%f\n", max);
}


float NormFrobenius( float M[N][N] ){ //EXERCICI 10
	int i, j;
        float num;
        for (j = 0; j < N; j++)
                for (i = 0; i < N; i++)
                        num += ( M[i][j] ) * ( M[i][j] );
	num = sqrt( num );
	printf( "%f\n", num );
}


int DiagonalDom( float M[N][N] ){ //EXERCICI 11
        int i, j;
	int diagonaldominant = 1;
        for (i = 0; i < N; i++){
		float diag = fabs(M[i][i]);
		float nodiag = 0;
                for (j = 0; j < N; j++){
			if(i != j){
			nodiag += fabs(M[i][j]);
			}
                if ( diag < nodiag ){
			diagonaldominant = 0;
			
			}
		}
        }
	if (diagonaldominant){
		printf( "La matriu MatDD és diagonal dominant\n" );
	}else{
		printf( "La matriu Mat NO és diagonal dominant\n" );
        }
}


void Matriu_x_Vector( float M[N][N], float vect[N], float vectres[N] ){ //EXERCICI 12
	int i, j;
	for ( j=0; j<N; j++ )
		for ( i=0; i<N; i++ )
			vectres[j] += M[j][i]*vect[i];
}


int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned iter ){ //EXERCICI 13

        int i, j, k;
        float sumatori, vectaux[N];

        for ( i = 0; i < N;  i++){
                 vectres[i] = 0;
        }

        for ( k = 0; k < iter; k++ ){ //Aquesta k registra les itineracions
                for (i = 0; i < N; i++) { 
                                vectaux[i] = vectres[i]; 
                }

                for ( j = 0; j < N;  j++){ //La j registra les files
                        sumatori =0;
                        for ( i = 0; i < N;  i++){ //La i son les columnes
                                if ( i!=j ){
                                        sumatori += ( M[i][j] * vectaux[i] );
                                }
                        }
                        vectres[j] = ( vect[j] - sumatori ) / M[j][j]; 
                }
        }

	float dife = 0;
	float diferen = 0;
	for ( i=0; i<N; i++ ){
		diferen = fabs(vectres[i] - vectaux[i]);
		if (diferen > dife){
			dife = 0;
			dife = diferen;
		}
		diferen = 0;

	}
	printf("El marge d'error es de %f\n", dife);
}








int main(){
	float vr[N], x, vr2[N];
	InitData();
printf("Exercici A: Els elements 0 al 9 i 256 al 265 dels vectors V1, V2 i V3\n");

	PrintVect(V1, 0, 10);
        PrintVect(V1, 256, 266);
        PrintVect(V2, 0, 10);
        PrintVect(V2, 256, 266);
        PrintVect(V3, 0, 10);
        PrintVect(V3, 256, 266);
	printf("\n");

printf("Exercici B: Els elements 0 al 9 de les files 0 i 100 de la matriu Mat.\n");

	PrintRow(Mat, 0, 0, 10);
        PrintRow(Mat, 100, 0, 10);
        printf("\n");

printf("Exercici C: Els elements 0 al 9 de la fila 0 i 90 a 99 de la fila 100 de la matriu MatDD.\n");
      	PrintRow(MatDD, 0, 0, 10);
        PrintRow(MatDD, 100, 90, 100);
        printf("\n");

printf("Exercici D: Per cada matriu (Mat i MatDD) calculareu i visualitzareu: a. La seva Infini-norma b. La seva norma ú c. La seva norma de Frobenius d. Si la matriu és o no diagonal dominant\n");

	Infininorm( Mat );
        Onenorm( Mat );
        NormFrobenius( Mat );
        DiagonalDom( Mat );
	Infininorm( MatDD );
        Onenorm( MatDD );
        NormFrobenius( MatDD );
	DiagonalDom( MatDD );
        printf("\n");

printf("Exercici E: Calculareu i visualitzareu els següents productes escalars: a. V1·V2 b. V1·V3 c. V2·V3\n");

	x = Scalar(V1, V2);
	printf( "%f\n", x);

        x = Scalar(V1, V3);
	printf( "%f\n", x);

        x = Scalar(V2, V3);
	printf( "%f\n", x);

        printf("\n");

printf("Exercici F: Calculareu i visualitzareu la magnitud de V1, V2 i V3\n");
	x = Magnitude(V1);
	printf( "%f\n", x);
        x = Magnitude(V2);
	printf( "%f\n", x);
        x = Magnitude(V3);
	printf( "%f\n", x);
        printf("\n");

printf("Exercici G: Calculareu i visualitzareu si V1 és o no ortogonal amb V2 i V3 i si V2 i V3 són ortogonals (totes les combinacions possibles).\n");

	Ortogonal(V1,V2);
	Ortogonal(V1,V3);
        Ortogonal(V2,V3);
        printf("\n");

printf("Exercici H: Calculareu la multiplicació del vector V3 amb l’escalar 2.0 i visualitzareu els elements 0 al 9 i 256 al 265 del vector resultant.\n");
	MultEscalar(V3, vr2, 2.0);
	PrintVect(vr2, 0, 9);
	PrintVect(vr2, 256, 265);
        printf("\n");

printf("Exercici I: Calculareu la projecció del V2 sobre V3 i visualitzareu els 10 primers\n");
	Projection(V2, V3, vr);
	PrintVect(vr, 0, 10);
	Projection(V1, V2, vr);
        PrintVect(vr, 0, 10);
        printf("\n");
        
printf("Exercici J: Calculareu la multiplicació de la matriu Mat amb el vector v2 i visualitzareu els 10 primers elements del vector resultant\n");
	Matriu_x_Vector( Mat, V2, vr );
	PrintVect(vr, 0, 10);
        printf("\n");

printf("Exercici K: Calcularem la solució del sistema d’equacions MatDD*X = V3 pel metode de Jacobi\n");
	Jacobi( MatDD, V3, vr, 1 );
	PrintVect( vr, 0, 9 );
	Jacobi( MatDD, V3, vr, 1000 );
        PrintVect( vr, 0, 9 );

}


