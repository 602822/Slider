// Assignment1v2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Assignment1v2.h"


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ASSIGNMENT1V2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ASSIGNMENT1V2));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ASSIGNMENT1V2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ASSIGNMENT1V2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)

{

	static int state = 3;
	static int stateTL2 = 1;
	static int antalltid = 0;
	static int antalltid2 = 0;

	static BOOL lagBiler = false;
	static BOOL lagBiler2 = false;

	static int nyPosBil[9] = { 0,0,0,0,0,0,0,0,0 };
	static int nyPos2Bil[9] = { 0,0,0,0,0,0,0,0,0 };




	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;

	case WM_LBUTTONDOWN:
	{

		lagBiler = true;

	}
	break;

	case WM_RBUTTONDOWN:
	{
		lagBiler2 = true;
	}
	break;


	case WM_CREATE:
	{
		SetTimer(hWnd, 0, 1800, 0);

		SetTimer(hWnd, 1, 100, 0);

		SetTimer(hWnd, 2, 100, 0);
	}
	break;

	case WM_TIMER:
	{

		//Switch for dei forskejllige timerene, ein for trafikklysene og ein for bilene
		switch (wParam) {
		case 0:
		{

			state += 1;
			stateTL2 += 1;

			if (state == 5) {
				state = 1;
			}

			if (stateTL2 == 5) {
				stateTL2 = 1;
			}



		}
		break;

		// Øker posisjonene til bilene som går horisontalt

		case 1:
		{

			if (lagBiler) {
				antalltid++;
				nyPosBil[0] += 5;

			}

		}

		break;


		// Øker posisjonen til bilene som går vertikalt

		//TODO fiks stoppingen på rødt lys

		case 2:
		{
			if (lagBiler2) {
				antalltid2++;
				nyPos2Bil[0] -= 5;
			}

		}
		break;


		}

		InvalidateRect(hWnd, 0, true);



	}
	break;


	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...

		Rectangle(hdc, 500, 250, 600, 100); //trafikklys 1
		Rectangle(hdc, 400, 300, 550, 400); //trafikklys 2

		HBRUSH greyBrush = CreateSolidBrush(RGB(105, 105, 105));
		HGDIOBJ horg = SelectObject(hdc, greyBrush);


		Rectangle(hdc, 150, 350, 1050, 250);  //vei horisonal
		Rectangle(hdc, 550, 0, 650, 600);    // vei vertikal


		//trafikklys 2
		switch (stateTL2) {
		case 1:
		{
			// HBRUSH hwhiteBrush = CreateSolidBrush(RGB());
			 //venstre top høgre bunn



			HBRUSH hredbrush = CreateSolidBrush(RGB(255, 0, 0));
			HGDIOBJ horg = SelectObject(hdc, hredbrush);
			Ellipse(hdc, 500, 350, 550, 400);



			HBRUSH hgreybrush = CreateSolidBrush(RGB(105, 105, 105));
			SelectObject(hdc, hgreybrush);
			Ellipse(hdc, 450, 350, 500, 400);
			Ellipse(hdc, 400, 350, 450, 400);

			//opprydding
			SelectObject(hdc, horg);
			DeleteObject(hredbrush);
			DeleteObject(hgreybrush);}
		break;

		case 2:
		{

			HBRUSH hredbrush = CreateSolidBrush(RGB(255, 0, 0));
			HGDIOBJ horg = SelectObject(hdc, hredbrush);
			Ellipse(hdc, 500, 350, 550, 400);




			HBRUSH hyellowbrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hyellowbrush);
			Ellipse(hdc, 450, 350, 500, 400);




			HBRUSH hgreybrush = CreateSolidBrush(RGB(105, 105, 105));
			SelectObject(hdc, hgreybrush);
			Ellipse(hdc, 400, 350, 450, 400);

			//opprydding
			SelectObject(hdc, horg);
			DeleteObject(hredbrush);
			DeleteObject(hyellowbrush);
			DeleteObject(hgreybrush);
		}
		break;

		case 3:
		{



			HBRUSH hgreybrush = CreateSolidBrush(RGB(105, 105, 105));
			HGDIOBJ horg = SelectObject(hdc, hgreybrush);
			Ellipse(hdc, 500, 350, 550, 400);
			Ellipse(hdc, 450, 350, 500, 400);


			HBRUSH hgreenBrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hgreenBrush);
			Ellipse(hdc, 400, 350, 450, 400);

			//opprydding
			SelectObject(hdc, horg);
			DeleteObject(hgreybrush);
			DeleteObject(hgreenBrush);}
		break;
		case 4:
		{

			HBRUSH hgreybrush = CreateSolidBrush(RGB(105, 105, 105));
			HGDIOBJ horg = SelectObject(hdc, hgreybrush);


			Ellipse(hdc, 400, 350, 450, 400);
			Ellipse(hdc, 500, 350, 550, 400);

			HBRUSH hyellowbrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hyellowbrush);
			Ellipse(hdc, 450, 350, 500, 400);
			SelectObject(hdc, horg);
			DeleteObject(hyellowbrush);
			DeleteObject(hgreybrush);
		}
		}







		//trafikklys 1
		switch (state) {
		case 1:
		{
			// HBRUSH hwhiteBrush = CreateSolidBrush(RGB());
			 //venstre top høgre bunn



			HBRUSH hredbrush = CreateSolidBrush(RGB(255, 0, 0));
			HGDIOBJ horg = SelectObject(hdc, hredbrush);
			Ellipse(hdc, 550, 150, 500, 100);

			HBRUSH hgreybrush = CreateSolidBrush(RGB(105, 105, 105));
			SelectObject(hdc, hgreybrush);
			Ellipse(hdc, 550, 200, 500, 150);
			Ellipse(hdc, 550, 250, 500, 200);

			//opprydding
			SelectObject(hdc, horg);
			DeleteObject(hredbrush);
			DeleteObject(hgreybrush);}
		break;

		case 2:
		{




			HBRUSH hredbrush = CreateSolidBrush(RGB(255, 0, 0));
			HGDIOBJ horg = SelectObject(hdc, hredbrush);
			Ellipse(hdc, 550, 150, 500, 100);


			HBRUSH hyellowbrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hyellowbrush);
			Ellipse(hdc, 550, 200, 500, 150);


			HBRUSH hgreybrush = CreateSolidBrush(RGB(105, 105, 105));
			SelectObject(hdc, hgreybrush);
			Ellipse(hdc, 550, 250, 500, 200);

			//opprydding
			SelectObject(hdc, horg);
			DeleteObject(hredbrush);
			DeleteObject(hyellowbrush);
			DeleteObject(hgreybrush);
		}
		break;


		case 3:
		{



			HBRUSH hgreybrush = CreateSolidBrush(RGB(105, 105, 105));
			HGDIOBJ horg = SelectObject(hdc, hgreybrush);
			Ellipse(hdc, 550, 150, 500, 100);
			Ellipse(hdc, 550, 200, 500, 150);


			HBRUSH hgreenBrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hgreenBrush);
			Ellipse(hdc, 550, 250, 500, 200);

			//opprydding
			SelectObject(hdc, horg);
			DeleteObject(hgreybrush);
			DeleteObject(hgreenBrush);}
		break;
		case 4:
		{



			HBRUSH hgreybrush = CreateSolidBrush(RGB(105, 105, 105));
			HGDIOBJ horg = SelectObject(hdc, hgreybrush);

			Ellipse(hdc, 550, 150, 500, 100);
			Ellipse(hdc, 550, 250, 500, 200);

			HBRUSH hyellowbrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hyellowbrush);
			Ellipse(hdc, 550, 200, 500, 150);

			SelectObject(hdc, horg);
			DeleteObject(hyellowbrush);
			DeleteObject(hgreybrush);
		}
		}

		HBRUSH pinkBrush = CreateSolidBrush(RGB(255, 192, 203));

		if (lagBiler) {
			for (int i = 0; i < 100; i++) {
				SelectObject(hdc, pinkBrush);
				Rectangle(hdc, 150 + i, 300, 210 + i, 320);
			}

			SelectObject(hdc, horg);
			DeleteObject(pinkBrush);




			EndPaint(hWnd, &ps);
		}
		break;
	}
       case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
	}
}



// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
