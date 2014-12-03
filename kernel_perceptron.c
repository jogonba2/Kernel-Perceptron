/*
 * Kernel Perceptron.c
*/

#include "kernel_perceptron.h"
#include "auxfunctions.c"

void kernel_perceptron(double** weightVectors,unsigned long C,double** learnSamples,
						unsigned long numLearnSamples,double learnFactor,double margin,
						unsigned int dimensions){
							
	unsigned long     m; // Number of well clasified samples //
	unsigned long     n; // Sample id //
	unsigned long     i; // Sample label //
	unsigned long     j; // Index of lasses 1 <= j <= C ( C weightVectors )//
	double            g; // Correct class of a given sample //
	char      error = 0; 
	do{
		m = 0;
		for(n=1;n<=numLearnSamples-1;n++){
			i = learnSamples[n][1]; g = pdoublexpdouble(weightVectors[n],learnSamples[n],dimensions); error = FALSE;
			for(j=1;j<=C;j++){
				if(j!=i){
					if(pdoublexpdouble(weightVectors[j],learnSamples[n],numLearnSamples)+margin > g){
						pdoubledifferencexalpha(weightVectors[j],learnSamples[n],learnFactor,numLearnSamples);
						error = TRUE;
					}
				}
				if(error==TRUE) pdoublesumcexalpha(weightVectors[i],learnSamples[n],learnFactor,numLearnSamples);
				else m += 1;			
			}
		}	
	}while(m<numLearnSamples);
}
