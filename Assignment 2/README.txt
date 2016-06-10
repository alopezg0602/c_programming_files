Name: 	James Harding
StID: 	998 043 291
Title: 	Mars Rover
Source:	marsrover.c

############### Description ###############
The marsrover program is used to, given a maze input, calculate the shortest 
path through the maze, if at all possible. 
- If there are no valid solutions, the program will notify the user. 
- If the input is invalid, the program will state the error and quit.
- If a path can be found through the maze, a set of compass instructions
  (north, south, east, or west) will guide the robot through the maze.

############### Compiling ###############
The wallowing command will be used to computer the program. With terminal 
set to the working directory including the source file, enter:

gcc -Wall -o marsrover marsrover.c

############### Running ###############
To run the application, enter the following into terminal

./marsrover

This command requires keyboard input of maze data. Alternately, a txt 
file in the same directory can be sent as input. If the maze data file 
is called 'maze.txt'

.marsrover < maze.txt

will run the program using the text file data.

############### Input Format ###############
The following is an example of acceptable input

520..................#X.......................#.....#...................#..........L........#..........

Where L is the lassoing location, X is the target,
'.'s are acceptable paths, and # symbols are walls

############### Known Issues ###############
None :-)