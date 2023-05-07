import cv2


#cap = cv2.VideoCapture('http://admin:admin@[2402:f000:3:6801:a824:ae1c:7df3:d561]:8081')
print(0)
cap = cv2.VideoCapture('http://192.168.106.76:81/stream')
print(1)
#cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 320)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 240)
#cap.set(cv2.CAP_PROP_FRAME_WIDTH, 960)
#cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 540)
#cv2.namedWindow('img', 0)
while True:
    _, frame = cap.read()
    cv2.imshow('img', frame)
    #print(_, frame.shape)
    cv2.waitKey(20)
