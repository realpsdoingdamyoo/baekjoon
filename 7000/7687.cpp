#include <stdio.h>
#include <math.h>

int sqs(int x, int y){return x*x+y*y;}

int main () {
    while(1){
        int lx_, ly_, lz_, x_, y_, z_, leng=872368623, x, y, z, lx, ly, lz;
        scanf("%d %d %d %d %d %d", &lx_, &ly_, &lz_, &x_, &y_, &z_);
        if(lx_==0 && ly_==0 && lz_==0) break;
        if(x_==0) leng=sqs(y_, z_);
        if(y_==0) leng=sqs(z_, x_);
        if(z_==0) leng=sqs(x_, y_);
        if(x_==lx_){
            x=x_; y=y_; z=z_; lx=lx_; ly=ly_; lz=lz_;
            leng=leng<((lx+z)*(lx+z)+y*y)?leng:((lx+z)*(lx+z)+y*y);
            leng=leng<((lx+y)*(lx+y)+z*z)?leng:((lx+y)*(lx+y)+z*z);
            if(z*lx>ly*(ly-y)) leng=leng<sqs(lx+ly-y, ly+z)?leng:sqs(lx+ly-y, ly+z);
            if(y*lx>lz*(lz-z)) leng=leng<sqs(lx+lz-z, lz+y)?leng:sqs(lx+lz-z, lz+y);
        }
        if(y_==ly_){
            x=y_; y=z_; z=x_; lx=ly_; ly=lz_; lz=lx_;
            leng=leng<((lx+z)*(lx+z)+y*y)?leng:((lx+z)*(lx+z)+y*y);
            leng=leng<((lx+y)*(lx+y)+z*z)?leng:((lx+y)*(lx+y)+z*z);
            if(z*lx>ly*(ly-y)) leng=leng<sqs(lx+ly-y, ly+z)?leng:sqs(lx+ly-y, ly+z);
            if(y*lx>lz*(lz-z)) leng=leng<sqs(lx+lz-z, lz+y)?leng:sqs(lx+lz-z, lz+y);
        }
        if(z_==lz_){
            x=z_; y=x_; z=y_; lx=lz_; ly=lx_; lz=ly_;
            leng=leng<((lx+z)*(lx+z)+y*y)?leng:((lx+z)*(lx+z)+y*y);
            leng=leng<((lx+y)*(lx+y)+z*z)?leng:((lx+y)*(lx+y)+z*z);
            if(z*lx>ly*(ly-y)) leng=leng<sqs(lx+ly-y, ly+z)?leng:sqs(lx+ly-y, ly+z);
            if(y*lx>lz*(lz-z)) leng=leng<sqs(lx+lz-z, lz+y)?leng:sqs(lx+lz-z, lz+y);
        }
        printf("%d\n", leng);
    }
    return 0;
}
