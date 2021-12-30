/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Points: 5
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 10
 */
int getByte(int x, int n) {
// (n << (2^3)
  return ((( x & (0xff << (n << 3))) >> (n << 3)) & 0xff );
}

/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Points: 10
 */
int byteSwap(int x, int n, int m) {
 int bn = ((( x & (0xff << (n << 3))) >> (n << 3)) & 0xff ); //extract n
int bm = ((( x & (0xff << (m << 3))) >> (m << 3)) & 0xff ); //extract m
int clear1 = (x & (~(0xff << (n << 3))));
int clear2 = (clear1 & (~(0xff << (m << 3))));
int mask1 = ( clear2 | (bn << (m << 3)));
int mask2 = ( mask1 | (bm << (n << 3)));  
 return mask2;
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 15
 */
int logicalShift(int x, int n) {
int signmask = (((0x1 << 31) >> n) << 1); 
 return ((x >> n) & ~signmask);
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 20
 */
int bitCount(int x) {
int result = ((x & 1) + ((x >> 1) & 1) + ((x >> 2) & 1) + ((x >> 3) & 1) + ((x >> 4) & 1) + ((x >> 5) & 1) + ((x >> 6) & 1) + ((x >> 7) & 1) + ((x >> 8) & 1) + ((x >> 9) & 1) + ((x >> 10) & 1)); 
int result1 =  (((x >> 11) & 1) + ((x >> 12) & 1) + ((x >> 13) & 1) + ((x >> 14) & 1) + ((x >> 15) & 1) + ((x >> 16) & 1) + ((x >> 17) & 1) + ((x >> 18) & 1) + ((x >> 19) & 1) + ((x >> 20) & 1));
int result2 = (((x >> 21) & 1) + ((x >> 22) & 1) + ((x >> 23) & 1) + ((x >> 24) & 1) + ((x >> 25) & 1) + ((x >> 26) & 1) + ((x >> 27) & 1) + ((x >> 28) & 1) + ((x >> 29) & 1) + ((x >> 30) & 1) + ((x >> 31) & 1)); 
return (result + result1 + result2);

}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Points: 20
 */
int bang(int x) {
  return ((x >> 31) | ((~x + 1) >> 31)) + 1;;
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 20
 */
int bitParity(int x) {
int result = ((x & 1) + ((x >> 1) & 1) + ((x >> 2) & 1) + ((x >> 3) & 1) + ((x >> 4) & 1) + ((x >> 5) & 1) + ((x >> 6) & 1) + ((x >> 7) & 1) + ((x >> 8) & 1) + ((x >> 9) & 1) + ((x >> 10) & 1));
int result1 =  (((x >> 11) & 1) + ((x >> 12) & 1) + ((x >> 13) & 1) + ((x >> 14) & 1) + ((x >> 15) & 1) + ((x >> 16) & 1) + ((x >> 17) & 1) + ((x >> 18) & 1) + ((x >> 19) & 1) + ((x >> 20) & 1));
int result2 = (((x >> 21) & 1) + ((x >> 22) & 1) + ((x >> 23) & 1) + ((x >> 24) & 1) + ((x >> 25) & 1) + ((x >> 26) & 1) + ((x >> 27) & 1) + ((x >> 28) & 1) + ((x >> 29) & 1) + ((x >> 30) & 1) + ((x >> 31) & 1));

int bits1= result + result1 + result2;

  return bits1 & 1;
}
