
# The Problem : 

Every integer 2 or greater N has a unique prime factorisation such that
N = P1^Q1 × P2^Q2...<br>
where Pi are ascending prime numbers and Qi are positive power indices.

Examples
30 = (2^1)×(3^1)×(5^1)<br>
96 = (2^5)× (3^1)<br>
900 = (2^2)×(3^2)×(5^2)<br>

Consider a transformation that takes all values in a given finite set of primes and maps each prime to another one (it can be the same prime as before, and not necessarily in the initial set, but no two primes map to the same prime).

For example, take a transformation which has the following mapping:<br>
2 -> 11<br>
3 -> 17<br>
5 -> 2<br>

Then<br>
4 -> 121, (2^2 -> 11^2)<br>
9 -> 289, (3^2 -> 17^2)<br>
25 -> 4, (5^2 -> 2^2)<br>
6 -> 187 ((2^1)×(3^1) -> (11^1)×(17^1))<br>
10 -> 22 ((2^1)×(5^1) -> (11^1)×(2^1))<br>

Your task, given a set of transformed pairs, is to find the transformation and thus apply it to a given integer X.

# input : 

Line 1: X the integer to transform<br>
Line 2: C the number of clues given about the transformation<br>
Next C Lines: For each line, a pair of integers Ai and Bi such that the transformation maps Ai to Bi.

# Output :

One line containing Y, the result of the transformation applied to X.
 ### Constraints
  2 ≤ Ai, Bi, X, Y < 2^63<br>
  2 ≤ Pi ≤ 100<br>

# Example
     
     Input         Output<br>
      
      16            625 <br>
      1
      2  5<br>

