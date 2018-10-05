#include <stdio.h> 
 
int main(){
  int k, cur, prev = 0, count = 0;
  scanf("%d", &k);
 
  while(scanf("%d", &cur) == 1){ 
    count++;
    if(prev == 0){
      if(k > cur){
	prev = cur;
	if(count != 1)printf("0\n");
      }
      else{
	printf("%d\n", cur/k);
	prev = cur % k;
      }            
    }
    else{
      int new = prev*10 + cur;
      prev = new % k;
      printf("%d\n", new / k);
    }
  }
  if(count == 1) printf("0\n");
  return 0;
}
