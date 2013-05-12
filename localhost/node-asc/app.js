// need to have mamp opened
// need to have the my server.js noded!! 
// study this link https://developer.mozilla.org/en-US/docs/Web/Guide/Touch_events
// 


var io = require('socket.io').listen(8080),
	osc = require('node-osc'),
	util = require('util');

var client = new osc.Client('localhost', 3333);	

io.sockets.on('connection', function(socket) { // connecta o servidor ao socket.io
	socket.on('shit', function(data) { // canal que envia a informação do cliente para server :: shit (data é a informação enviada)
		client.send('/mousePositionY', data); // canal que envia a informação vinda do server para osc :: signalWhatever (data é a informação enviada)
				// client.send('asda', {'data1': data, 'data2': datazz}); //send more data using json
				// client.send('/mousePositionY', [data, hhh]); // or send more data using an array
	});

	socket.on('shithorse', function(data) {
		client.send('/mousePositionX', data); 
	});

	socket.on('horse', function(data) { 
		client.send('/clicked', data); 
	});


});

// io.sockets.on('connection', function(socket) { // connecta o servidor ao socket.io
// 	socket.on('userclicked', function(data) { // canal que envia a informação do cliente para server :: shit (data é a informação enviada)
// 		client.send('sendMyClick', data); // canal que envia a inforação vinda do server para osc :: signalWhatever (data é a informação enviada)
// 	});
// });