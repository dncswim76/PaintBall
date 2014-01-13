Paint Ball -- POV globe

Dependencies (Things you will need to download)

This is what I think we'll need so far.

gitHub ... you will need to set it up ...
follow these instructions:
   https://help.github.com/articles/set-up-git

arduino
 * frequencyTimer2 Library
   -->   http://playground.arduino.cc/Code/FrequencyTimer2
 * tranciever library
   -->   http://playground.arduino.cc/InterfacingWithHardware/Nrf2401

python
 * pySerial
     for linux:
        sudo apt-get install python-serial
     for macs:
         however you download from the command line on a mac :P


Brian Walsh, I made the pythonUI to put the user interface
directory files in.

Brian Ip, I made the tranceiver directory for you to
work with the communication stuff.
   Heres the link for you to see what you to look at:
   http://playground.arduino.cc/InterfacingWithHardware/Nrf2401

For those of you that don't know how to use git:

     On the right of the webpage you should be able to copy the pointer
     to the git repository

     then say in linux command line:
     git clone <paste url here>

     you can make changes to the code that is there, but to update the version
     say:

     git commit -am "some message of what you changed"
         **This only updates locally on your machine, not in the repo
           found online**

     to update to everyone else say:

     git push origin master

     if you add a file:

     git add <path to file/name of file>
