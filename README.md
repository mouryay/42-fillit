Fillit is a 42 School Project where you need to write a program to fit a given set of tetriminoes into the smallest possible square.

I did not know anything about anything at this point when I started this project. I did not know how to read a file. The Project PDF page says you can use the read() function, so I googled it. It can read files based on their 'file descriptors'. I didn't know what a 'file descriptor' was. So I googled that and it was only a number assigned to any filename when you open it using the open() function. Cool. I can read a file. Now what? I had no clue. Everybody said you gotta try to do it yourself but I spent a lot of time being clueless that I finally caved in and looked up on github for other people's approach. After scanning through some I found a gem.

Jem Cope's github <https://github.com/Jemmeh>. 
You should totally read her 'readme' for a detailed explanation. I finally understood how to approach it and was able to finish it in a few days. I did not use libft or any other libraries apart from those two allowed functions.

Approach:
Basically you read the file and you look for illegal characters. If you find an illegal character, you print error and exit, otherwise save the co-ordinates of the tetrimino blocks in an array (or a linkedlist if you prefer). Once you save it, you try to place all of them in the smallest possible square (an array). This is where the algorithm comes in. They call it the 'backtracking algorithm'. I did not understand it until I actually wrote it down and executed it. So don't worry if you feel clueless. You will be clueless until you are not.
