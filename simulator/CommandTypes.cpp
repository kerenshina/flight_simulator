#include "CommandTypes.h"
#include "Command.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <thread>
#include <sstream>


using namespace std;


void updateOutputVals(vector<double> data){
    outputVals["airspeed"].setValue(data[0]);
    outputVals["alt"].setValue(data[4]);
    outputVals["heading"].setValue(data[3]);
    outputVals["pitch"].setValue(data[8]);
    outputVals["roll"].setValue(data[7]);
    outputVals["rpm"].setValue(data[35]);
}

OpenServerCommand::OpenServerCommand() {

}

int OpenServerCommand::execute(vector<string> parameters) {
    if (parameters.size() != 1) {
        cout << "number of parameters sent to command doesn't match the command type!" << endl;
        return 0;
    }
   int sourcePort = atoi(parameters[0].c_str());
   createServer(sourcePort);

    return parameters.size() ;
}
void getInfo(int client_socket){
    cout<<"INSIDE GET INFO";
    char buffer[1024] = {0};
    vector<double>info;
    while(running){
        mutexLock.lock();
        read(client_socket,buffer,1024);
        string buff=buffer;
        size_t pos=0;
        string delimiter = ",";
        while ((pos = buff.find(delimiter)) != string::npos) {
            info.push_back(stod(buff.substr(0, pos)));
            buff.erase(0, pos + delimiter.length());
        }
        info.push_back(stod(buff.substr(0, pos)));
        memset(buffer,0,1024);
        updateOutputVals(info);
        this_thread::sleep_for(chrono::milliseconds(100));
        mutexLock.unlock();
    }
}

//create server
void OpenServerCommand::createServer(int sourcePort) {
   int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Couldn't create a socket" << std::endl;
        return;
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(sourcePort);

    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Couldn't bind the socket to an IP" << std::endl;
        return;
    }
    // listen
    if (listen(socketfd, 5) == -1) {
        std::cerr << "Err during listening command" << std::endl;
        return;
    }
    cout << "Server is now listening..." << endl;
    // accept
    int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
        return;
    }
    cout << "Server Connected" << endl;
    ///Unlock the thread after connection with the simulator
    thread t1(getInfo,client_socket);
    t1.join();
}
OpenServerCommand::~OpenServerCommand() {

}


ConnectCommand::ConnectCommand(){

}

int ConnectCommand::execute(vector<string> parameters) {
return 2;
}

ConnectCommand::~ConnectCommand() {

}


DefineVarCommand::DefineVarCommand(map<string, Variable*>* symbolTable) {
    this->symbolTable = symbolTable;
}

int DefineVarCommand::execute(vector<string> parameters) {
    Variable newVar = Variable();
    if (symbolTable->find(parameters[0]) != symbolTable->end()) {
        cout << "Invalid variable definition!" << endl;
        return 0;
    }
    newVar.setSim(parameters[3]);
    if (parameters[1].compare("->")){
        outputVals.emplace(parameters[0],newVar);
    } else if (parameters[1].compare("<-")){
        inputVals.emplace(parameters[0],newVar);
    }
//-        newVar.setSim(parameters[3]);
        symbolTable->insert({parameters[0], &newVar});
        return parameters.size();
     //else if (parameters[1].compare("=") && symbolTable->find(parameters[2]) != symbolTable->end()) {
//-        newVar.setSim(symbolTable->find(parameters[2])->second->getSim());
//-        newVar.setDirectionByInt(symbolTable->find(parameters[2])->second->getDirection());
//-        newVar.setValue(symbolTable->find(parameters[2])->second->getValue());
      //  symbolTable->insert({parameters[0], newVar});
       // return parameters.size();
  //  } else {
      //  cout << "Invalid variable definition!" << endl;
       // return 0;
}

DefineVarCommand::~DefineVarCommand() {

}


UpdateVarCommand::UpdateVarCommand(map<string, Variable*>* symbolTable) {
    this->symbolTable = symbolTable;
}

int UpdateVarCommand::execute(vector<string> parameters) {
    auto itr = symbolTable->find(parameters[0]);
    if (itr == symbolTable->end()) {
        cout << "Invalid variable!" << endl;
        return 0;
    }
    itr->second->setValue(atof(parameters[1].c_str()));
    return parameters.size() -1 ;
}

UpdateVarCommand::~UpdateVarCommand() {

}


SleepCommand::SleepCommand() {

}

int SleepCommand::execute(vector<string> parameters) {
return parameters.size();
}

SleepCommand::~SleepCommand() {

}


PrintCommand::PrintCommand() {

}

int PrintCommand::execute(vector<string> parameters) {
    cout<<parameters[0]<<endl;
    if (parameters[0].compare("done")==0){
        running=false;
    }
return parameters.size();
}
PrintCommand::~PrintCommand() {
}
