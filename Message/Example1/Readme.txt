gcc send.c -o send
gcc receive.c -o receive

execute send and receive separately.

./receive

then check the pid of receive
ex: 100

./send 100 1  // the pid of receive: 100, Execute times: 1


