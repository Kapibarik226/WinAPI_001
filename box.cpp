 #include <windows.h> 
 #include "box.h"  
 int       	           color[20] = { RGB(  0,   0,   0),     //  0 Чёрный цвет фона  
		                          		 RGB(255, 255, 255),     //  1 Белый  		                   		  
		                   		  		 RGB(248,  71,  71),     //  2 Красный 
						   		  		 RGB(  0, 255,   0),     //  3 Зелёный
						   		  		 RGB(  0, 128, 255),     //  4 Синий
						          		 RGB(233, 149,  22),     //  5 0x0000FFFF,     //  5 Yellow						             
						   		  		 RGB( 66, 170, 255),     //  6 Light_Blue	
						   		  		 RGB(180, 180, 180),     //  7 Серый 
						   	      		 RGB( 7,   55,  99),     //  8  Dark    RGB( 35, 102, 141), 
						   		  		 RGB( 75, 206,  50),	 //  9 Коричневый ШОКОЛАД
						   		  		 RGB( 43, 103, 136),	 // 10 серо-голубой
						   		  		 RGB( 62,  41,  77),     // 11 Выцветший коричневый	;
						   		         RGB(143,  32, 147),     // 12 фиолетовый	
								         RGB( 66,  66, 176),     // 13 бледно-фиолетовый 	
										 RGB(196, 250,  31)      // 14 Жёлто-зелёный 	
							           };  
								  							  
						            
   HPEN              hPen[20] = { CreatePen(0, 1, color[ 0]),     //  Перо такого же цвета, как фон  (Black) 
                                  CreatePen(0, 1, color[ 1]),     //  White        
								  CreatePen(0, 1, color[ 2]),     //  RED
								  CreatePen(0, 1, color[ 3]),     //  Green
								  CreatePen(0, 1, color[ 4]),     //  Blue
								  CreatePen(0, 1, color[ 5]),     //  Yellow
								  CreatePen(0, 1, color[ 6]),     //  Light_Blue	
								  CreatePen(0, 1, color[ 7]),     //  Серый 
								  CreatePen(0, 1, color[ 8]),     //  Dark     
								  CreatePen(0, 1, color[ 9]),     //  9 Коричневый ШОКОЛАД
								  CreatePen(0, 1, color[10]),     //  10 серо-голубой  
								  CreatePen(0, 1, color[11]),     //  11 Выцветший коричневый	;
								  CreatePen(0, 1, color[12]),     //  12 фиолетовый	
								  CreatePen(0, 1, color[13]),     //  13 бледно-фиолетовый 
								  CreatePen(0, 1, color[14])      //  14 Жёлто-зелёный 
								};  
								
					
   HBRUSH             hBr[20] = { CreateSolidBrush(color[0]),    //  Создадим кисть такого же цвета, как фон  (Black)    
                                  CreateSolidBrush(color[1]),
                                  CreateSolidBrush(color[2]),
                                  CreateSolidBrush(color[3]),
                                  CreateSolidBrush(color[4]),
                                  CreateSolidBrush(color[5]),
                                  CreateSolidBrush(color[6]),
                                  CreateSolidBrush(color[7]),
                                  CreateSolidBrush(color[8])  		
								}; 					
								
				
   HFONT           hFont[20] =  {  (HFONT)GetStockObject(10),                                 // №0     OEM_FIXED_FONT
		                           (HFONT)GetStockObject(11),                                 // №1    ANSI_FIXED_FONT
		                           (HFONT)GetStockObject(12), 							      // №2      ANSI_VAR_FONT
		                           (HFONT)GetStockObject(13),                                 // №3        SYSTEM_FONT
		                           (HFONT)GetStockObject(16),                                 // №4  SYSTEM_FIXED_FONT
		                           (HFONT)GetStockObject(17),  				                  // №5   DEFAULT_GUI_FONT
		                           
		 CreateFont(13, 8, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET,
	 OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
	       FW_BOLD | FF_DONTCARE | DEFAULT_PITCH, "Courier"),                                 // №6            Сourier
	                               
		 CreateFont(18, 8, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 
	 OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, 
	 FW_BOLD | FF_DONTCARE | DEFAULT_PITCH, "Comic Sans MS"),                                 // №7
	               
         CreateFont(18, 8, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 
	 OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, 
	         FW_BOLD | FF_DONTCARE | DEFAULT_PITCH, "Tahoma") };
	         
	void  LinesG()                              //зеленый                                             //
	{
		  HDC       hdc;
		  int x1 = rand()%256,
		      y1 = rand()%256;
		  
		  int x2 = rand()%600,
		  	  y2 = rand()%400,					
		      t  = rand()%7 + 1;			  	
			
	      //MoveToEx(memdc, x1, y1, 0);
		  hdc = GetDC(hWnd);
		  hPen[9] = CreatePen(0, t, color[3] ); 
						                     
		  SelectObject(hdc, hPen[9]);
		  LineTo(hdc, x2, y2);

		 // InvalidateRect(hWnd, 0, 1);
		  ReleaseDC(hWnd,hdc);		
	}
	//////////////////////////////////////
	void  LinesR()               //красный                                                    //
	{
		  HDC       hdc;
		  int x1 = rand()%256,
		      y1 = rand()%256;
		  
		  int x2 = rand()%600,
		  	  y2 = rand()%400,					
		      t  = rand()%7 + 1;			  	
			
	      //MoveToEx(memdc, x1, y1, 0);
		  hdc = GetDC(hWnd);
		  hPen[9] = CreatePen(0, t, color[2] ); 
						                     
		  SelectObject(hdc, hPen[9]);
		  LineTo(hdc, x2, y2);

		 // InvalidateRect(hWnd, 0, 1);
		  ReleaseDC(hWnd,hdc);		
	}
	//////////////////////////////////////////
	void  LinesB()                    //синий                                  
	{
		  HDC       hdc;
		  int x1 = rand()%256,
		      y1 = rand()%256;
		  
		  int x2 = rand()%600,
		  	  y2 = rand()%400,					
		      t  = rand()%7 + 1;			  	
			
	      //MoveToEx(memdc, x1, y1, 0);
		  hdc = GetDC(hWnd);
		  hPen[9] = CreatePen(0, t, color[4] ); 
						                     
		  SelectObject(hdc, hPen[9]);
		  LineTo(hdc, x2, y2);

		 // InvalidateRect(hWnd, 0, 1);
		  ReleaseDC(hWnd,hdc);		
	}
	//////////////////////////////////////////
	void  LinesW()                                                        //белый
	{
		  HDC       hdc;
		  int x1 = rand()%256,
		      y1 = rand()%256;
		  
		  int x2 = rand()%600,
		  	  y2 = rand()%400,					
		      t  = rand()%7 + 1;			  	
			
	      //MoveToEx(memdc, x1, y1, 0);
		  hdc = GetDC(hWnd);
		  hPen[9] = CreatePen(0, t, color[1] ); 
						                     
		  SelectObject(hdc, hPen[9]);
		  LineTo(hdc, x2, y2);

		 // InvalidateRect(hWnd, 0, 1);
		  ReleaseDC(hWnd,hdc);		
	}
	////////////////////////////////////////
	void  LinesP()                                                        //фиолетовый
	{
		  HDC       hdc;
		  int x1 = rand()%256,
		      y1 = rand()%256;
		  
		  int x2 = rand()%600,
		  	  y2 = rand()%400,					
		      t  = rand()%7 + 1;			  	
			
	      //MoveToEx(memdc, x1, y1, 0);
		  hdc = GetDC(hWnd);
		  hPen[9] = CreatePen(0, t, color[12] ); 
						                     
		  SelectObject(hdc, hPen[9]);
		  LineTo(hdc, x2, y2);

		 // InvalidateRect(hWnd, 0, 1);
		  ReleaseDC(hWnd,hdc);		
	}
	
/////////////////////////////////////////////////	
void xPrint(int x, int y, const char *pChar)
	{
		
		 HDC       hdc;
		// y  += ToolBar;                                            //  Поправка по вертикали (учитываем высоту ToolBar)
	     hdc = GetDC(hWnd);
		 //SetTextColor(hdc, RGB( 186, 137,  95)); 
		 SetTextColor(hdc, color[12]);
		 SetBkColor  (hdc, color[0]); 
		// (HFONT)SelectObject(hdc, hFont[9]);	
		 TextOut(hdc, x, y, pChar, strlen(pChar));
		 ReleaseDC(hWnd,hdc);
	}
	
	
	
	
