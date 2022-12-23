//
// Created by sigit dani perkasa on 18/08/2022.
//
#define UNICODE
#include "KinovaTypes.h"
#include <iostream>
#include <windows.h>
#include "CommunicationLayer.h"
#include "CommandLayer.h"
#include <conio.h>

using namespace std;

HINSTANCE commandLayer_handle;
int(*MyInitAPI)();
int(*MyCloseAPI)();
int(*MySendBasicTrajectory)(TrajectoryPoint command);
int(*MyGetDevices)(KinovaDevice devices[MAX_KINOVA_DEVICE], int &result);
int(*MySetActiveDevice)(KinovaDevice device);
int(*MyMoveHome)();
int(*MyInitFingers)();
int(*MyGetCartesianCommand)(CartesianPosition &);

int main(){
    CartesianPosition currentCommand;
    int programResult = 0;

    commandLayer_handle = LoadLibraryA("CommandLayerWindows.dll");

    MyInitAPI = (int(*)()) GetProcAddress(commandLayer_handle, "InitAPI");
    MyCloseAPI = (int(*)()) GetProcAddress(commandLayer_handle, "CloseAPI");
    MyMoveHome = (int(*)()) GetProcAddress(commandLayer_handle, "MoveHome");
    MyInitFingers = (int(*)()) GetProcAddress(commandLayer_handle, "InitFingers");
    MyGetDevices = (int(*)(KinovaDevice devices[MAX_KINOVA_DEVICE],
                           int &result)) GetProcAddress(commandLayer_handle, "GetDevices");
    MySetActiveDevice = (int(*)(KinovaDevice devices)) GetProcAddress(commandLayer_handle,
                                                                      "SetActiveDevice");
    MySendBasicTrajectory = (int(*)(TrajectoryPoint)) GetProcAddress(commandLayer_handle,
                                                                     "SendBasicTrajectory");
    MyGetCartesianCommand = (int(*)(CartesianPosition &)) GetProcAddress(commandLayer_handle,
                                                                         "GetCartesianCommand");

    if ((MyInitAPI == NULL) || (MyCloseAPI == NULL) || (MySendBasicTrajectory == NULL) ||
        (MyGetDevices == NULL) || (MySetActiveDevice == NULL) || (MyGetCartesianCommand == NULL) ||
        (MyMoveHome == NULL) || (MyInitFingers == NULL)){

        cout << "init error/n";
        programResult = 0;
    }
    else{

        cout << "initialization complete" << endl;

        int result = (*MyInitAPI)();
        CartesianPosition currentCommand;
        KinovaDevice list[MAX_KINOVA_DEVICE];
        int devicesCount = MyGetDevices(list, result);

        for (int i = 0; i < devicesCount; i++) {
            cout << "robot found: " << list[i].SerialNumber << endl;
            MySetActiveDevice(list[i]);

            MyInitFingers();
            TrajectoryPoint pointToSend;
            pointToSend.InitStruct();
            
            pointToSend.Position.Type = CARTESIAN_POSITION;

//     		pointToSend.Position.CartesianPosition.X = 0.211792;
//pointToSend.Position.CartesianPosition.Y = -0.266734;
//pointToSend.Position.CartesianPosition.Z = 0.505966;
//pointToSend.Position.CartesianPosition.ThetaX = 1.64961;
//pointToSend.Position.CartesianPosition.ThetaY = 1.11148;
//pointToSend.Position.CartesianPosition.ThetaZ = 0.131208;
//pointToSend.Position.Fingers.Finger1 = 3342;
//pointToSend.Position.Fingers.Finger2 = 3426;
//pointToSend.Position.Fingers.Finger3 = 1428;
//MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.686806;
pointToSend.Position.CartesianPosition.Y = -0.190583;
pointToSend.Position.CartesianPosition.Z = 0.495772;
pointToSend.Position.CartesianPosition.ThetaX = -2.1097;
pointToSend.Position.CartesianPosition.ThetaY = 1.47086;
pointToSend.Position.CartesianPosition.ThetaZ = -2.39766;
pointToSend.Position.Fingers.Finger1 = 3342;
pointToSend.Position.Fingers.Finger2 = 3426;
pointToSend.Position.Fingers.Finger3 = 1428;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.600273;
pointToSend.Position.CartesianPosition.Y = -0.18714;
pointToSend.Position.CartesianPosition.Z = 0.073012;
pointToSend.Position.CartesianPosition.ThetaX = -2.36696;
pointToSend.Position.CartesianPosition.ThetaY = 1.4986;
pointToSend.Position.CartesianPosition.ThetaZ = -2.1392;
pointToSend.Position.Fingers.Finger1 = 3342;
pointToSend.Position.Fingers.Finger2 = 3426;
pointToSend.Position.Fingers.Finger3 = 1428;
MySendBasicTrajectory(pointToSend);



pointToSend.Position.CartesianPosition.X = 0.562648;
pointToSend.Position.CartesianPosition.Y = 0.0373124;
pointToSend.Position.CartesianPosition.Z = 0.0755753;
pointToSend.Position.CartesianPosition.ThetaX = -1.45481;
pointToSend.Position.CartesianPosition.ThetaY = -0.0843519;
pointToSend.Position.CartesianPosition.ThetaZ = -3.01769;
pointToSend.Position.Fingers.Finger1 = 3342;
pointToSend.Position.Fingers.Finger2 = 3426;
pointToSend.Position.Fingers.Finger3 = 1428;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.563818;
pointToSend.Position.CartesianPosition.Y = 0.0376363;
pointToSend.Position.CartesianPosition.Z = 0.0158775;
pointToSend.Position.CartesianPosition.ThetaX = -1.45579;
pointToSend.Position.CartesianPosition.ThetaY = -0.0821879;
pointToSend.Position.CartesianPosition.ThetaZ = -3.02262;
pointToSend.Position.Fingers.Finger1 = 3342;
pointToSend.Position.Fingers.Finger2 = 3426;
pointToSend.Position.Fingers.Finger3 = 1428;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.563819;
pointToSend.Position.CartesianPosition.Y = 0.0376361;
pointToSend.Position.CartesianPosition.Z = 0.0158733;
pointToSend.Position.CartesianPosition.ThetaX = -1.45579;
pointToSend.Position.CartesianPosition.ThetaY = -0.0821829;
pointToSend.Position.CartesianPosition.ThetaZ = -3.0226;
pointToSend.Position.Fingers.Finger1 = 528;
pointToSend.Position.Fingers.Finger2 = 618;
pointToSend.Position.Fingers.Finger3 = 6;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.577877;
pointToSend.Position.CartesianPosition.Y = 0.10163;
pointToSend.Position.CartesianPosition.Z = 0.015262;
pointToSend.Position.CartesianPosition.ThetaX = -1.45833;
pointToSend.Position.CartesianPosition.ThetaY = -0.123989;
pointToSend.Position.CartesianPosition.ThetaZ = -3.01639;
pointToSend.Position.Fingers.Finger1 = 528;
pointToSend.Position.Fingers.Finger2 = 618;
pointToSend.Position.Fingers.Finger3 = 6;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.577877;
pointToSend.Position.CartesianPosition.Y = 0.101631;
pointToSend.Position.CartesianPosition.Z = 0.0152595;
pointToSend.Position.CartesianPosition.ThetaX = -1.45833;
pointToSend.Position.CartesianPosition.ThetaY = -0.123989;
pointToSend.Position.CartesianPosition.ThetaZ = -3.01638;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.575779;
pointToSend.Position.CartesianPosition.Y = 0.12253;
pointToSend.Position.CartesianPosition.Z = 0.234697;
pointToSend.Position.CartesianPosition.ThetaX = -1.45943;
pointToSend.Position.CartesianPosition.ThetaY = -0.108049;
pointToSend.Position.CartesianPosition.ThetaZ = -3.00658;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.559078;
pointToSend.Position.CartesianPosition.Y = 0.462366;
pointToSend.Position.CartesianPosition.Z = 0.230746;
pointToSend.Position.CartesianPosition.ThetaX = -1.46486;
pointToSend.Position.CartesianPosition.ThetaY = -0.282178;
pointToSend.Position.CartesianPosition.ThetaZ = -2.98621;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.0922354;
pointToSend.Position.CartesianPosition.Y = 0.557933;
pointToSend.Position.CartesianPosition.Z = 0.237885;
pointToSend.Position.CartesianPosition.ThetaX = -1.38679;
pointToSend.Position.CartesianPosition.ThetaY = -0.985124;
pointToSend.Position.CartesianPosition.ThetaZ = -2.87726;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.00648765;
pointToSend.Position.CartesianPosition.Y = 0.533739;
pointToSend.Position.CartesianPosition.Z = 0.145944;
pointToSend.Position.CartesianPosition.ThetaX = -1.31593;
pointToSend.Position.CartesianPosition.ThetaY = -1.14581;
pointToSend.Position.CartesianPosition.ThetaZ = -2.79598;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.00663309;
pointToSend.Position.CartesianPosition.Y = 0.534305;
pointToSend.Position.CartesianPosition.Z = 0.146243;
pointToSend.Position.CartesianPosition.ThetaX = -1.25616;
pointToSend.Position.CartesianPosition.ThetaY = -1.20394;
pointToSend.Position.CartesianPosition.ThetaZ = -2.74135;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.0067962;
pointToSend.Position.CartesianPosition.Y = 0.533616;
pointToSend.Position.CartesianPosition.Z = 0.146796;
pointToSend.Position.CartesianPosition.ThetaX = 3.09731;
pointToSend.Position.CartesianPosition.ThetaY = -0.168163;
pointToSend.Position.CartesianPosition.ThetaZ = 1.91232;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.00836021;
pointToSend.Position.CartesianPosition.Y = 0.533753;
pointToSend.Position.CartesianPosition.Z = 0.14652;
pointToSend.Position.CartesianPosition.ThetaX = 3.02252;
pointToSend.Position.CartesianPosition.ThetaY = 0.0504396;
pointToSend.Position.CartesianPosition.ThetaZ = 1.91409;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.00880742;
pointToSend.Position.CartesianPosition.Y = 0.53595;
pointToSend.Position.CartesianPosition.Z = 0.147216;
pointToSend.Position.CartesianPosition.ThetaX = -1.51311;
pointToSend.Position.CartesianPosition.ThetaY = -1.20846;
pointToSend.Position.CartesianPosition.ThetaZ = -3.00235;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.190711;
pointToSend.Position.CartesianPosition.Y = 0.586965;
pointToSend.Position.CartesianPosition.Z = 0.165091;
pointToSend.Position.CartesianPosition.ThetaX = -1.57228;
pointToSend.Position.CartesianPosition.ThetaY = -0.809571;
pointToSend.Position.CartesianPosition.ThetaZ = -3.04989;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.188094;
pointToSend.Position.CartesianPosition.Y = 0.58552;
pointToSend.Position.CartesianPosition.Z = 0.0240963;
pointToSend.Position.CartesianPosition.ThetaX = -1.58547;
pointToSend.Position.CartesianPosition.ThetaY = -0.813601;
pointToSend.Position.CartesianPosition.ThetaZ = -3.06163;
pointToSend.Position.Fingers.Finger1 = 4056;
pointToSend.Position.Fingers.Finger2 = 4158;
pointToSend.Position.Fingers.Finger3 = 3846;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.188093;
pointToSend.Position.CartesianPosition.Y = 0.58552;
pointToSend.Position.CartesianPosition.Z = 0.0240872;
pointToSend.Position.CartesianPosition.ThetaX = -1.58548;
pointToSend.Position.CartesianPosition.ThetaY = -0.813604;
pointToSend.Position.CartesianPosition.ThetaZ = -3.06166;
pointToSend.Position.Fingers.Finger1 = 12;
pointToSend.Position.Fingers.Finger2 = 12;
pointToSend.Position.Fingers.Finger3 = 6;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.189041;
pointToSend.Position.CartesianPosition.Y = 0.587558;
pointToSend.Position.CartesianPosition.Z = 0.176287;
pointToSend.Position.CartesianPosition.ThetaX = -1.57388;
pointToSend.Position.CartesianPosition.ThetaY = -0.810577;
pointToSend.Position.CartesianPosition.ThetaZ = -3.05298;
pointToSend.Position.Fingers.Finger1 = 12;
pointToSend.Position.Fingers.Finger2 = 12;
pointToSend.Position.Fingers.Finger3 = 6;
MySendBasicTrajectory(pointToSend);
	
//KOPI


pointToSend.Position.CartesianPosition.X = 0.184588;
pointToSend.Position.CartesianPosition.Y = 0.584705;
pointToSend.Position.CartesianPosition.Z = 0.0917701;
pointToSend.Position.CartesianPosition.ThetaX = -1.56795;
pointToSend.Position.CartesianPosition.ThetaY = -0.231194;
pointToSend.Position.CartesianPosition.ThetaZ = -3.13687;
pointToSend.Position.Fingers.Finger1 = 12;
pointToSend.Position.Fingers.Finger2 = 12;
pointToSend.Position.Fingers.Finger3 = 6;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.183337;
pointToSend.Position.CartesianPosition.Y = 0.585336;
pointToSend.Position.CartesianPosition.Z = 0.169677;
pointToSend.Position.CartesianPosition.ThetaX = -1.56218;
pointToSend.Position.CartesianPosition.ThetaY = -0.236656;
pointToSend.Position.CartesianPosition.ThetaZ = 3.14;
pointToSend.Position.Fingers.Finger1 = 12;
pointToSend.Position.Fingers.Finger2 = 12;
pointToSend.Position.Fingers.Finger3 = 6;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.430745;
pointToSend.Position.CartesianPosition.Y = 0.12065;
pointToSend.Position.CartesianPosition.Z = 0.175647;
pointToSend.Position.CartesianPosition.ThetaX = -1.56223;
pointToSend.Position.CartesianPosition.ThetaY = 0.786309;
pointToSend.Position.CartesianPosition.ThetaZ = 3.1319;
pointToSend.Position.Fingers.Finger1 = 12;
pointToSend.Position.Fingers.Finger2 = 12;
pointToSend.Position.Fingers.Finger3 = 6;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.471167;
pointToSend.Position.CartesianPosition.Y = 0.161244;
pointToSend.Position.CartesianPosition.Z = 0.0328685;
pointToSend.Position.CartesianPosition.ThetaX = -1.55825;
pointToSend.Position.CartesianPosition.ThetaY = 0.730512;
pointToSend.Position.CartesianPosition.ThetaZ = 3.13004;
pointToSend.Position.Fingers.Finger1 = 12;
pointToSend.Position.Fingers.Finger2 = 12;
pointToSend.Position.Fingers.Finger3 = 6;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.562507;
pointToSend.Position.CartesianPosition.Y = 0.251923;
pointToSend.Position.CartesianPosition.Z = 0.00494173;
pointToSend.Position.CartesianPosition.ThetaX = -1.55957;
pointToSend.Position.CartesianPosition.ThetaY = 0.63835;
pointToSend.Position.CartesianPosition.ThetaZ = 3.12845;
pointToSend.Position.Fingers.Finger1 = 12;
pointToSend.Position.Fingers.Finger2 = 12;
pointToSend.Position.Fingers.Finger3 = 6;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.562507;
pointToSend.Position.CartesianPosition.Y = 0.251925;
pointToSend.Position.CartesianPosition.Z = 0.00493894;
pointToSend.Position.CartesianPosition.ThetaX = -1.55956;
pointToSend.Position.CartesianPosition.ThetaY = 0.638343;
pointToSend.Position.CartesianPosition.ThetaZ = 3.12846;
pointToSend.Position.Fingers.Finger1 = 4212;
pointToSend.Position.Fingers.Finger2 = 4212;
pointToSend.Position.Fingers.Finger3 = 4206;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.561828;
pointToSend.Position.CartesianPosition.Y = 0.253189;
pointToSend.Position.CartesianPosition.Z = 0.171105;
pointToSend.Position.CartesianPosition.ThetaX = -1.56074;
pointToSend.Position.CartesianPosition.ThetaY = 0.631677;
pointToSend.Position.CartesianPosition.ThetaZ = 3.13057;
pointToSend.Position.Fingers.Finger1 = 4212;
pointToSend.Position.Fingers.Finger2 = 4212;
pointToSend.Position.Fingers.Finger3 = 4206;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.00577149;
pointToSend.Position.CartesianPosition.Y = 0.529546;
pointToSend.Position.CartesianPosition.Z = 0.11607;
pointToSend.Position.CartesianPosition.ThetaX = -1.55842;
pointToSend.Position.CartesianPosition.ThetaY = -0.494626;
pointToSend.Position.CartesianPosition.ThetaZ = -3.13852;
pointToSend.Position.Fingers.Finger1 = 4212;
pointToSend.Position.Fingers.Finger2 = 4212;
pointToSend.Position.Fingers.Finger3 = 4206;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.00700849;
pointToSend.Position.CartesianPosition.Y = 0.530557;
pointToSend.Position.CartesianPosition.Z = 0.114502;
pointToSend.Position.CartesianPosition.ThetaX = -1.57583;
pointToSend.Position.CartesianPosition.ThetaY = -1.07321;
pointToSend.Position.CartesianPosition.ThetaZ = 3.13048;
pointToSend.Position.Fingers.Finger1 = 4212;
pointToSend.Position.Fingers.Finger2 = 4212;
pointToSend.Position.Fingers.Finger3 = 4206;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.008202;
pointToSend.Position.CartesianPosition.Y = 0.530112;
pointToSend.Position.CartesianPosition.Z = 0.116401;
pointToSend.Position.CartesianPosition.ThetaX = 2.82967;
pointToSend.Position.CartesianPosition.ThetaY = 0.556935;
pointToSend.Position.CartesianPosition.ThetaZ = 2.1614;
pointToSend.Position.Fingers.Finger1 = 4212;
pointToSend.Position.Fingers.Finger2 = 4212;
pointToSend.Position.Fingers.Finger3 = 4206;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.00741635;
pointToSend.Position.CartesianPosition.Y = 0.532389;
pointToSend.Position.CartesianPosition.Z = 0.120606;
pointToSend.Position.CartesianPosition.ThetaX = -1.73741;
pointToSend.Position.CartesianPosition.ThetaY = -1.06278;
pointToSend.Position.CartesianPosition.ThetaZ = 2.94733;
pointToSend.Position.Fingers.Finger1 = 4212;
pointToSend.Position.Fingers.Finger2 = 4212;
pointToSend.Position.Fingers.Finger3 = 4206;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.187113;
pointToSend.Position.CartesianPosition.Y = 0.595063;
pointToSend.Position.CartesianPosition.Z = 0.119522;
pointToSend.Position.CartesianPosition.ThetaX = -1.68807;
pointToSend.Position.CartesianPosition.ThetaY = -0.759877;
pointToSend.Position.CartesianPosition.ThetaZ = 3.00581;
pointToSend.Position.Fingers.Finger1 = 4212;
pointToSend.Position.Fingers.Finger2 = 4212;
pointToSend.Position.Fingers.Finger3 = 4206;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.181063;
pointToSend.Position.CartesianPosition.Y = 0.592809;
pointToSend.Position.CartesianPosition.Z = 0.0826931;
pointToSend.Position.CartesianPosition.ThetaX = -1.69288;
pointToSend.Position.CartesianPosition.ThetaY = -0.770216;
pointToSend.Position.CartesianPosition.ThetaZ = 3.00079;
pointToSend.Position.Fingers.Finger1 = 4212;
pointToSend.Position.Fingers.Finger2 = 4212;
pointToSend.Position.Fingers.Finger3 = 4206;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.181065;
pointToSend.Position.CartesianPosition.Y = 0.59281;
pointToSend.Position.CartesianPosition.Z = 0.0826847;
pointToSend.Position.CartesianPosition.ThetaX = -1.69288;
pointToSend.Position.CartesianPosition.ThetaY = -0.770214;
pointToSend.Position.CartesianPosition.ThetaZ = 3.0008;
pointToSend.Position.Fingers.Finger1 = -6;
pointToSend.Position.Fingers.Finger2 = 0;
pointToSend.Position.Fingers.Finger3 = -6;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.533182;
pointToSend.Position.CartesianPosition.Y = 0.331607;
pointToSend.Position.CartesianPosition.Z = 0.213513;
pointToSend.Position.CartesianPosition.ThetaX = -1.65404;
pointToSend.Position.CartesianPosition.ThetaY = -0.054463;
pointToSend.Position.CartesianPosition.ThetaZ = 3.09044;
pointToSend.Position.Fingers.Finger1 = 12;
pointToSend.Position.Fingers.Finger2 = 12;
pointToSend.Position.Fingers.Finger3 = -6;
MySendBasicTrajectory(pointToSend);

          
        }

        cout << endl;
        result = (*MyCloseAPI)();
        programResult = 1;
    }

    FreeLibrary(commandLayer_handle);
    return programResult;
}


