#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE4(kernel_2d_memcpy,float __user **,src,float __user **,dest,int,rows,int,cols){
    float kerarr[rows][cols];
    for(int i=0;i<rows;i++){
        if(__copy_from_user(kerarr[i], src[i], sizeof(float)*(cols))){
            return -EFAULT;
        }
    }
    for(int i=0;i<rows;i++){
        if(__copy_to_user(dest[i], kerarr[i], sizeof(float)*(cols))){
        return -EFAULT;
    }

    }
    
    return 0;
    
    



}