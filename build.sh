# If you already install g++ or build-essential, use this
sudo apt-get install clang
sudo apt-get install boxes
clang++ script/CPPBot.cpp script/enet/callbacks.c script/enet/compress.c script/enet/host.c script/enet/list.c script/enet/packet.c script/enet/peer.c script/enet/protocol.c script/enet/unix.c -pthread -std=c++11 -fpermissive -o cid -w #Build source code into executable
echo "Build Successfully! you just do ./cid on terminal"