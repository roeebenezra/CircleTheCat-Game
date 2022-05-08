# Circle-The-Cat
circle the cat game using SFML library  


Yaakov Haimoff 318528510
Roee Ben Ezra 206123994

The project is the game Circle The Cat.
The purpose of the player in the game is to circle the cat with black circles,
The cat has a smart algorithm that uses BFS which helps him to run away to the edges.
If the cat got to the edge the cat wins.
There's 3 levels, starting from the easiest to the hardest. The easiest level starts with
15 black circles which are set in random circles in the board.
As the player moves forward in the levels the number of black circles decreases.

Main files in the game:
Controller – runs the game, handling the events in the games.
MoveObject – the base class for Cat, holds the BFS algorithm .
Cat – the cat object in the game. manages the cat movement between when the cat uses the BFS and when the cat in trapped.
Resources – singleton class for the images and font in the game.
Board – holds the game board with a vector of circles.

Main algorithms is the BFS.
No bugs known.
 


