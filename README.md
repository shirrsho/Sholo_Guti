https://github.com/shirsho1106/Sholo_Guti/

# Sholo_Guti

Here I try to digitalize a very common rural game of South Asia named Shologuti. Which is known by the outside world as Sixteen Soldiers. 
The game was documented by Henry Parker in Ancient Ceylon: An Account of the Aborigines and of Part of the Early Civilisation (1909) with the name Hēwākam Keliya or the War Game.
Parker’s documented game and the shologuti of the Bangladesh version are completely similar. Here are the rules to be followed in this game[1]:

Players alternate their turns.
A player may only use one of their pieces in a turn and must either make a move or perform a capture but not both.
A piece may move onto any vacant adjacent point along a line.
A piece may capture an opposing piece by a short leap. The piece must be adjacent to the opposing piece, and leap over it onto a vacant point immediately beyond. The leap must be in a straight line and follow the pattern on the board. Captures are not mandatory. A piece can continue to capture within the same turn and may stop capturing any time. The captured piece (or pieces) is removed from the board.
The player who captures all of the other player's pieces wins.
 
[1] : https://en.wikipedia.org/wiki/Sixteen_Soldiers

And in my SPL-1, I am to design a program that will create an environment to play this ancient game on a computer. A user can play against his friend here, or he can play against the computer also.
The program will follow each and every rule. And the AI will be smart enough to make its moves which can beat a good Shologuti player. Everything will be handled according to the rules. An attractive UI will also be available to make things smooth.
The project has been implemented in C language, using the graphics.h header file.



There are two parts of the project:
Two Players’ mode
AI mode

 **Two Players’:**
It is a mode where two players will make their moves to get an advancement over their opponent. And each move whether it is just a displacement or a killing move will be controlled by the program. Players will click on a piece to move it to their preferred position. If the move is valid the program will let it happen or it will not. The game rules have to be strictly followed by the players. Otherwise, it will not be playable.			Figure 1: Two players’ mode in the game


 **Machine:**
The program is separated into two parts here. One is Player vs Machine and the other is Machine vs Machine. 
Two AI has been developed here. According to their effectiveness, one is labeled with “Regular AI” and the other one is “Tough AI”.
In the Player vs Machine mode, a human will be able to play against the AI. And in the Machine vs Machine mode, the Tough AI will play against the Regular AI. Therefore, the Tough AI should win each game with some limitations, because the Regular AI is not a complete naive 
Figure 2: Player vs AI mode in the game			Figure 3: AI vs AI mode in the game

machine. Again, the game rules will be followed by the machine. No AI can make an invalid move. Further details about the AIs and how they work will be discussed in the appropriate section.
