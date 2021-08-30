#pragma once
class ApplicationState
{
private:
public:
	ApplicationState();
	int handleMessage(int uMsg, int wParam, int lParam);
	bool getRenderData();
};