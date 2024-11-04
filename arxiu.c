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
		printf( "%f,", vect[i] );//Imprimirà el numero a la posició del vector i una coma
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
	}else{
		ortogonal = 0;
	}
	printf("%d\n", ortogonal);
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
        printf("%i\n", diagonaldominant);
}








int main(){
	float vr[N], x;
	InitData();
//A
/*
	PrintVect(V1, 0, 10);
        PrintVect(V1, 256, 266);
        PrintVect(V2, 0, 10);
        PrintVect(V2, 256, 266);
        PrintVect(V3, 0, 10);
        PrintVect(V3, 256, 266);
*/

//B
/*
	PrintRow(Mat, 0, 0, 10);
        PrintRow(Mat, 100, 0, 10);
*/

//C
/*      PrintRow(MatDD, 0, 0, 10);
        PrintRow(MatDD, 100, 90, 100);
*/

//D
/*
	Infininorm( Mat );
        Onenorm( Mat );
        NormFrobenius( Mat );
        DiagonalDom( Mat );
	Infininorm( MatDD );
        Onenorm( MatDD );
        NormFrobenius( MatDD );
	DiagonalDom( MatDD );
*/
//E
/*
	x = Scalar(V1, V2);
	printf( "%f\n", x);

        x = Scalar(V1, V3);
	printf( "%f\n", x);

        x = Scalar(V2, V3);
	printf( "%f\n", x);

//F
	x = Magnitude(V1);
	printf( "%f\n", x);
        x = Magnitude(V2);
	printf( "%f\n", x);
        x = Magnitude(V3);
	printf( "%f\n", x);
*/
//G
/*
	Ortogonal(V1,V2);
	Ortogonal(V1,V3);
        Ortogonal(V2,V3);
*/

//I
	//Projection(V2, V3, vr);
	//PrintVect(vr, 0, 10);
	//Projection(V1, V2, vr);
        //PrintVect(vr, 0, 10);

	//Infininorm( Mat );
	//Onenorm( Mat );
	//NormFrobenius( Mat );


}


