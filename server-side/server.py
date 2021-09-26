import game
from http.server import BaseHTTPRequestHandler, HTTPServer
from flask import Flask, request, jsonify
from flask_cors import CORS

commands = ['go to', 'use', 'attack', 'look at', 'help']

def parse_command(command):
	command.replace(' ', '')
	for substr in commands:
		if substr in command:
			action = substr.strip()
			target = command.split(substr)[1].strip()
			if target == None:
				target = ''
			if action == None:
				action = ''
			return (action, target)
	return ('', '')

new_game = ""
p1_address = ""
p2_address = ""

app = Flask(__name__)
CORS(app)

@app.route('/')
def home():
	print('Testing')
	return 'Welcome home.'

@app.route('/start_game')
def start_game():
	global new_game
	global p1_address
	global p2_address
	if(p1_address == ""):
		p1_address = request.access_route[0]
	else:
		p2_address = request.access_route[0]
	new_game = game.start()
	content = {'intro': new_game.intro()}
	print(content)
	print(p1_address, flush=True)
	print("Hello", flush=True)
	print(p2_address, flush=True)
	print(request.access_route, flush=True)
	return content

@app.route('/recv_command', methods=['POST'])
def recv_command():
	content = request.get_json()
	action, target = parse_command(content['command'])
	print(action + target)
	if(action == ''):
		return {'result': 'Invalid input (try \'help\')', 'finished': '0'}
	res = new_game.p2Action(action, target)
	finished = new_game.isOver()
	content = {'result': res, 'finished': str(finished)}
	return content

app.run(host='0.0.0.0', debug=True, port=8080)
