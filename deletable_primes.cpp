/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
 #include "deletable_primes.h"
 #include <stdio.h>
 #include <math.h>

 unsigned long remove_digit(int index, unsigned long n){
  int divisor = pow(10,index + 1);
  int modulator = pow(10,index);
  long result = n / divisor;
  result *= modulator;
  result += n % modulator;
  return result;
}

int get_ways(unsigned long p){
  int count = 0;

  if(get_length(p) == 1 ){
    if(is_prime(p)){
      count++;
      return count;
    }
    else{
      return count;
    }
  }
  int index = 0;
  int length = get_length(p);

  while (index < length) {
    long return_value = remove_digit(index, p);
    if(get_length(return_value) > 1){
      if(is_prime(return_value)){
        count += get_ways(return_value);
        index++;
      }
      else{
        index++;
      }
    }
    else if(get_length(return_value) == 1){
      count += get_ways(return_value);
      index++;
    }
  }
  return count;
}

bool is_prime(long number){
  if(number <= 1 || number % 2 == 0) return false;
  if(number == 2) return true;

  for (int i = 2; i < number / 2; i++) {
    if(number % i == 0 && number != i) return false;
  }
  return true;
}

int get_length(long number){
  int i = 0;
  int j = 0;

  do{
    i++;
    j = number / pow(10, i);

  }while (j != 0);

  return i;
}
