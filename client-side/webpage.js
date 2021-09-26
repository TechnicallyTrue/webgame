/*const http = require('http')
const fs = require('fs')

const webserver = http.createServer((req, res) => {
	res.writeHead(200, {'content-type': 'text/html'})
	fs.createReadStream('index.html').pipe(res)
})

webserver.listen(process.env.PORT || 8080)*/

var http = require('http');  
var url = require('url');  
var fs = require('fs');  
var webserver = http.createServer(function(req, res) {  
    var path = url.parse(req.url).pathname;  
    fs.readFile(__dirname + path, function(error, data) {  
        if (error) {  
            res.writeHead(404);  
            res.write('This page does not exist');
            res.end();  
        } else {  
            res.writeHead(200, {  
                'Content-Type': 'text/html'
            }); 
            res.write(data);  
            res.end();  
        }  
    }); 
});  
webserver.listen(8080);
