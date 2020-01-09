#include "CommandTypes.h"
#include "Command.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

OpenServerCommand::OpenServerCommand() {

}

int OpenServerCommand::execute(vector<string> parameters) {
    if (parameters.size() != 1) {
        cout << "number of parameters sent to command doesn't match the command type!" << endl;
        return 0;
    }
    int sourcePort = atoi(parameters[0].c_str());
    //createServer(sourcePort);
    return parameters.size() + 1;
}
//create server
//void OpenServerCommand::createServer(int sourcePort) {
//// exemple of
//    int server_fd, new_socket, valread;
//    struct sockaddr_in address;
//    int opt = 1;
//    int addrlen = sizeof(address);
//    char buffer[2048] = {0};
//    char *hello = "Hello from server";
//
//    // Creating socket file descriptor
//    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
//        perror("socket failed");
//        exit(EXIT_FAILURE);
//    }
//
//    // Forcefully attaching socket to the port 8080
//    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
//                   &opt, sizeof(opt))) {
//        perror("setsockopt");
//        exit(EXIT_FAILURE);
//    }
//    address.sin_family = AF_INET;
//    address.sin_addr.s_addr = INADDR_ANY;
//    address.sin_port = htons(sourcePort);
//
//    // Forcefully attaching socket to the port 8080
//    if (bind(server_fd, (struct sockaddr *) &address,
//             sizeof(address)) < 0) {
//        perror("bind failed");
//        exit(EXIT_FAILURE);
//    }
//    if (listen(server_fd, 3) < 0) {
//        perror("listen");
//        exit(EXIT_FAILURE);
//    }
//    if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
//                             (socklen_t *) &addrlen)) < 0) {
//        perror("accept");
//        exit(EXIT_FAILURE);
//    }
//    valread = read(new_socket, buffer, 2048);
//    printf("%s\n", buffer);
//    send(new_socket, hello, strlen(hello), 0);
//    printf("Hello message sent\n");
//}
OpenServerCommand::~OpenServerCommand() {

}


ConnectCommand::ConnectCommand(){

}

int ConnectCommand::execute(vector<string> parameters) {

}

ConnectCommand::~ConnectCommand() {

}


DefineVarCommand::DefineVarCommand(map<string, Variable*>* symbolTable) {
    this->symbolTable = symbolTable;
}

int DefineVarCommand::execute(vector<string> parameters) {
    Variable newVar;

    if (symbolTable->find(parameters[0]) != symbolTable->end()) {
        cout << "Invalid variable definition!" << endl;
        return 0;
    }

    if (parameters[1].compare("->") || parameters[1].compare("<-")) {
     //-   newVar.setDirectionByStr(parameters[1]);
        if (parameters[2].compare("sim") != 0) {
            cout << "Invalid variable definition!" << endl;
            return 0;
        }
//-        newVar.setSim(parameters[3]);
        symbolTable->insert({parameters[0], &newVar});
        return parameters.size();
    } else if (parameters[1].compare("=") && symbolTable->find(parameters[2]) != symbolTable->end()) {
//-        newVar.setSim(symbolTable->find(parameters[2])->second->getSim());
//-        newVar.setDirectionByInt(symbolTable->find(parameters[2])->second->getDirection());
//-        newVar.setValue(symbolTable->find(parameters[2])->second->getValue());
        symbolTable->insert({parameters[0], &newVar});
        return parameters.size();
    } else {
        cout << "Invalid variable definition!" << endl;
        return 0;
    }

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
//-    itr->second->setValue(atof(parameters[0].c_str()));
    return parameters.size() + 1;
}

UpdateVarCommand::~UpdateVarCommand() {

}


SleepCommand::SleepCommand() {

}

int SleepCommand::execute(vector<string> parameters) {

}

SleepCommand::~SleepCommand() {

}


PrintCommand::PrintCommand() {

}

int PrintCommand::execute(vector<string> parameters) {

}

PrintCommand::~PrintCommand() {

}
