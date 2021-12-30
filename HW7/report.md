Phase one solution: "When a problem comes along, you must zip it!"
This phase was the easiest one, since just by scrolling through the instructions it was 
easy to identify a function that compared the input with the string 'When a problem...'.
Nevertheless, I still managed to blow it up couple times :(. That happens when you do not
wait for the lab to start working on the assignment, I guess. Lesson learned, the hard way.

Phase two solution: "0 1 2 6 16 44"
This one took me longer. I could identify a function that used scanf to check for
"%d %d %d %d %d %d". Then later found that it checked the first an second integers against
the values 0 and 1. The remaining ones were a little more difficult to find until I 
figured out that, starting with the third one, it was checking each digit against double
the sum of the two digits before it. 
 
Phase three solution: "Ewi-,(Ocjb"
This was the hardest one. It was relatively easy to see that it wanted an input of 10
chars, but the instructions did some weir manipulations in the beginning loading some stuff
into the registers and it got me lost for a while. After a little tinkering I found that
the string "Luc.. Ball" and the sequence of hex values 09 02 0a 03 02 08 0d 02 06 0e, 
loaded into registers in the beginning, were being used as a key to check the input. 
Each characte from the input was being XORed with the respective value from the hex 
sequence and checked to see if it matched with the char at the same position on the string
"Luc.. Ball". After realizing this, it was easy to do the calculations and come up with
the right sequence of characters for the input.

Phase four solution: "7 64"
This one was surprisingly easy. Scanf was used at the beginning to check for "%d %d". Then 
a little further it checked for the first input and checked it to see if it matched 7. Then 
right before the end it tries to match the second integer with the input with 0x40, which is
64.

Phase five solution: "11 35"
This phase also checked for two integers. Both were somehow related to the hex value 0x23, 
which is 35. The first input had to be less or equal to 7 after subtracting 8 from it in order
to avoid blowing the bomb. After that, the function calls a loop that adds 3, 5, 7 and 9 to 
the first value in the input and compares it with 0x23 for validation. Lastly, right before
returning, the second value of the input is also compared with 0x23 and the explode function
gets called if the input is different.

