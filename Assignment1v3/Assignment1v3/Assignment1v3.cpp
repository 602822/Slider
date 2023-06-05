// Assignment1v3.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Assignment1v3.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
int pw;
int pn;
BOOL spawnbil = false;


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    MyDlg(HWND, UINT, WPARAM, LPARAM);


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
    LoadStringW(hInstance, IDC_ASSIGNMENT1V3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ASSIGNMENT1V3));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ASSIGNMENT1V3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ASSIGNMENT1V3);
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
// 
//
//

class Car {
public:
	int left = 0;
	int top = 0;
	int right = 0;
	int bottom = 0;

	Car(int left, int top, int right, int bottom) : left(left), top(top), right(right), bottom(bottom) {

	};

	Car() {

	}

};


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{


	static int state = 3;
	static int stateTL2 = 1;
	static int antalltid = 0;
	static int antalltid2 = 0;

	static BOOL lagBiler = false;
	static BOOL lagBiler2 = false;

	//	static int nyPosBil[9] = { 0,0,0,0,0,0,0,0,0 };
		// static int nyPos2Bil[9] = { 0,0,0,0,0,0,0,0,0 };

	/*
	static struct Car {
		int left, top, right, bottom;
	};
	*/



	static Car cars[100];


	static Car cars2[100];

	
	//std::vector<Car*> cars;

//	std::vector<Car*> cars2;




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

	case WM_KEYDOWN:
	{

		switch (wParam) {

		case VK_LEFT:
		{
			if (pw < 100) {
				pw += 10;
			}
		}
		break;

		case VK_RIGHT:
		{
			if (pw > 0) {
				pw -= 10;
			}
		}
		break;

		case VK_UP:
		{
			if (pn < 100) {
				pn += 10;
			}
		}
		break;

		case VK_DOWN:
		{
			if (pn > 0) {
				pn -= 10;
			}
		}
		break;

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
		//timer for trafikklys
		SetTimer(hWnd, 0, 3000, 0);

		//timer for å øke posisjonen til biler horisontalt
		SetTimer(hWnd, 1, 100, 0);

		//timer for å øke posisjonen biler vertikalt
		SetTimer(hWnd, 2, 100, 0);

		//legge til biler i ein vektor kvart sekund
		SetTimer(hWnd, 3, 1000, 0);
	
	

		DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, MyDlg);


		//Setter start pos til biler horisontalt
		for (int i = 0; i < 10; i++) {
			cars[i].left = 150;
			cars[i].top = 300;
			cars[i].right = 210;
			cars[i].bottom = 320;
		}

		//Setter start pos til biler vertikalt
		for (int i = 0; i < 10; i++) {
			cars2[i].left = 595;
			cars2[i].top = 495;
			cars2[i].right = 615;
			cars2[i].bottom = 555;
		}
		


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

		//TODO få bilene til å stoppe på rødt lys



		//540

		case 1:
		{

			//kjører bilene
			if (lagBiler) {
				for (int i = 0; i < 10; i++) {
					cars[i].left += 5;
					cars[i].right += 5;

					//Stopper bilene
					if (cars[i].right == 540 + (i * 80)) {
						if (state == 1 || state == 2) {
							cars[i].left -= 5;
							cars[i].right -= 5;

							//Bilene bak stopper når bilene forran stopper
							for (int i = 0; i < 10; i++) {
								if (cars[i + 1].right >= cars[i].right) {
									cars[i + 1].left -= 5;
									cars[i + 1].right -= 5;

								}
							}
						}
					}
				}
			}
			break;
		}







		// Øker posisjonene til bilene som går vertikalt


		//TODO få bilene til å stoppe på rødt lys

		case 2:
		{
			if (lagBiler2) {
				//Bilene kjører
				for (int i = 0; i < 10; i++) {
					cars2[i].top -= 5;
					cars2[i].bottom -= 5;

					//Bilene stopper
					if (cars2[i].top == 350 - (i * 80)) {
						if (stateTL2 == 1 || stateTL2 == 2) {
							cars2[i].top += 5;
							cars2[i].bottom += 5;

							//Bilene bak stopper vist bilene forran stopper

							for (int i = 0; i < 10; i++) {
								if (cars2[i + 1].top <= cars2[i].top) {
									cars2[i + 1].top += 5;
									cars2[i + 1].bottom += 5;
								}
							}
						}
					}
				}
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

		/*
		RECT rect;
		GetClientRect(hWnd, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;
		*/


		Rectangle(hdc, 500, 250, 600, 100); //trafikklys 1
		Rectangle(hdc, 400, 300, 550, 400); //trafikklys 2

		//	Rectangle(hdc, rect.right / 2 - 150, rect.bottom / 2 - 200, rect.right / 2 - 50, rect.bottom / 2 - 50);


		HBRUSH greyBrush = CreateSolidBrush(RGB(105, 105, 105));
		HGDIOBJ horg = SelectObject(hdc, greyBrush);


		Rectangle(hdc, 150, 350, 1050, 250);  //vei horisonal
		Rectangle(hdc, 550, 0, 650, 600);    // vei vertikal

		TCHAR buffer[100];
		_stprintf_s(buffer, _T("Probability cars west : %d %%"), pw);
		TextOut(hdc, 0, 0, buffer, _tcslen(buffer));



		TCHAR buffer2[100];
		_stprintf_s(buffer2, _T("Probability cars north : %d %%"), pn);
		TextOut(hdc, 0, 20, buffer2, _tcslen(buffer2));






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
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));


		//	srand(time(0));
			//int randomNumber = rand() % 100 + 1;



			// Lager Biler horisontalt

		
		if(lagBiler) {
		
			for (int i = 0; i < 10; i++) {
				//if (rand() % 100 <= pw) {
				SelectObject(hdc, pinkBrush);
				Rectangle(hdc, cars[i].left - (i * 80), cars[i].top, cars[i].right - (i * 80), cars[i].bottom);
				//}
			}

		}

		









		// Lager biler vertikalt
		if (lagBiler2) {
			for (int i = 0; i < 10; i++) {
				SelectObject(hdc, blueBrush);
				//if (rand() % 100 <= pn) {
					Rectangle(hdc, cars2[i].left, cars2[i].top + (i * 80), cars2[i].right, cars2[i].bottom + (i * 80));

				//}
			}

		}






			SelectObject(hdc, horg);
			DeleteObject(pinkBrush);
			DeleteObject(blueBrush);






			EndPaint(hWnd, &ps);
		}
		break;
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


INT_PTR CALLBACK MyDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:

	{
		HWND pwControl = GetDlgItem(hDlg, IDC_EDIT1);
		HWND pnControl = GetDlgItem(hDlg, IDC_EDIT2);

		SetWindowText(pwControl, L"Legg inn eit heiltal 1-100");
		SetWindowText(pnControl, L"Legg inn eit heiltal 1-100");

		return (INT_PTR)TRUE;

	}
	break;

	case WM_COMMAND:


		if (LOWORD(wParam) == IDOK) {

			BOOL isNumber = false;
			pw = GetDlgItemInt(hDlg, IDC_EDIT1, &isNumber, false);
			pn = GetDlgItemInt(hDlg, IDC_EDIT2, &isNumber, false);







			EndDialog(hDlg, LOWORD(wParam));

		}


		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

