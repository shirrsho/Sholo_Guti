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
It is a mode where two players will make their moves to get an advancement over their opponent. And each move whether it is just a displacement or a killing move will be controlled by the program. Players will click on a piece to move it to their preferred position. If the move is valid the program will let it happen or it will not. The game rules have to be strictly followed by the players. Otherwise, it will not be playable.


 **Machine:**
The program is separated into two parts here. One is Player vs Machine and the other is Machine vs Machine. 
Two AI has been developed here. According to their effectiveness, one is labeled with “Regular AI” and the other one is “Tough AI”.
In the Player vs Machine mode, a human will be able to play against the AI. And in the Machine vs Machine mode, the Tough AI will play against the Regular AI. Therefore, the Tough AI should win each game with some limitations, because the Regular AI is not a complete naive 
Figure 2: Player vs AI mode in the game machine. Again, the game rules will be followed by the machine. No AI can make an invalid move. Further details about the AIs and how they work will be discussed in the appropriate section.




**User Manual**

(Use codeblock EP and libbgi.a library to compile and run the sources.)


At first, a menu appears with all the game modes available: Two Players’, vs Machine, AI vs AI. Each option runs its related portions. Another option available is ‘Leaderboard’. By which we can see the scores and winners of each match ever played.


 *Two Players’ mode:*
 
After clicking on the Two Players’ mode screen will be flooded with white color and the Shologuti board will be displayed at the center of the screen, containing two kinds of pieces, reds and blacks. On the right side of the screen, there will be three labels. Two of them indicate whose move it is and the third one is the button of getting back to the main menu screen.
The user will have to click on a piece to move it. By clicking on a piece it will turn big indicating it has been selected. Then the user will click on his desired destination for the selected piece. This will complete a move for the user. The move can be of two kinds: Killing Move and Displacement Move. In the killing move, a piece will have to jump over another player’s piece to the place next to it. This will cause the jumped-over piece to be killed or vanished, the opponent will lose that piece. The beauty of the kill move is it will trigger a recursive killing function. By the recursive killing, one will be able to kill any number of pieces possible by hopping over them in a single move.
And by killing the opponent’s pieces the winner will be chosen. The player who will kill the opponent’s all pieces in the first place will be declared as the winner.
Then a window regarding the winner’s name and score will pop up containing a button that takes the user to the main menu screen by a mouse-click.
				          Figure 7: Game ending pop-up option
 
 *AI mode (vs Machine):*
 
By clicking on the AI mode a similar screen will be visible like the Two Players’ mode. But now the black pieces will be controlled by the computer according to the heuristic algorithm implemented for the AI. The details of the implementation will be stated in the appropriate section.

The player’s control here is the same as what is stated in the two players’ mode. One can move and kill a piece by the appropriate use of mouse clicks. And after completing a move the player needs to wait for the AI to make its move. After the AI moves its piece the player needs to play his turn. 
The game will be played repeating these steps. The game ends when the player or the AI successfully captures all the pieces of the opponent. Then a pop-up window will appear stating the winner and the score alongside a button to return to the main menu.


 *AI vs AI mode:*
 
The AI vs AI mode is more like a “sit back and enjoy” mode. The only working button available for the user is the end game button, which takes the user back to the menu screen.
Except that every move here is made by the computer. Player red and player black plays against each other, both controlled by the computer. Here, the backend algorithm for the black player is more constructive than the red one. So, logically the black one should win every game. But in some cases, matches will be tied because of the excessive safe play of the AIs. And after a game is finished a pop-up window will appear and can take the user back to the main menu by clicking a button.


 *Leaderboard:*
By clicking on the Leaderboard labeled button from the home screen, scores will come into view alongside their holder for each game played. For the overflow of records, a ‘+’ signed button will appear. Clicking on that button will display another page holding the next records. 

