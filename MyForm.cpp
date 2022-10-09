#include "MyForm.h"
using namespace Project8;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project8::MyForm form;
	Application::Run(% form);
	return 0;
}


