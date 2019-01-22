; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSoundDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Sound.h"

ClassCount=3
Class1=CSoundApp
Class2=CSoundDlg

ResourceCount=3
Resource2=IDD_SOUND_DIALOG
Resource1=IDR_MAINFRAME
Class3=CWAVdisp
Resource3=IDD_SOUND_DIALOG (English (U.S.))

[CLS:CSoundApp]
Type=0
HeaderFile=Sound.h
ImplementationFile=Sound.cpp
Filter=N
LastObject=CSoundApp

[CLS:CSoundDlg]
Type=0
HeaderFile=SoundDlg.h
ImplementationFile=SoundDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDOK



[DLG:IDD_SOUND_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CSoundDlg

[DLG:IDD_SOUND_DIALOG (English (U.S.))]
Type=1
Class=CSoundDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_INPUT_NAME,edit,1350633600
Control3=IDC_BROWSE,button,1342242816
Control4=IDC_SAVE,button,1342242816
Control5=IDC_WAVEDISP,static,1350570246
Control6=IDC_STATIC,button,1342177287

[CLS:CWAVdisp]
Type=0
HeaderFile=WAVdisp.h
ImplementationFile=WAVdisp.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC
LastObject=CWAVdisp

