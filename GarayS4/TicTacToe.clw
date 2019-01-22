; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTicTacToeDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TicTacToe.h"

ClassCount=3
Class1=CTicTacToeApp
Class2=CTicTacToeDlg

ResourceCount=3
Resource2=IDD_TICTACTOE_DIALOG
Resource1=IDR_MAINFRAME
Class3=CBoard
Resource3=IDD_TICTACTOE_DIALOG (English (U.S.))

[CLS:CTicTacToeApp]
Type=0
HeaderFile=TicTacToe.h
ImplementationFile=TicTacToe.cpp
Filter=N

[CLS:CTicTacToeDlg]
Type=0
HeaderFile=TicTacToeDlg.h
ImplementationFile=TicTacToeDlg.cpp
Filter=D
LastObject=IDC_RESTART
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_TICTACTOE_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CTicTacToeDlg

[DLG:IDD_TICTACTOE_DIALOG (English (U.S.))]
Type=1
Class=CTicTacToeDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_BOARD,static,1350566150
Control3=IDC_TURN,static,1342312448
Control4=IDC_COMPUTER,button,1342242816
Control5=IDC_RESTART,button,1342242816

[CLS:CBoard]
Type=0
HeaderFile=Board.h
ImplementationFile=Board.cpp
BaseClass=CStatic
Filter=W
LastObject=CBoard
VirtualFilter=WC

