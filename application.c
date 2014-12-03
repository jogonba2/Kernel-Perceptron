#include "kernel_perceptron.c"

int main(int argc, char **argv)
{
	// Test con muestras D-dimensionales //
	
	// Rellenar los vectores de peso //
	unsigned long N = 3;
	double** weightVectors = (double **)malloc(N*sizeof(double *));
	unsigned long i = 0;
	unsigned long j = 0;
	for(i=0;i<D;i++) weightVectors[i] = (double *) malloc (D*sizeof(double));
	for(i=0;i<N;i++) for(j=0;j<D;weightVectors[i][j++] = i);
	
	// Rellenar muestras de entrenamiento//
	// nMuestrasEntrenamiento = NVectoresDePeso = N en este caso //
	double** learnSamples = (double **)malloc(N*sizeof(double *));
	for(i=0;i<D;i++) learnSamples[i] = (double *) malloc (D*sizeof(double));
	for(i=0;i<N;i++) for(j=0;j<D;learnSamples[i][j++] = i);
	
	printMat(weightVectors,N,D); printMat(learnSamples,N,D);
	//printVec(weightVectors[1],N);
	
	// Factor de aprendizaje \alpha = 1 , Margen b = 0.1 //
	double learnFactor = 1;
	double margin      = 0.1;
	kernel_perceptron(weightVectors,N,learnSamples,N,learnFactor,margin,D);
	for(i=0;i<N;i++){ free(learnSamples[i]);free(weightVectors); }
	
	return 0;
}

