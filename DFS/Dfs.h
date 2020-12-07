#ifndef HELLOAPP_H
#define HELLOAPP_H

#include <wx/wx.h>

class HelloApp : public wxApp {
public:
	HelloApp();
	virtual ~HelloApp();
	virtual bool OnInit();
};

DECLARE_APP(HelloApp)

#endif