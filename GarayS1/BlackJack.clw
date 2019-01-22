; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBlackJackDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BlackJack.h"

ClassCount=4
Class1=CBlackJackApp
Class2=CBlackJackDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_BLACKJACK_DIALOG
Resource4=IDD_ABOUTBOX (Spanish (Modern))
Class4=CRectangles
Resource5=IDD_BLACKJACK_DIALOG (Spanish (Modern))

[CLS:CBlackJackApp]
Type=0
HeaderFile=BlackJack.h
ImplementationFile=BlackJack.cpp
Filter=N

[CLS:CBlackJackDlg]
Type=0
HeaderFile=BlackJackDlg.h
ImplementationFile=BlackJackDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CBlackJackDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=BlackJackDlg.h
ImplementationFile=BlackJackDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_BLACKJACK_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CBlackJackDlg

[DLG:IDD_BLACKJACK_DIALOG (Spanish (Modern))]
Type=1
Class=CBlackJackDlg
ControlCount=25
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_POINTS,edit,1350633600
Control4=IDC_START,button,1342242816
Control5=IDC_RECTANGLES,static,1350569990
Control6=IDC_WINS,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_LOSSES,edit,1350633600
Control9=IDC_STATIC,static,1342308352
Control10=IDC_COMPUTER,static,1350701056
Control11=IDC_STATIC,static,1342308352
Control12=IDC_HITME,button,1476460544
Control13=IDC_STAND,button,1476460544
Control14=IDC_RECTANGLES2,static,1350569990
Control15=IDC_POINTS2,edit,1350633600
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342177288
Control22=IDC_STATIC,static,1342177288
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX (Spanish (Modern))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CRectangles]
Type=0
HeaderFile=Rectangles.h
ImplementationFile=Rectangles.cpp
BaseClass=CStatic
Filter=W
LastObject=CRectangles
VirtualFilter=WC

