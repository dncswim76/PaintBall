The code for communication with the ball, to be implemented
through the RF tranceiver chips.


the information will need to be sent through different packets since
the RF chips can only send a max of 25 bytes at a time. The packets will
consist of the following.

Each packet will correspond to one column in the matrix... (see pythonUI readme)
so this will be 16 bytes of information for 128 LEDs.

A header will be attached to the message to indicate which column (or degree)
the data is specifying.  Since 360 degrees, we will need 2 bytes to represent
this.

so a packet will have a total 18 bytes.


byte 0                       byte 1                   byte2                            byte 17
|  HIGHER BITS of column # | lower bits of column # | bits closer to north pole| ..... | bits closer to south pole|
