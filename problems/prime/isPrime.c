#include<stdio.h>
#include<math.h>

int main(){
  int num, flag = 0;
  
  printf("Enter a natural number: ");
  scanf("%d", &num);

  double sqrtResult = sqrt((double) num);

  for (int i=2; i <= sqrtResult; ++i){
    if (num%i == 0){
      flag = 1;
      break;
    }
  }
  
  if (flag == 1) {
    printf("%d is not a prime number\n", num);
  } else {
    printf("%d is a prime number\n", num);
  }

  return 0;
}