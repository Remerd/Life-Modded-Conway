from websocket_server import WebsocketServer
import time


# Called for every client connecting (after handshake)
def new_client(client, server):
	print("New client connected and was given id %d" % client['id'])
	while True:
		f = open('log.txt', 'r')
		
		for line in f:
			server.send_message_to_all(line)
		f.close()
		time.sleep(2)


# Called for every client disconnecting
def client_left(client, server):
	print("Client(%d) disconnected" % client['id'])

# Called when a client sends a message

PORT=443
server = WebsocketServer(PORT)
server.set_fn_new_client(new_client)
server.set_fn_client_left(client_left)
server.run_forever()
