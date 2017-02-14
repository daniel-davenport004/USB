#include "Application.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	Application * theApp = new Application();

	if (FAILED(theApp->Initialise(hInstance, nCmdShow)))
	{
		return -1;
	}

    // Main message loop
    MSG msg = {0};

	DWORD presetFrameInterval = 25; // one frame every 25 milliseconds; 40 fps
	DWORD frameProcessingTime = 0;

    while (WM_QUIT != msg.message)
    {
		DWORD frameStartTime = GetTickCount();

        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
			bool handled = false;

			if (msg.message >= WM_KEYFIRST && msg.message <= WM_KEYLAST)
			{
				handled = theApp->HandleKeyboard(msg);
			}
			else if (WM_QUIT == msg.message)
				break;

			if (!handled)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
        }
        else
		{
			theApp->Update(frameProcessingTime);

			frameProcessingTime = GetTickCount() - frameStartTime;

			if (frameProcessingTime < presetFrameInterval)
			{
				// Delay
				Sleep(presetFrameInterval - frameProcessingTime);
				frameProcessingTime = presetFrameInterval;
			}

            theApp->Draw();
        }
    }

	delete theApp;
	theApp = nullptr;

    return (int) msg.wParam;
}