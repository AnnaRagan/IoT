#!/usr/bin/python
# -*- coding: latin-1 -*-
import os, sys
from lidar_lite import Lidar_Lite
lidar = Lidar_Lite()

connected = lidar.connect(1)

if connected < -1:
    print ("Not Connected")
else:
    print ("Connected")

for i in range(100):
    distance = lidar.getDistance()
    print(lidar.getVelocity())
    print ("Distance to targetâ", (distance))
    if int(distance) < 50:
        print(lidar.getVelocity())
        print ("Too Close!!! Back Off!!!")
