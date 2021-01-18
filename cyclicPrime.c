#include<stdio.h>
#include<math.h>
#include <stdbool.h>
bool isPrime(int number)
{
  int factor = number - 1;
  bool isPrime = true;

  while(factor>=2){

     if(number%factor==0){

        isPrime=false;
     }
     factor--;
  }
  return isPrime;
}

int main(){
int number;
int temp= number;
int powerCount=0;
int cyclicPrime,rem,div;
int count =0;
printf("enter the number");
scanf("%d",&number);
if(number<=0){
    printf("-1");
}

while(temp>0){
    temp=temp%10;
    powerCount++;
}
cyclicPrime=number;

while(isPrime(cyclicPrime)){
    count++;
    rem = cyclicPrime%10;
    div =cyclicPrime /10;
    cyclicPrime=pow(10,powerCount-1)*rem + div;

    if(cyclicPrime==number){
        break;
    }
}
if(count==powerCount){
    printf("1");
}
else{
    printf("0");
}

}
