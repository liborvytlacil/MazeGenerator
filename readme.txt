Usage:
[executable-name] [width] [height]

Description:
Generates a pseudo-random rectangular 4-directional maze of size [width]x[height] and prints its representation to the standard output.

Each cell of the maze is represented by a space character, e.g. ' ', in the output. Either a space ' ' or a wall 'X' is
printed between each two neighbouring cells depending on whether those cells are connected or not.

Example output for [width]=3 and [height]=4:

XXXXXXX
X X   X
X X X X
X X X X
X XXX X
X     X
XXXXX X
X     X
XXXXXXX