Caterpillar

On a field we grow letters. Our caterpillar eats letters from the field. The caterpillar is composed of modules. Each module consists of a letter. After moving into a letter the caterpillar grows i.e. it eats the letter and adds new module to the body. The module consists the same letter that was eaten. The extension is done at the head of the body if lowercase is eaten or at the tail if uppercase is eaten. After eating a letter a new letter is showing up on the same spot. The new letter is one smaller, in order of ASCII code, from the eaten one. After eating the letter 'a' or 'A' a waste is showing up on its spot.
If caterpillar goes to any waste then one module is deleted from the body. The front module is deleted if the waste was created from 'a' and tail module is deleted if the waste was created from 'A'.
The field is a rectangular grid. On the grid except letters there are also signs. The caterpillar is in constant move and its direction is given by the signs.
Write a program which simulates few first movements of the caterpillar.

Input
In the first line there are 3 numbers n m c where n is width of the field, m is height of the field and c is the number of movements.
In the second line there are 3 numbers x y d where x,y is starting position of the caterpillar, d is the starting length of the caterpillar.
In the third line there are the d letters - first letter is the head of the caterpillar. Next n lines consists m charters each - it is description of the field.
Valid charters are:
a-z A-Z letters
1,2,3,4 - signs, directions: up/down/left/right respectively
# - empty space
Upper left corner of the field has coordinate (1,1).
The caterpillar cannot go outside of the field because it has 'tire' property - lack of borders e.g. coordinate left of (1,1) is (n,1) and up of the (1,1) is (1,m). At the beginning of the simulation the caterpillar moves right.
Output
In the first line write position of the caterpillar after c moves and the module letters starting with the head.
If the caterpillar dies (all modules are deleted) before c moves then write position of the death and sign #.
Next n lines consist the field as described in input. The wastes should be depicted by '@'. 

Example:

Input
4 2 23
1 1 2
mi
2zB3
4#a2

Output
3 1 amib
2x@3
4#@2