; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFlightDoc
LastTemplate=CScrollView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "flight.h"
LastPage=0

ClassCount=6
Class1=CFlightApp
Class2=CAboutDlg
Class3=CFlightDoc
Class4=CFlightView
Class5=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX (Spanish (Modern))
Resource2=IDD_FLIGHT_FORM (Spanish (Modern))
Class6=CMapView
Resource3=IDR_MAINFRAME (Spanish (Modern))

[CLS:CFlightApp]
Type=0
BaseClass=CWinApp
HeaderFile=Flight.h
ImplementationFile=Flight.cpp
LastObject=CFlightApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Flight.cpp
ImplementationFile=Flight.cpp
LastObject=CAboutDlg

[CLS:CFlightDoc]
Type=0
BaseClass=CDocument
HeaderFile=FlightDoc.h
ImplementationFile=FlightDoc.cpp
LastObject=ID_FILE_OPENTEXT
Filter=N
VirtualFilter=DC

[CLS:CFlightView]
Type=0
BaseClass=CFormView
HeaderFile=FlightView.h
ImplementationFile=FlightView.cpp
Filter=D
VirtualFilter=VWC
LastObject=CFlightView

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
LastObject=CMainFrame
Filter=T
VirtualFilter=fWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg

[DLG:IDD_FLIGHT_FORM]
Type=1
Class=CFlightView

[TB:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_OPENTEXT
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_APP_ABOUT
CommandCount=14

[ACL:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_ABOUTBOX (Spanish (Modern))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FLIGHT_FORM (Spanish (Modern))]
Type=1
Class=CFlightView
ControlCount=18
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_NAME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_NORTHLAT,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_WESTLON,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_DEP_TIME,edit,1350631552
Control10=IDC_ADD_CITY,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_ORIG_CITY,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_DEST_CITY,edit,1350631552
Control15=IDC_ADD_FLIGHT,button,1342242816
Control16=IDC_CITY_LIST,SysListView32,1350631429
Control17=IDC_FLIGHT_LIST,SysListView32,1350631429
Control18=IDC_STATIC,button,1342177287

[CLS:CMapView]
Type=0
HeaderFile=MapView.h
ImplementationFile=MapView.cpp
BaseClass=CScrollView
Filter=C
LastObject=CMapView
VirtualFilter=VWC

