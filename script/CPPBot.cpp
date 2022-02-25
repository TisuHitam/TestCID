// CPPBot.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "HTTPRequest.hpp"
#include <sys/system_properties.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include <future>
#include <thread>
#include <chrono>
#include "corefunc.h"
#include "userfunc.h"
#include <string>
#include <unistd.h>
#include <stdint.h>
#include "json.hpp"
//#include <curses.h>
//#include <conio.h>
//#include <windows.h>
using json = nlohmann::json;
using namespace std;
http::Request request{"http://growtopia2.com/growtopia/server_data.php"};
const auto response = request.send("GET");
string dataserver = string{response.body.begin(), response.body.end()};
string sport = dataserver.substr(29, 5);
string servergt = dataserver.substr(7, 15);
int portgt = stoi(sport);
vector<GrowtopiaBot> bots;
GrowtopiaBot bot = {"", "", "", -1};
GrowtopiaBot bot1 = {"", "", "", -1};
GrowtopiaBot bot2 = {"", "", "", -1};
GrowtopiaBot bot3 = {"", "", "", -1};
GrowtopiaBot bot4 = {"", "", "", -1};
void CheckGrowid() {
	if (Growid_acc.find("${Angka}") != std::string::npos) {
			int found = -1;
			found = Growid_acc.find("${Angka}", found+1);
			GrowidBelakang = Growid_acc.substr(found+8, Growid_acc.length());
			if (not found == 0) {
				GrowidDepan = Growid_acc.substr(0, found);
			}
		} else {
			GrowidDepan = Growid_acc;
		}
}
void BroadCastGoWorld(string name)
{
	bot.gotow(name);
}
void BroadCastPacket(int typ, string text)
{
	bot.packetPeer(typ, text);
}
string getBotPos()
{
	string datas = "";
	if (bot.getPeer())
		datas += "BOT : x:" + to_string(bot.localX) + " y: " + to_string(bot.localY) + "\n";
	return datas;
}
void input()
{
	int c = 0;
	while (1)
	{
		string data;
		getline(cin, data);
		if (data == "/bot")
		{
			if (bot.getPeer())
				cout << bot.uname << " At " << bot.world->name << endl;
		}
		else if (data.find("/say ") != std::string::npos)
			BroadCastPacket(2, "action|input\n|text|" + data.substr(5));
		else if (data == "/status")
		{
			string status = "";
			if (bot.getPeer())
				;
			status += "BOT 1: ON\n";
		}
		else if (data == "/pos")
			getBotPos();
		else if (data == "/help")
			cout << "Console Command: /clear, go <name>, /status, /bot (print bot world), /say <text>,/pos" << endl;
		else if (data.find("/go ") != std::string::npos)
		{
			string wr = data.substr(4);
			BroadCastGoWorld(wr);
			cout << "Going to: " << wr << endl;
		}
		else if (data == "/clear")
			system("clear");
	}
}
GrowtopiaBot makeBot(string user, string pass, string host, int portgt, string vers, string wname)
{
	GrowtopiaBot bot = {user, pass, host, portgt};
	bot.gameVersion = vers;
	bot.currentWorld = wname;
	bot.userInit();
	bots.push_back(bot);
	return bot;
}
void botSetup()
{
	system("clear");
	cout << "File : " + filename + "\n" << endl;
	bot = makeBot("", "", servergt, portgt, "3.81", "");
	bot1 = makeBot("", "", servergt, portgt, "3.81", "");
    bot2 = makeBot("", "", servergt, portgt, "3.81", "");
    bot3 = makeBot("", "", servergt, portgt, "3.81", "");
    bot4 = makeBot("", "", servergt, portgt, "3.81", "");
	while (true)
	{
		bot.eventLoop();
		bot1.eventLoop();
        bot2.eventLoop();
        bot3.eventLoop();
        bot4.eventLoop();
	}
}
int main()
{
		system("clear");
		cout << "Script By ARR\n" << endl;
		cout << "Anda Terdeteksi Android Version " + osVersion << endl;
		if (osVersion == "11") {
			cout << "File Diganti Ke : `acc.txt`\n" << endl;
			filename = "0";
		} else if (osVersion == "12") {
		cout << "File Diganti Ke : `acc.txt`\n" << endl;
		filename = "0";
		} else {
			cout << "File Diganti Ke : `GrowID : ${GrowID}.txt`\n" << endl;
			filename = "1";
		}
		cout << "Memasuki : http://growtopia2.com/growtopia/server_data.php" << endl;
		cout << dataserver << "\n" << endl;
		cout << "Get Server : " << servergt << endl;
		cout << "Get Port : " << portgt << "\n" << endl;
		cout << "GrowID : ";
		cin >> Growid_acc;
		CheckGrowid();
		cout << "Password : ";
		cin >> Password_acc;
		cout << "Email : ";
		cin >> Email_acc;
		cout << "Start Number : ";
		cin >> START_DARI;
		cout << "End Number : ";
		cin >> END_NUMBER;
		if (filename == "1") {
			filename = "GrowID : " + GrowidDepan + GrowidBelakang + ".txt";
		} else {
			filename = "acc.txt";
		}
		std::thread thr(input);
		thr.detach();
		botSetup();
}