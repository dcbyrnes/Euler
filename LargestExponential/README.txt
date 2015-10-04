Project: LargestExponential

Authors: Daniel Byrnes

Date: 10/4/2015

Use: ./exp

Description: Euler projects are challenging math problems that require 
			 mathematical insight as well as computing power. 
			 Problem #99, Largest Exponential.

Function: This program is simple in that is generates a list of numbers 
          and reports the kth smallest number. The numbers in this list
          are reported as b^e where both b and e are integers between 
          1 and 10^9. Thus, b^e can be a very large number 
          (e.g. 53879401^(115438167)). In order to sort these numbers we 
          need to compare numbers in this list, but evaluating b^e will
          surely result in an integer overflow. Thus, we use the fact 
          that if b^e < a^d, then e*log(b) < d*log(a). Log transformations
          will allow us to easily compare numbers without overflow.


