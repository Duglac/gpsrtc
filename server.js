var http = require('http');
var server = http.createServer(
 function(req,res){
  res.writeHead(200, {'Content-Type':'text/plain'});
  const Time = new Date();
  const {exec} = require("child_process");
  exec("./gps", (error,stdout,stderr) => res.end('Now: ' + Time + "\n" + stdout)
  );
 }
);
server.listen(5050);
