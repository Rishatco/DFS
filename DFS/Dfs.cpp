#include "Dfs.h"
#include "GUI/guifrmMain.h"

IMPLEMENT_APP(HelloApp)




HelloApp::HelloApp() {
}

HelloApp::~HelloApp() {
}

bool HelloApp::OnInit() {
	guifrmMain* frame = new guifrmMain((wxWindow*)NULL);
	frame->Show();
	SetTopWindow(frame);
	return true;
}