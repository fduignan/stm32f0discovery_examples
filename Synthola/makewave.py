#!/usr/bin/python
import math
print "const int16_t wavetable[]={"
for index in range(0,1023):
    # Make a waveform with 4 octaves (feel free to experiment but make sure values stay between -32768 and +32767
    SineValue = math.sin(index*2*math.pi/1024)/4+math.sin(index*4*math.pi/1023)/4+math.sin(index*8*math.pi/1024)/4+math.sin(index*16*math.pi/1023)/4
    SineValue = SineValue * 32767
    SineValue = int(SineValue)
    print str(SineValue)+","
print "};"
    
