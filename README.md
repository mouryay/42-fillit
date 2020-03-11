Fillit is a 42 School Project where you need to write a program to fit a given set of tetriminoes into the smallest possible square.

I did not know anything about anything at this point. I did not know how to read a file. The Project PDF page says you can use the read() function, so I googled what it is. It can read files based on their 'file descriptors'. I didn't know what a 'file descriptor' was. So I googled that and it was only a number assigned to any file name when you open it using the open() function. Cool. Now I could read a file. Now what? I had no clue. Everybody said you gotta try to do it yourself but I spent a lot of time being clueless that I finally caved in and looked up on github for other people's code. After scanning through some I found a gem.

Jem Cope's github <https://github.com/Jemmeh>. 
I finally understood how to approach it and was able to finish it in a few days. 

Basically you read the file, you look for illegal characters. If everything is as it should be you then save the co-ordinates of the tetrimino blocks in an array or a linkedlist. Once you save it, you try place all of them in the smallest possible square (an array). This is where the algorithm comes in. They call it the 'backtracking algorithm'. I did not understand it until I actually wrote it down. So don't worry if you feel clueless. You will be clueless until you are not.

You should totally read Jem Cope's 'readme' for a detailed explanation.
