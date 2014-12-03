/*
 * auxfunctions.c
*/

#include "auxfunctions.h"

void printMat(double **m,unsigned long N,unsigned long M){
	unsigned long i,j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++) fprintf(stdout,"%0.2f ",m[i][j]);
		fprintf(stdout,"\n");
	}
	fprintf(stdout,"\n\n");
}

void printVec(double *m,unsigned long N){
	unsigned long i = 0;
	fprintf(stdout,"[ ");
	for(;i<N;i++) fprintf(stdout,"%f, ",m[i]);
	fprintf(stdout,"]\n\n");
}


double pdoublexpdouble(double *ai,double* y,unsigned long n){
	double sum = 0;
	for(n -= 1;n>0;n--) sum += *(ai+n) * *(y+n);
	return sum;
}


void pdoubledifferencexalpha(double* a,double* y,double alpha,unsigned long n){
	for(n -= 1;n>0;n--) a[n] = (*(a+n)) - ((*(y+n))*alpha);
}

void pdoublesumcexalpha(double* a,double* y,double alpha,unsigned long n){
	for(n -= 1;n>0;n--) a[n] = (*(a+n)) + ((*(y+n))*alpha);
}
