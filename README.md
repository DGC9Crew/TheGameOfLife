A simple version of Conway's Game of Life in C.

gameOfLife.c -> the simulation itself. Reads data from gen.txt for simulation.
- Default rows is 45.
- Default columns is 188.
- Default update delay (in milisec) is 50ms
- Default # of generations is 1000.

gener.c -> generates random values for the gen.txt.
- Default rows is 45.
- Default columns is 188.
- Default random rate is 10 (1/10 chance for alive tile)

GameOfLife -> executable for gameOfLife.c || Run with ./GameOfLife
- Args. EX: ./GameOfLife X=20 Y=20 D=5 G=100
  - X= number of rows. EX: ./GameOfLife X=60
  - Y= number of columns. EX: ./GameOfLife Y=120
  - D= update delay in MS. EX: ./GameOfLife D=10
  - G= number of generations (negative for infinite). EX: ./GameOfLife G=1500

Gen -> executable for gener.c || Run with ./Gen
- Args. EX: ./Gen X=60 Y=120 R=5
  - X= number of rows. EX: ./Gen X=60 
  - Y= number of columns. EX: ./Gen Y=120 X=60
  - R= random rate per tile to be alive. 1/R. EX: ./Gen R=5

