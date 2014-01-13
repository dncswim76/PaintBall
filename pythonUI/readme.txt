/*user interface for the POV sphere*/


okay so here's what i'm thinking...

what eddie and I need is a 360 --16 byte packets to run the hardware.
* each bit in the 16 bytes repesents 1 LED, hence 16*8 is 128.
* we need 360 of these because we need the information for every degree of the sphere
  as it turns, so one bundle of 16 bytes would essentially be 1 column in a matrix.

The issue that you will run into is that that there will be more resolution closer to
the poles of the sphere because the LEDs don't need to travel as far, and their linear
velocity isn't as fast as LEDs farther away from the poles.

So for example, when a user draws on a computer, they will be drawing on something that looks like
the figure on the left. But eddie and I need what's on the right

      what the user                 translated 16 byte (128 bit) by 360 matrix
        drawns on
       xxxxxxxxx                  xxxxxxxxxxxxxxxx
      xxxxxxxxxxxx                xxxxxxxxxxxxxxxx
     xxxxxxxxxxxxxx               xxxxxxxxxxxxxxxx
    xxxxxxxxxxxxxxxx       ===\   xxxxxxxxxxxxxxxx
    xxxxxxxxxxxxxxxx       ===/   xxxxxxxxxxxxxxxx
     xxxxxxxxxxxxxx               xxxxxxxxxxxxxxxx
      xxxxxxxxxxxxx               xxxxxxxxxxxxxxxx
       xxxxxxxxxxx                xxxxxxxxxxxxxxxx

So you will need to develope software that will translate this.  You would expect that bits closer to the equator
would be not changed as much, but bits towards the pole will need to be stretch out to cover more that one bit after the
translation due to the differences in the linear velocities of the LEDs i said before.

It shouldn't be too bad. I believe you will just have to do some minor radian calculations of the percentage the bit takes up of the "circle" tangent
to the axel.

so for example, if a row has 8 bits and we need it to be drawn out to 360 bits, then the translation would be 1/8 * 360 or 45 bits. so the first bit from before
corresponds to the first 45 in the translated matrix row
