# Intuition

This problem is just a matrix where you're checking adjacent cells. adjacent seems to apply diagonally as well, hence the problem saying to check 8 adjacent cells

```md
..@@.@@@@.
@@@.@.@.@@
@@@@@.@.@@
@.@@@@..@.
@@.@@@@.@@
.@@@@@@@.@
.@.@.@.@@@
@.@@@.@@@@
.@@@@@@@@.
@.@.@@@.@.
```
at any cell i can look left right up and down. the main issue is correctly detecting something out of range.

left and right out of range is easy, if the indices on a string are out of range then we're good.
up and down out of range is not as simple. Of course i could create an empty row, which i could actually put into the data and just start from row one index wise.
what are the ramifications to doing that?(create a new blank string up top)? I think the main one is that I am assuming I need one blank string.

I think the best approach is to use logic to determine all of the out of boundary spots.

How would I design the project to go allow out of bounds
