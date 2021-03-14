import socket
import config
from time import sleep


s = socket.socket()
s.bind(('', 9090))
s.listen(1)
s_, ip = s.accept()
while True:
    mess = s_.recv(1024)
    if config.questbool == True:
        s_.send("1")
        print(1)
    else:
        s_.send("0")
        print(0)

    sleep(1)
