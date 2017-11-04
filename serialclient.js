/*

	This Node script requires node-serialport and socket.io-client to be installed with NPM
	It is meant to be run on a computer with an arduino or other serial device and relays data to a remote server for broadcasting

*/

var SerialPort = require('serialport');
// CHANGE TO YOUR SERIAL PORT
var serialPort = new SerialPort("/dev/tty.usbmodem1421", {
  baudRate: 9600
});

var buffer = [];

serialPort.on("open", function () {
  console.log('open');

// CHANGE TO YOUR SERVER ADDRESS
  var socket = require('socket.io-client')('http://localhost:1025');
  socket.on('connect', function(){
  	 console.log("Socket Connected");

  	 socket.on('motor', function(data) {
  	 	console.log("join and speed up");
			 serialPort.write(data.toString());
			 console.log(data.toString());
  	 });
  });
});
