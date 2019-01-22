; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQuesPageD
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "questions.h"

ClassCount=7
Class1=CQuestionsApp
Class2=CQuesPageZ

ResourceCount=6
Resource1=IDR_MAINFRAME
Class3=CQuestionsPsh
Resource2=IDD_QUES_PAGED (English (U.S.))
Class4=CQuesPageA
Class5=CQuesPageB
Resource3=IDD_QUES_PAGEA (English (U.S.))
Resource4=IDD_QUES_PAGEZ (English (U.S.))
Class6=CQuesPageC
Resource5=IDD_QUES_PAGEC (English (U.S.))
Class7=CQuesPageD
Resource6=IDD_QUES_PAGEB (English (U.S.))

[CLS:CQuestionsApp]
Type=0
HeaderFile=questions.h
ImplementationFile=questions.cpp
Filter=N
LastObject=CQuestionsApp

[CLS:CQuestionsPsh]
Type=0
HeaderFile=QuestionsPsh.h
ImplementationFile=QuestionsPsh.cpp
BaseClass=CPropertySheet
Filter=W
LastObject=CQuestionsPsh

[DLG:IDD_QUES_PAGEA (English (U.S.))]
Type=1
Class=CQuesPageA
ControlCount=11
Control1=IDC_TEXT_QUES1,static,1342308352
Control2=IDC_ANSWER1,button,1342308361
Control3=IDC_ANSWER2,button,1342177289
Control4=IDC_ANSWER3,button,1342177289
Control5=IDC_ANSWER4,button,1342177289
Control6=IDC_ANSWER5,button,1342177289
Control7=IDC_TEXT_ANSWER1,static,1342308352
Control8=IDC_TEXT_ANSWER2,static,1342308352
Control9=IDC_TEXT_ANSWER4,static,1342308352
Control10=IDC_TEXT_ANSWER3,static,1342308352
Control11=IDC_TEXT_ANSWER5,static,1342308352

[CLS:CQuesPageA]
Type=0
HeaderFile=QuesPageA.h
ImplementationFile=QuesPageA.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CQuesPageA
VirtualFilter=idWC

[CLS:CQuesPageB]
Type=0
HeaderFile=QuesPageB.h
ImplementationFile=QuesPageB.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CQuesPageB
VirtualFilter=idWC

[DLG:IDD_QUES_PAGEB (English (U.S.))]
Type=1
Class=CQuesPageB
ControlCount=2
Control1=IDC_TEXTQUES2,static,1342308352
Control2=IDC_PAGEBLIST,listbox,1352728913

[CLS:CQuesPageC]
Type=0
HeaderFile=QuesPageC.h
ImplementationFile=QuesPageC.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=IDC_TEXT_QUES3
VirtualFilter=idWC

[DLG:IDD_QUES_PAGEC (English (U.S.))]
Type=1
Class=CQuesPageC
ControlCount=3
Control1=IDC_TEXT_QUES3,static,1342308352
Control2=IDC_ANSWER,edit,1350631552
Control3=IDC_STATIC,static,1342177294

[DLG:IDD_QUES_PAGED (English (U.S.))]
Type=1
Class=CQuesPageD
ControlCount=3
Control1=IDC_TEXT_QUES4,static,1342308352
Control2=IDC_NUMBER,edit,1350631552
Control3=IDC_SPIN,msctls_updown32,1342177394

[CLS:CQuesPageD]
Type=0
HeaderFile=QuesPageD.h
ImplementationFile=QuesPageD.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CQuesPageD
VirtualFilter=idWC

[DLG:IDD_QUES_PAGEZ (English (U.S.))]
Type=1
Class=CQuesPageZ
ControlCount=16
Control1=IDC_TEXTQUES1,static,1342308352
Control2=IDC_STATIC,button,1342177287
Control3=IDC_ANSWER1,edit,1350633600
Control4=IDC_TEXTQUES2,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_ANSWER2,edit,1350633600
Control7=IDC_TEXTQUES3,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_ANSWER3,edit,1350633600
Control10=IDC_TEXTQUES4,static,1342308352
Control11=IDC_STATIC,button,1342177287
Control12=IDC_ANSWER4,edit,1350633600
Control13=IDC_TEXTQUES5,static,1342308352
Control14=IDC_STATIC,button,1342177287
Control15=IDC_ANSWER5,edit,1350633600
Control16=IDC_SAVEAS,button,1342242816

[CLS:CQuesPageZ]
Type=0
HeaderFile=QuesPageZ.h
ImplementationFile=QuesPageZ.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=IDC_SAVEAS
VirtualFilter=idWC

