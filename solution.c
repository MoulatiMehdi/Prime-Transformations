#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define t_size long long

const t_size  LENGTH = 25 ;
const t_size PRIME[] = {
    97, 89, 83, 79, 73, 71, 67, 61,
    59, 53, 47, 43, 41, 37, 31, 29,
    23, 19, 17, 13, 11, 7, 5, 3, 2 };


t_size maxA = 0;
t_size B_maxA = 0;

int lines = 0;
t_size log_n(t_size  n, t_size x){

    return (t_size) (log(x) / log(n));
}

t_size findPower(t_size number, t_size base){

    t_size high = log_n(base,number) + 1;
    t_size low = 0 ;
    
    while(low <= high){

        t_size mid = high + low;
        t_size guess = pow(base, mid);

        if(number%guess == 0 ){

            if ((number/guess) % base != 0) {

                return mid;
            }
            low = mid + 1;

        }else{
            high = mid - 1;
        }
    }
    return 0;
}

t_size* primeFactor(t_size num){
    
    t_size *factors = (t_size*)calloc(sizeof(t_size),LENGTH);

    for(t_size i = 0 ;i < LENGTH ;i++){

        t_size prime = PRIME[i];
        
        if( num % prime  == 0){

            t_size power = findPower(num, prime);   
            factors[i] = power;
           
            num /= pow(prime, power);
        } else{
            factors[i] = 0;
        }
    }
    return factors;
}

t_size primeTransform(t_size X ,t_size*A ,t_size*B){

    if(maxA > X){

        t_size* P = (t_size *) calloc(sizeof(t_size),LENGTH);
    
        for(int i = 0;i < lines ;i++){
            
            int power = findPower(A[i],X);
            t_size * factors = primeFactor(B[i]);            
              
            for(int j = 0; j < LENGTH ;j++){
                if(factors[j] != power){
                    P[j] = 1;
                }   
            }
            free(factors);
        }
        t_size  answer = 0;

        for(int i = 0; i < LENGTH; i++){
            if(P[i] == 0)
                answer = PRIME[i];
        }

        free(P);
        return answer;

    }else{

        t_size power = findPower(X,maxA);
        return pow(B_maxA , power) * X / pow(maxA,power);
    }
    

}





int main()
{
    long long X;
    scanf("%lld", &X);
    scanf("%d", &lines);

    t_size* A = (t_size*) calloc(sizeof(t_size),lines + 1);
    t_size* B = (t_size*) calloc(sizeof(t_size),lines + 1);

    for (int i = 0; i < lines; i++) {
        long long ai;
        long long bi;
        
        scanf("%lld%lld", &ai, &bi);

        A[i] = ai;
        B[i] = bi;

        if(ai > maxA){
            maxA = ai ;
            B_maxA = bi; 
        }
    }


    t_size answer = primeTransform(X,A,B);
    printf("%lld\n",answer);

    return 0;
}
