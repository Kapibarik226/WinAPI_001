
#include <windows.h> 
#include "box.h"
void xPrint(int x, int y, const char *pChar)  ;           //  ���������� (������������ ���� ) ���������� ������� WinAPI  

//////////////////////////////////////////  ���������� ���������� 
HWND                  hWnd;             //  ����� ��������! ����  
HINSTANCE        hInstance; 			//  ��������� ���� ��������� 


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)   //  ������� ��������� ��������� ��...
{																				  //  ...OS Windows	
	switch(message)
	{
		case  WM_CREATE:   break;                          //  ��������� ����������� ��������� ��� �������������
	    case WM_DESTROY:   PostQuitMessage(0);             //  ��������� ����������� ��������� ��� ��_�������������
		 	 			   break;
							 		 	 		
		case WM_COMMAND:  switch(LOWORD(wParam))
	                    {
			              case 115:	xPrint(rand()%256,rand()%256, "Hello");
								    break;
								
						  case 110:  LinesG();
							         break;
							         
						  case 111:  LinesR();
							         break;	
							         
						  case 112:  LinesP();
							         break;	
							         
						  case 113:  LinesB();
							         break;	
									 
						  case 114:  LinesW();
							         break;			 		 		          
							         
					    } 
	 		
			
		
			
			
			 /*if (LOWORD(wParam) == 109)
		                   {
			                   xPrint(100,20, "Hello");
			
	                       }
	                       if (LOWORD(wParam) == 105)
	                       {
								
								xPrint(300,60, "SONY");
						   }
			*/
			                break;				 
							 	   
		        default:   return DefWindowProc(hWnd, message, wParam, lParam);   // ��������� OS ��������� ���������
	}
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpszCmd, int nCmdShow)
{
	
	WNDCLASS WndClass;             // ������ ������� ������� ���������	
			 WndClass.style         = CS_HREDRAW | CS_VREDRAW;
			 WndClass.lpfnWndProc   = WndProc;                                 //   ��� ������� �������
			 WndClass.cbClsExtra    = 0;
			 WndClass.cbWndExtra    = 0;
			 WndClass.hInstance     = hInstance = hInst;                       //   ���������� ����������
			 WndClass.hIcon		    = LoadIcon(hInstance, "MYICON");           //   ��������� ������
			 WndClass.hCursor       = LoadCursor(NULL, MAKEINTRESOURCE(230));             //   ��������� ��� ������� 
			 WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);      //   ���� ������� ���� �������
			 WndClass.lpszMenuName  = "xMENU";                                 //   ��������� ��� ���� 
			 WndClass.lpszClassName = "dllBridge";                             //   ��������� ���� ��� ������ ����  
                                                    // C������ ������������ ����� �������� ���� ���������  
	if(!RegisterClass(&WndClass)) return 0;         // ���� ����� �� ���������������, �� ������� 
	
	hWnd = CreateWindow("dllBridge",                // ����� ������� ���� ������ dllBridge �����
						"TIK-TAK",                  // ��������� ���� (������� �� �������-����� ������)
						WS_OVERLAPPEDWINDOW,        // ����� ����
						800,              // ���������� X ������ �������� ���� ���� 
						600,              // ���������� Y ������ �������� ���� ���� 
						250,                        // ������� ���� (������)
					    500,                        // ������
					      0,                        // ���������� ������������� ����  ( ��� �������� ���� ��������� :)
					      0,                        // ����������  ����  (��� ������������� ��������� ����)
					    hInstance,                  // ���������� ���������� ����������
					      0);                      
	if(hWnd == 0) return 0;							    //  ���� ���� �� �������, �� ������� (��������� �� �����������)
	ShowWindow(hWnd, nCmdShow);						//  ���������� ���� �� ������
	UpdateWindow(hWnd);								//  �������� ����       								  									   								   


               MSG      msg;                        //  ������ ������� ��������� ��������� �� OS Windows
	while(  GetMessage(&msg, 0, 0, 0))              //  ���� ��������� ���������	
	{ TranslateMessage(&msg);                       //  �������� � "�������������" ��������� � �������
	   DispatchMessage(&msg);
	} 
return msg.wParam;
}

	




























