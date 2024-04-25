# Game_Of_Life
This project is a reproduction of the Game of life of Conway. It use Raylib to display the map.

# Raylib 

Here you can find how to install Raylib : [Tutorial for Raylib](https://youtu.be/PaAcVk5jUd8?si=Mj535kA19qn2Bokf)



# Launch game_of_life

You can simply compile the project by using make, then run it with
`./game_of_life probability_of_spawn`

`probability_of_spawn` : The chance in percent that every cells on the map start by 
						 being alive at the first generation.

If the programme receive no arguments, `probability_of_spawn` = 8.

You can modifie the size of the windows by modifiying the constants : HEIGHT & WIDTH, at the
compilation or in the inc/game_of_life.h file and make re. The PIXEL constant stand for the pixel scale
of every cells on the map.



# Control game_of_life

There is two mod :

*The generation mod, the map will update, generation by generation, by the speed that you can
increased by pressing ↑, and decreased by pressing ↓.

*The pause mode, that can be entered by holding down space key. In this mod, the generation
stop, and wait for you to released the space key, you can then create cells by pressing
the left mouse click, and kill other by pressing the right mouse click. This mod able zoom and
camera movement

You can quit the game anytime by pressing echap
