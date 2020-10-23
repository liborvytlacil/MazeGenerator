Usage:
[executable-name] [width] [height]

Description:
Generates a pseudo-random rectangular 4-directional maze of size [width]x[height] and prints its representation to the standard output.
An algorithm based on DFS with backtracking is used for the maze generation.

Each cell of the maze is represented by a space character, e.g. ' ', in the output. Either a space ' ' or a wall 'X' is
printed between each two neighbouring cells depending on whether those cells are connected or not.

Example output for [width]=7 and [height]=5:

XXXXXXXXXXXXXXX
X X     X     X
X X XXX X X XXX
X X   X   X   X
X XXX XXXXXXX X
X X       X   X
X XXXXXXX X XXX
X     X   X   X
XXXXX XXXXXXX X
X             X
XXXXXXXXXXXXXXX