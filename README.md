# Push_Swap

<img width="450" alt="Screen Shot 2023-08-08 at 9 11 40 PM" src="https://github.com/driely01/Push_Swap/assets/41493879/07747294-7f42-4116-b1d3-09adff5358fd">

This project for sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. 

we have at our disposal a set of integer values, 2 stacks, and a set of instructions
to manipulate both stacks.

Our goal?
Write a program in C called push_swap which calculates and displays
on the standard output the smallest program, made of Push swap language instructions,
that sorts the integers received as arguments.

Easy?
We’ll see...

In this project we have to sort data in aspecific rules:

• You have 2 stacks named a and b.

• At the beginning:
  ◦ The stack a contains a random amount of negative and/or positive numbers
  which cannot be duplicated.
  ◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the
  following operations at your disposal:
  
  `sa` *(swap a)*: Swap the first 2 elements at the top of stack a.
      Do nothing if there is only one or no elements.
      
  `sb` *(swap b)*: Swap the first 2 elements at the top of stack b.
      Do nothing if there is only one or no elements.
      
  `ss`  sa and sb at the same time.
  
  `pa` *(push a)*: Take the first element at the top of b and put it at the top of a.
      Do nothing if b is empty.
      
  `pb` *(push b)*: Take the first element at the top of a and put it at the top of b.
      Do nothing if a is empty.
      
  `ra` *(rotate a)*: Shift up all elements of stack a by 1.
      The first element becomes the last one.
      
  `rb` *(rotate b)*: Shift up all elements of stack b by 1.
      The first element becomes the last one.
      
  `rr` ra and rb at the same time.

  `rra` *(reverse rotate a)*: Shift down all elements of stack a by 1.
      The last element becomes the first one.
      
  `rrb` *(reverse rotate b)*: Shift down all elements of stack b by 1.
      The last element becomes the first one.

  `rrr` rra and rrb at the same time.
