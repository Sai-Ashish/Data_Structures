# include<stdio.h>
# include<stdlib.h>
# include <math.h>
# include <complex.h>

#define pi 3.141592653
typedef double complex compl;// just renaming double complex as compl 

compl *recursiveFFT(compl x[],int N){

  if(N==1){
    return x;
  }
  compl wn=cexp(-2*pi*I/N);
  compl w=1;
  compl even[N/2];
  compl odd[N/2];

  for(int i=0;i<N/2;i++){
    even[i]=x[2*i];
    odd[i]=x[2*i+1];
  }
  
  /*we have to return the array from function thus malloc has been used*/
  compl *y_even=(compl *)malloc((N/2)*sizeof(compl));
  compl *y_odd=(compl *)malloc((N/2)*sizeof(compl));
  compl *X=(compl *)malloc(N*sizeof(compl));

  y_even=recursiveFFT(even,N/2);
  y_odd=recursiveFFT(odd,N/2);

  for(int k=0;k<N/2;k++){
    X[k]=y_even[k]+w*y_odd[k];
    X[k+N/2]=y_even[k]-w*y_odd[k];
    w=w*wn;
  }

  return X;
}

int main(){
  compl x[8]={1,8,0,4,1,2,3,1};
  compl *X1;
  X1=recursiveFFT(x,8);
  for(int i=0;i<8;i++){
    printf("(%g,%g)\n",creal(X1[i]),cimag(X1[i]));
  }
}
