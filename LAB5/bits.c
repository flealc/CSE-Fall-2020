#include "bits.h"

/*
 *  * Return and of x and y
 *   * Points: 5
 *    */
int and_op(int x, int y) {
  return (x&y);
}

/* 
 *  * Return or of x and y
 *   * Points: 5
 *    */
int or_op(int x, int y) {
 return (x|y);
}

/*
 *  * Return xor of x and y
 *   * Points: 5
 *    */
int xor_op(int x, int y) {
 return (x^y);
}


/*
 *  * Clear `b`th byte of x
 *   * Points: 10
 *    */
int masking_and(int x, int b) {
  int shift = 32 -(b*8);
  int result = (x & (~(0xff << shift)));
  return (result);
}

/*
 *  * Set `b`th byte of x
 *   * Points: 10
 *    */
int masking_or(int x, int b) {
  int shift = 32 -(b*8);
  int result = (x | (0xff << shift));
  return (result);
}

/*
 *  * Toggle `b`th byte of x
 *   * Points: 10
 *    */
int masking_xor(int x, int b) {
  int shift = 32 -(b*8);
  int result = (x ^ (0xff << shift));
  return (result);
}

/*
 *  * Shift x to the left by `sc` # of bits
 *   * Points: 5
 *    */
int shifting_left_op(int x, int sc) {
  return (x << sc);
}

/*
 *  * Shift x to the right by `sc` # of bits
 *   * Points: 5
 *    */
int shifting_right_op(int x, int sc) {
  return (x >> sc);
}


/*
 *  * Return logical not of x
 *   * Points: 5
 *    */
int bang(int x) {
  int result = !x;
  return (result);
}

/*
 * Given an integer x in decimal, convert to binary and set it in `bitstring`
 * Points: 40
 */
void bit_conversion(int x, char* bitstring) {
int y = x;
char buf[33];
//char buf2[33];
int index = 0;
while (y > 0){
        if ((y & 1) == 0){
                buf[index] = '0';
        }
        else if ((y & 1) == 1){
               buf[index] = '1';
        }
        y = y >> 1;
        index++;
}
int i;
int j = index;
for (i = 0; i <= index; i++) {
   bitstring[i] = buf[j - 1];
   j--;
}
bitstring[index+1] = '\0';
//bitstring = buf2;

}

 

