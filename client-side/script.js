const resultText = document.getElementById("result");
const commandField = document.getElementById("command");
const url = "http://172.20.0.4:8080/recv_command";

function processResponse(obj) {
	resultText.innerHTML = obj["result"].replaceAll("\n", "<br />");
	if (obj["finished"] === "1") {
		commandField.disabled = true;
	}
}

function sendCommand(str) {
	let req = new XMLHttpRequest();
	req.open("POST", url);
	req.responseType = "json";
	req.setRequestHeader("Content-type", "application/json");
	req.onreadystatechange = function() {
		console.log("Got response", this.readyState);
		if (this.readyState === XMLHttpRequest.DONE &&
			this.status === 200) {
			console.log("Response is good", this.response);
			processResponse(this.response);
		}
	}
	let content = JSON.stringify({"command": str});
	console.log("Sending");
	req.send(content);
}

function begin(){
	let req = new XMLHttpRequest();
	req.open("GET", "http://172.20.0.4:8080/start_game");
	req.setRequestHeader("Content-type", "application/json");
	req.responseType = "json";
	req.onreadystatechange = function() {
		console.log("Got response", this.readyState);
		if (this.readyState === XMLHttpRequest.DONE &&
			this.status === 200) {
			console.log("Response is good", this.response);
			resultText.innerHTML = this.response["intro"].replaceAll("\n", "<br />");
		}
	}
	req.send();
}

function updateText(e) {
	str = e.target.value;
	e.target.value = "";
	sendCommand(str);
	//resultText.textContent = str;
}

commandField.addEventListener("change", updateText);
document.addEventListener("DOMContentLoaded", begin);
