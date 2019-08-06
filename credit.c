#include<stdio.h>
#include<cs50.h>

int main(){

unsigned long long creditCard;

int digitCounter=0;

int sum=0;

creditCard=get_long("Number: ");

int digit1=(creditCard)%10;

int digit2=(creditCard/10)%10;

int digit3=(creditCard/100)%10;

int digit4=(creditCard/1000)%10;

int digit5=(creditCard/10000)%10;

int digit6=(creditCard/100000)%10;

int digit7=(creditCard/1000000)%10;

int digit8=(creditCard/10000000)%10;

int digit9=(creditCard/100000000)%10;

int digit10=(creditCard/1000000000)%10;

int digit11=(creditCard/10000000000)%10;

int digit12=(creditCard/100000000000)%10;

int digit13=(creditCard/1000000000000)%10;                           

int digit14=(creditCard/10000000000000)%10;

int digit15=(creditCard/100000000000000)%10;

int digit16=(creditCard/1000000000000000)%10;

while(creditCard!=0){

    digitCounter++;

    creditCard=creditCard/10;
}
if(digitCounter!=13 && digitCounter!=15 && digitCounter!=16 ){

    printf("INVALID\n");
}
if(digitCounter==15){

    if((digit15==3 && digit14==4)||(digit15==3 && digit14==7)){
        digit2=digit2*2;
        digit4=digit4*2;
        digit6=digit6*2;
        digit8=digit8*2;
        digit10=digit10*2;
        digit12=digit12*2;
        digit14=digit14*2;
        sum=(digit2%10)+((digit2/10)%10)+(digit4%10)+((digit4/10)%10)+(digit6%10)+((digit6/10)%10)+(digit8%10)+((digit8/10)%10)+(digit10%10)+((digit10/10)%10)+(digit12%10)+((digit12/10)%10)+(digit14%10)+((digit14/10)%10);
        sum=sum+digit1+digit3+digit5+digit7+digit9+digit11+digit13+digit15;
        if(sum%10==0){
            printf("AMEX\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    else{
        printf("INVALID\n");
    }

}
if(digitCounter==16){

    if(digit16==5 && (digit15>=1 &&digit15<6)){
        digit2=digit2*2;
        digit4=digit4*2;
        digit6=digit6*2;
        digit8=digit8*2;
        digit10=digit10*2;
        digit12=digit12*2;
        digit14=digit14*2;
        digit16=digit16*2;
        sum=(digit2%10)+((digit2/10)%10)+(digit4%10)+((digit4/10)%10)+(digit6%10)+((digit6/10)%10)+(digit8%10)+((digit8/10)%10)+(digit10%10)+((digit10/10)%10)+(digit12%10)+((digit12/10)%10)+(digit14%10)+((digit14/10)%10)+(digit16%10)+((digit16/10)%10);
        sum=sum+digit1+digit3+digit5+digit7+digit9+digit11+digit13+digit15;
         if(sum%10==0){
            printf("MASTERCARD\n");
        }
        else{
            printf("INVALID\n");
        }

    }
    
    if(digit16==4){
        digit2=digit2*2;
        digit4=digit4*2;
        digit6=digit6*2;
        digit8=digit8*2;
        digit10=digit10*2;
        digit12=digit12*2;
        digit14=digit14*2;
        digit16=digit16*2;
        sum=(digit2%10)+((digit2/10)%10)+(digit4%10)+((digit4/10)%10)+(digit6%10)+((digit6/10)%10)+(digit8%10)+((digit8/10)%10)+(digit10%10)+((digit10/10)%10)+(digit12%10)+((digit12/10)%10)+(digit14%10)+((digit14/10)%10)+(digit16%10)+((digit16/10)%10);
        sum=sum+digit1+digit3+digit5+digit7+digit9+digit11+digit13+digit15;
         if(sum%10==0){
            printf("VISA\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    
}

if(digitCounter==13){

    if(digit13==4){
        digit2=digit2*2;
        digit4=digit4*2;
        digit6=digit6*2;
        digit8=digit8*2;
        digit10=digit10*2;
        digit12=digit12*2;
        sum=(digit2%10)+((digit2/10)%10)+(digit4%10)+((digit4/10)%10)+(digit6%10)+((digit6/10)%10)+(digit8%10)+((digit8/10)%10)+(digit10%10)+((digit10/10)%10)+(digit12%10)+((digit12/10)%10);
        sum=sum+digit1+digit3+digit5+digit7+digit9+digit11+digit13;
        if(sum%10==0){
            printf("VISA\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    else{
        printf("INVALID\n");
    }

}




}

