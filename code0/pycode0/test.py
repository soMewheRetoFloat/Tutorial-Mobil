
from my_udp import UDP_Manager
import time
import cv2
import numpy as np

recvTemp = b''
recv = []


def callback(data, addr):
    global recvTemp
    recvTemp += data[8:]
    if data[1] == 0x01:
        #recv.append(recvTemp)
        #cv2.imshow('img', cv2.imdecode(np.frombuffer(recvTemp, np.uint8), cv2.IMREAD_COLOR))
        try:
            img = cv2.imdecode(np.frombuffer(recvTemp, np.uint8), cv2.IMREAD_COLOR)
            img = np.flip(img, 0)
            img = np.flip(img, 1)
            cv2.imshow('img', img)
            cv2.waitKey(1)
        except:
            print('bad packet')
        
        print(len(recvTemp))
        recvTemp = b''

data_1 = b'\x42\x76'

ip = '192.168.4.153'
port  = 8080
addr = (ip, port)

a = UDP_Manager(callback)
a.Start()

a.Send(data_1, addr)
#time.sleep(3)
#a.Close()

#img = cv2.imdecode(np.frombuffer(recv[1], np.uint8), cv2.IMREAD_COLOR)
#cv2.imshow('img', img)
