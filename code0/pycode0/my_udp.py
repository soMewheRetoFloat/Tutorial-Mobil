#coding:utf-8
import socket
import time
import struct
import threading



class UDP_Manager:
    def __init__(self, callback, isServer = False, ip = '', port = 8083, frequency = 50, inet = 4):
        self.callback = callback
        
        self.isServer = isServer
        self.interval = 1.0 / frequency

        self.available_addr = socket.getaddrinfo(socket.gethostname(), port)
        self.hostname = socket.getfqdn(socket.gethostname())

        self.inet = inet
        self.af_inet = None
        self.ip = ip
        self.localIp = None
        self.port = port
        self.addr = (self.ip, self.port)
        self.running = False

        #self.serialNum = 0

        #self.recvPools = {} #{'IP:PORT': [{serialNum:[data..., recvNum, packetNum, timestamp]}]}

    def Start(self):
        if self.inet == 4:
            self.af_inet = socket.AF_INET  # ipv4
            self.localIp = '127.0.0.1'
        elif self.inet == 6:
            self.af_inet = socket.AF_INET6 # ipv6
            self.localIp = '::1'
        self.sockUDP = socket.socket(self.af_inet, socket.SOCK_DGRAM)

        if self.isServer:
            self.roleName = 'Server'
        else:
            self.port = 0
            self.roleName = 'Client'
        
        self.sockUDP.bind((self.ip, self.port))
        self.addr = self.sockUDP.getsockname()
        self.ip = self.addr[0]
        self.port = self.addr[1]
        
        print(self.roleName, '(UDP) at:', self.ip, ':', self.port)
            
        self.running = True
        self.thread = threading.Thread(target = self.Receive, args=())
        self.thread.setDaemon(True)
        self.thread.start()  #打开收数据的线程
        
    def ListAddr(self):
        for item in self.available_addr:
            if item[0] == self.af_inet:
                print(item[4])
    
    def Receive(self):
        print(self.roleName, '(UDP) is running...\n')
        while self.running:
            time.sleep(self.interval)
            while self.running:
                try:
                    recvData, recvAddr = self.sockUDP.recvfrom(65535) #等待接受数据
                    #print(recvData)
                except:
                    break
                if not recvData:
                    break
                self.callback(recvData, recvAddr)
            
    def Send(self, data, addr):
        self.sockUDP.sendto(data, addr)
        #print(data, addr)

    def Close(self):
        self.running = False
        

if __name__ == '__main__':
    def callback(x, y):
        print(x, y)
        print('nnn', len(x))
    
    #ip = '127.0.0.1'
    #ip = '::1'
    ip = '2402:f000:3:8801:f18a:8801:7760:74e0'
    inet = 6
    a = UDP_Manager(callback, isServer = True, ip=ip, port = 8083, inet=inet)
    b = UDP_Manager(callback, isServer = True, ip=ip, port = 8084, inet=inet)
    a.Start()
    time.sleep(0.5)
    b.Start()
    time.sleep(0.5)

    #a.ListAddr()

    print(a.sockUDP.getsockname())
    time.sleep(0.5)
    print(b.sockUDP.getsockname())
    time.sleep(0.5)

    b.Send(b'b'*100, (ip, 8083))
    time.sleep(0.5)
    a.Send(b'a'*100, (ip, 8084))
    time.sleep(0.5)



    
