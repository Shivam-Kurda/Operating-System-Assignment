#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#define kernel_2d_memcpy 451
int main(){
    float *dest[4];
    float *src[4];
    for(int i=0;i<=3;i++){
        src[i]=(float*)malloc(4*sizeof(float));
        dest[i]=(float*)malloc(4*sizeof(float));
       
    }
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            src[i][j]=4.0;
        }
    }
    long status;
    status=syscall(kernel_2d_memcpy,src,dest,4,4);
    if(status==0){
        for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
           printf("%lf\n",dest[i][j]);
        }
    }
    }
    else{
        printf("no");
    }

    
    
    
}